#pragma once

#include "Sprite.h"
#include "RendererImplementation.h"
#include "OpenGL/OpenGLImplementation.h"

namespace Hunter {
	class HUNTER_API Renderer 
	{
	public:
		static void Init();
		static void ShutDown();
		static void Draw(const Sprite& image, int x_pos, int y_pos, int width, int height);
		static void ClearFrame();

	private:
		Renderer();
		inline static Renderer* instance{nullptr};
		RendererImplementation* mDrawingEngine{ nullptr };
	};
}
