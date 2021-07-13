#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"
#include "HunterKeys.h"

namespace Hunter{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game");		

		Renderer::Init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) {

			Renderer::ClearFrame();
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			appWindow->SwapBuffers();
			appWindow->PollForEvents();

			mNextFrameTime += mFrameDuration;
		}

	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}
	HunterApp::HunterApp() {
		assert(instance == nullptr);
		instance = this;
	#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
	#else
	#Only_Windows_Supported_for_now
	#endif 
		bool success{ appWindow->CreateWindow(800,600) };
		assert(success);

		appWindow->setKeyPressedCallback([this](KeyPressedEvent& event) {onKeyPressed(event); });
		appWindow->setKeyReleasedCallback([this](KeyReleasedEvent& event) {onKeyReleased(event); });
	}
	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
	}
	void HunterApp::OnUpdate()
	{
	}
	int HunterApp::GetWindowHeight()
	{
		return instance->appWindow->GetWidth();
	}
	int HunterApp::GetWindowWidth()
	{
		return instance->appWindow->GetHeight();
	}
	void HunterApp::onKeyPressed(KeyPressedEvent& event)
	{
		HLOG(event.GetKeyCode());
	}
	void HunterApp::onKeyReleased(KeyReleasedEvent& event)
	{
	}
}
