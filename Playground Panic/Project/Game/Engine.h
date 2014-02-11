#pragma once
#include "StateManager.h"
#include "GameStateA.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "stdafx.h"

class PlayerObject;

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	sf::RenderWindow m_window;

	PlayerObject * m_player;

	//Temporary
	sf::RectangleShape * rec;
	sf::Sprite m_player_sprite;
	sf::Texture m_player_texture;

	float m_global_speed;

	float m_deltatime;
	sf::Clock deltaClock;
	sf::Time deltaTime;

};