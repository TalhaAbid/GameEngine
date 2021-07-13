#include "..\include\Unit.h"
#include "GameEngine.h"

Unit::Unit(const std::string& spritePath, int newSpeed) :mImage(spritePath), mSpeed(newSpeed)
{
}

void Unit::setXCoord(int newX)
{
	mXcoord = newX;
}

void Unit::setYCoord(int newY)
{
	mYcoord = newY;
}

int Unit::getXCoord() const
{
	return mXcoord;
}

int Unit::getYCoord() const
{
	return mYcoord;
}

void Unit::UpdateXCoord(int change)
{
	mXcoord += change;
}

void Unit::UpdateYCoord(int change)
{
	mYcoord += change;
}

int Unit::getSpeed() const
{
	return mSpeed;
}

void Unit::Draw() const
{
	Hunter::Renderer::Draw(mImage, mXcoord, mYcoord, mImage.getWidth(), mImage.getHeight());
}

bool Unit::OverlapsWith(const Unit& other) const
{
	if ((mXcoord <= other.mXcoord && other.mXcoord <= mXcoord + GetWidth()) ||
		(mXcoord <= other.mXcoord + other.GetWidth() && other.mXcoord + other.GetWidth() <= mXcoord + GetWidth()))
	{
if ((mYcoord <= other.mYcoord && other.mYcoord <= mYcoord + GetHeight()) ||
		(mYcoord <= other.mYcoord + other.GetHeight() && other.mYcoord + other.GetHeight() <= mYcoord + GetHeight()))
	{ 
	return true;

	}
}

	return false;
}

int Unit::GetHeight() const
{
	return mImage.getHeight();
}

int Unit::GetWidth() const
{
	return mImage.getWidth();
}
