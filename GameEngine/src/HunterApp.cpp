#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"

namespace Hunter{
	void Hunter::HunterApp::RunGame()
	{
		HLOG("Starting the game");		

		Renderer::Init();

		//Sprite cat{"../GameEngine/assets/sprites/cat.png"};
		Sprite boss{"../GameEngine/assets/sprites/boss.png"};
		while (true) {
			//Renderer::Draw(cat,100,100,cat.getWidth(), cat.getHeight());
			Renderer::Draw(boss,400,400,boss.getWidth(), boss.getHeight());
			appWindow->SwapBuffers();
			appWindow->PollForEvents();
		}

	}

	HunterApp* Hunter::HunterApp::GetApplication()
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

		appWindow = new WindowsWindow;
		bool success{ appWindow->CreateWindow(800,600) };
		assert(success);
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
}
