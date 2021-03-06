#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Window.h"
#include <KeyboardEvents.h>
namespace Hunter 
{
	class HUNTER_API WindowsWindow final: public Hunter::Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBuffers() override;
		virtual void PollForEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void setKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback) override;
		virtual void setKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback) override;
	private:
		struct Callbacks {
			std::function<void(KeyPressedEvent&)> mKeyPressedCallback;
			std::function<void(KeyReleasedEvent&)> mKeyReleasedCallback;
		} mCallbacks;
		GLFWwindow* window;
		int width{ 0 };
		int height{ 0 };
	};

}
