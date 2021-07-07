#pragma once
#include "HunterCentral.h"
#include "Window.h"
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
	private:
		HunterApp();
		inline static HunterApp* instance{ nullptr };
		Hunter::Window* appWindow{nullptr};
	};
}
