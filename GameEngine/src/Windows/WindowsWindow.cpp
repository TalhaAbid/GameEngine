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
			KeyPressedEvent event{ key };
			Callbacks*  callbacks =  (Callbacks*)glfwGetWindowUserPointer(window);
			callbacks->mKeyPressedCallback(event);
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
}