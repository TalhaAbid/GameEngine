#include <pch.h>
#include "HunterApp.h"
#include "WindowsWindow.h"

namespace Hunter{
	void Hunter::HunterApp::RunGame()
	{
		HLOG("Starting the game");		
		while (true) {
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
}
