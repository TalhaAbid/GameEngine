#pragma once
#include "HunterCentral.h"
#include "Window.h"
#include "WindowsWindow.h"
#include "KeyboardEvents.h"
namespace Hunter 
{
	class HUNTER_API HunterApp
	{
	public:
		void RunGame();
		static HunterApp* GetApplication();
		static void Init();
		virtual ~HunterApp();
		static int GetWindowHeight();
		static int GetWindowWidth();

		void onKeyPressed(KeyPressedEvent& event);
	private:
		HunterApp();
		inline static HunterApp* instance{ nullptr };
		Window* appWindow{nullptr};
	};
}
