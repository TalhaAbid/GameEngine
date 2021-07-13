#include  <pch.h>
#include  "WindowsWindow.h"

namespace Hunter {
	bool WindowsWindow::CreateWindow(unsigned int width, unsigned int height)
	{
		glfwInit();
		window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);
		if (window == nullptr) {
			return false;
		}
		glfwGetWindowSize(window,&this->width,&this->height);
		glfwMakeContextCurrent(window);
		gladLoadGL();

		glfwSwapInterval(1);

		glfwSetWindowUserPointer(window, &mCallbacks);

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS || action == GLFW_REPEAT) {
				KeyPressedEvent event{ key };
				Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);
				callbacks->mKeyPressedCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				KeyReleasedEvent event{ key };
				Callbacks* callbacks = (Callbacks*)glfwGetWindowUserPointer(window);
				callbacks->mKeyReleasedCallback(event);
			}
			});
		return true;
	}
	void WindowsWindow::DeleteWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void WindowsWindow::SwapBuffers()
	{
		glfwSwapBuffers(window);
	}
	void WindowsWindow::PollForEvents()
	{
		glfwPollEvents();
	}
	int WindowsWindow::GetWidth() const
	{
		return width;
	}
	int WindowsWindow::GetHeight() const
	{
		return height;
	}
	void WindowsWindow::setKeyPressedCallback(std::function<void(KeyPressedEvent&)> newCallback)
	{
		mCallbacks.mKeyPressedCallback = newCallback;
	}
	void WindowsWindow::setKeyReleasedCallback(std::function<void(KeyReleasedEvent&)> newCallback)
	{
		mCallbacks.mKeyReleasedCallback = newCallback;
	}
}