#pragma once
#include "GameEngine.h"
#include "Unit.h"
#include <deque>
class GameApp : public Hunter::HunterApp 
{
public:
	GameApp();

	virtual void OnUpdate() override;

	virtual void onKeyPressed(Hunter::KeyPressedEvent& event);
	virtual void onKeyReleased(Hunter::KeyReleasedEvent& event);
private:
	Unit mSpaceship;
	std::deque<Unit> mAsteroids;
	enum class Action {
		LeftMove,
		RightMove,
		Forward,
		Up,
		Down
	} mSpaceshipAction;

	std::vector<std::string> listAstd = {
		"assets/small/a10000.png",
		"assets/small/a30005.png",
		"assets/small/a40009.png",
		"assets/medium/a10000.png",
		"assets/medium/a30005.png",
		"assets/medium/a40009.png",
	};

	bool gameOver;
	Hunter::Sprite mBackground;
	long long mFrameNumber;
};
