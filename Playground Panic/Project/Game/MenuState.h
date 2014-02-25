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

class MenuState : public State {
public:
	MenuState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view);
	void Initialize();
	//void Draw(DrawManager* m_draw_manager);
	std::string Next();
	bool IsType(const std::string &type);

	bool m_changetoGameState;
	bool m_changetoOptionsState;
	
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

	sf::Sprite m_background_sprite;
	sf::Texture m_background_texture;

	sf::Sprite m_start_game_sprite;
	sf::Texture m_start_game_texture;

	sf::Sprite m_options_sprite;
	sf::Texture m_options_texture;

	sf::Sprite m_exit_game_sprite;
	sf::Texture m_exit_game_texture;
};

