#pragma once
#include "HunterCentral.h"
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
	};
}
