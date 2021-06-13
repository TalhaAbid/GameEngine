#include <pch.h>
#include "HunterApp.h"

namespace Hunter{
	void Hunter::HunterApp::RunGame()
	{
		HLOG("Starting the game");		
		while (true) {
		}

	}

	HunterApp* Hunter::HunterApp::GetApplication()
	{
		return instance;
	}
	void HunterApp::Init()
	{
		if (instance != nullptr) {
			instance = new HunterApp;
		}
	}
	HunterApp::HunterApp() {
		assert(instance == nullptr);
	}
}
