#include "pch.h"
#include "Sprite.h"
#include "stb_image.h"

namespace Hunter {
	Sprite::Sprite(const std::string& spriteFile)
	{
		stbi_set_flip_vertically_on_load(true);
		if (!Load(spriteFile)) {
			HLOG("ERROR LOADING SPRITE");
		}
	}
	bool Sprite::Load(const std::string& spriteFile)
	{
		mImg = stbi_load(spriteFile.c_str(), &mWidth, &mHeight, &mNumChannels,0);
		if (mImg) {
			return true;
		}
		else {
			return false;
		}
		return false;
	}
	int Sprite::getWidth() const
	{
		return mWidth;
	}
	int Sprite::getHeight() const
	{
		return mHeight;
	}
	const unsigned char* Sprite::GetImagePointer() const
	{
		return mImg;
	}
	Sprite::~Sprite()
	{
		stbi_image_free(mImg);
	}
}