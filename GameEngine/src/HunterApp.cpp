#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"

namespace Hunter{
	void HunterApp::RunGame()
	{
		HLOG("Starting the game");		

		Renderer::Init();

		//Sprite cat{"../GameEngine/assets/sprites/cat.png"};
		Sprite boss{"../GameEngine/assets/sprites/boss.png"};
		Sprite smiley{"../GameEngine/assets/sprites/smiley.png"};
		while (true) {
			//Renderer::Draw(cat,100,100,cat.getWidth(), cat.getHeight());
			Renderer::Draw(smiley,100,100,smiley.getWidth(), smiley.getHeight());
			Renderer::Draw(boss,100,100,boss.getWidth(), boss.getHeight());
			appWindow->SwapBuffers();
			appWindow->PollForEvents();
		}

	}

	HunterApp* HunterApp::GetApplication()
	{
		return instance;
	}
	void HunterApp::Init()
	{
		if (instance == nullptr) {
			instance = new HunterApp;
		}
	}
	HunterApp::HunterApp() {
		assert(instance == nullptr);
	#ifdef _HUNTER_WINDOWS
		appWindow = new WindowsWindow;
	#else
	#Only_Windows_Supported_for_now
	#endif 
		bool success{ appWindow->CreateWindow(800,600) };
		assert(success);

		appWindow->setKeyPressedCallback([this](KeyPressedEvent& event) {onKeyPressed(event); });
	}
	HunterApp::~HunterApp()
	{
		appWindow->DeleteWindow();
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
}
