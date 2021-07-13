#pragma once
#include "GameEngine.h"

class Unit 
{
public:
	Unit(const std::string &spritePath, int newSpeed);

	void setXCoord(int newX);
	void setYCoord(int newY);
	int getXCoord() const;
	int getYCoord() const;
	void UpdateXCoord(int change);
	void UpdateYCoord(int change);
	int getSpeed() const;

	void Draw() const;
	
	bool OverlapsWith(const Unit& other) const;
	
	int GetHeight() const;
	int GetWidth() const;

	Unit(const Unit&) = delete;
	Unit(Unit&&) = delete;
	Unit& operator=(const Unit&) = delete;
	Unit& operator=(Unit&&) = delete;
private:
	Hunter::Sprite mImage;
	int mXcoord;
	int mYcoord;
	int mSpeed;

};
