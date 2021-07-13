#pragma once
#include "pch.h"
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

		virtual ~HunterApp();
		virtual void OnUpdate();

		static int GetWindowHeight();
		static int GetWindowWidth();

		virtual void onKeyPressed(KeyPressedEvent& event);
		virtual void onKeyReleased(KeyReleasedEvent& event);
	protected:
		HunterApp();
	private:
		inline static HunterApp* instance{ nullptr };
		Window* appWindow{nullptr};

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ 16 };
	};
}
