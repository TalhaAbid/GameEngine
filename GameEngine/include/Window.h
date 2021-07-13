#pragma once
#include "pch.h"
#include "HunterCentral.h"
#include "KeyboardEvents.h"
namespace Hunter{
	class Window
	{

	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) = 0;
		virtual void DeleteWindow() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollForEvents() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void setKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) = 0;
		virtual void setKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) = 0;
	};
}
