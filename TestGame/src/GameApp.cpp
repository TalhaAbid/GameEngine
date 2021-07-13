#include "..\include\GameApp.h"
#include <cmath>

GameApp::GameApp() : mSpaceship("assets/spaceship.png", 5), mSpaceshipAction(Action::Forward), mFrameNumber(0), gameOver(false), mBackground("assets/back.png")
{
}

void GameApp::OnUpdate()
{

	Hunter::Renderer::Draw(mBackground, 0, 0, mBackground.getWidth(),mBackground.getHeight());

	if (gameOver)
	{
		Hunter::Sprite endScreen("assets/game-over.png");
		Hunter::Renderer::Draw(endScreen, GameApp::GetWindowWidth() - endScreen.getWidth() + 100, GameApp::GetWindowHeight() - endScreen.getHeight(), endScreen.getWidth(), endScreen.getHeight());
		return;
	}
	if (mFrameNumber % 15 == 0) {
		int ind = (rand() % listAstd.size());
		std::string astd = listAstd[ind];
		mAsteroids.emplace_back(astd,5);
		mAsteroids.back().setYCoord(GameApp::GetWindowHeight());
		mAsteroids.back().setXCoord(rand()%(GameApp::GetWindowWidth() - mAsteroids.back().GetWidth()));
	}
	if (mSpaceshipAction == Action::LeftMove) {
		if (mSpaceship.getXCoord() >= mSpaceship.getSpeed())
			mSpaceship.UpdateXCoord(-mSpaceship.getSpeed());
		else
			mSpaceship.setXCoord(0);
	}else if (mSpaceshipAction == Action::RightMove) {
		if (mSpaceship.getXCoord() + mSpaceship.getSpeed() + mSpaceship.GetWidth() < GameApp::GetWindowWidth())
		{
			HLOG('test')
			mSpaceship.UpdateXCoord(mSpaceship.getSpeed());
		}
		else
			mSpaceship.setXCoord(GameApp::GetWindowWidth() - mSpaceship.GetWidth());
	}
	else if (mSpaceshipAction == Action::Up) {
		if (mSpaceship.getYCoord() + mSpaceship.getSpeed() + mSpaceship.GetHeight() < GameApp::GetWindowHeight()) {
			mSpaceship.UpdateYCoord(mSpaceship.getSpeed());
		}
		else {
			mSpaceship.setYCoord(GameApp::GetWindowHeight());
		}
	}
	else if (mSpaceshipAction == Action::Down) {
		if (mSpaceship.getYCoord() - mSpaceship.GetWidth() - mSpaceship.getSpeed() >= 0) {
			mSpaceship.UpdateYCoord(-mSpaceship.getSpeed());
		}
		else {
			mSpaceship.setYCoord(0);
		}
	}
	while (mAsteroids.empty() == false && mAsteroids.front().getYCoord() <= -mAsteroids.front().GetHeight()) {
		mAsteroids.pop_front();
	}
	for (auto& astd : mAsteroids) {
		astd.UpdateYCoord(-astd.getSpeed());
		if (astd.OverlapsWith(mSpaceship)) {
			gameOver = true;
		}
	}
	for (const auto& astd : mAsteroids) {
			astd.Draw();
	}
	mSpaceship.Draw();
	mFrameNumber++;

}

void GameApp::onKeyPressed(Hunter::KeyPressedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT) {
		mSpaceshipAction = Action::LeftMove;

	}
	else if (event.GetKeyCode() == HUNTER_KEY_RIGHT) {
		mSpaceshipAction = Action::RightMove;
	}
	else if (event.GetKeyCode() == HUNTER_KEY_UP) {
		mSpaceshipAction = Action::Up;
	} 
	else if (event.GetKeyCode() == HUNTER_KEY_SPACE && gameOver == true) {
		mAsteroids.clear();
		gameOver = false;
		mSpaceship.setXCoord(GameApp::GetWindowWidth() / 2);
		mSpaceship.setYCoord(0);
	}
	else if (event.GetKeyCode() == HUNTER_KEY_DOWN) {
		mSpaceshipAction = Action::Down;
	}
	else {
		std::cout << "test" << std::endl;
	}
}

void GameApp::onKeyReleased(Hunter::KeyReleasedEvent& event)
{
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT || event.GetKeyCode() == HUNTER_KEY_DOWN || event.GetKeyCode() == HUNTER_KEY_UP) {
		mSpaceshipAction = Action::Forward;
	}
}
