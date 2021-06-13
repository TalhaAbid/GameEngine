#pragma once

#include <HunterApp.h>
#include <HunterCentral.h>

#define START_GAME(classname)\
	int main()\
	{\
	classname::Init();\
	classname::GetApplication()->RunGame();\
	}
