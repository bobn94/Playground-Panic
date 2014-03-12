#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "State.h"


class SpriteManager;
class Sprite;
class DrawManager;
class GameObject;

class OptionsState : public State {
public:
	OptionsState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level);
	void Initialize();
	void Draw(DrawManager* m_draw_manager);
	std::string Next();
	bool IsType(const std::string &type);

	bool m_resetHighScore;
	bool m_changetoGameState;

	void SpawnMenuCrosshair(SpriteManager *sprite_manager);
	bool CheckCrosshairCollision(sf::Vector2u &offset, SpriteManager* sprite_manager);

	void ResetHighscore();

	bool isOn;

private:

	sf::Vector2u m_crosshairPos;
	Sprite* m_BackgroundSprite;
	//std::vector<GameObject*> m_objects;

	//GameObject *m_resethighscoretext;
	//GameObject *m_gametext;

	bool m_GoGamestate;
	bool m_resetit;

	bool m_done;
	std::string m_next_state;
};

