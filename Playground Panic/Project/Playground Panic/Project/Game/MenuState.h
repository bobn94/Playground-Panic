#pragma once

#include <string>
#include <vector>
#include "stdafx.h"
#include <map>
//#include <SDL_ttf.h>
//#include "Vector2.h"
#include "State.h"
//#include "SpriteManager.h"
//#include "DrawManager.h"

class SpriteManager;
class Sprite;
class DrawManager;
class GameObject;

class MenuState : public State {
public:
	MenuState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime);
	void Initialize();
	//void Draw(DrawManager* m_draw_manager);
	std::string Next();
	bool IsType(const std::string &type);

	bool m_changetoGameState;
	bool m_changetoOptionsState;

	void SpawnMenuCrosshair(SpriteManager *sprite_manager);
	bool CheckCrosshairCollision(sf::Vector2u &offset, SpriteManager* sprite_manager);

private:


	sf::Vector2u m_crosshairPos;
	Sprite* m_BackgroundSprite;
	std::vector<GameObject*> m_objects;

	GameObject *m_startgametext;
	GameObject *m_optionstext;

	bool m_GoGamestate;
	bool m_GoOptionsstate;

	bool m_done;
	std::string m_next_state;
};

