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
}