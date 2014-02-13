#pragma once
#include "StateManager.h"
#include "GameStateA.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "stdafx.h"

class PlayerObject;
class Collider;
class ProjectileObject;

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	sf::RenderWindow m_window;
	//StateManager * mgr;

	PlayerObject * m_player;
	Collider * m_player_collider;
	sf::Sprite m_player_sprite;
	sf::Texture m_player_texture;

	std::vector<ProjectileObject*> m_projectile;
	std::vector<sf::Sprite*> m_projectile_sprite;
	sf::Texture m_projectile_texture;
	std::vector<Collider*> m_projectile_collider;
	sf::Clock m_player_pst;
	//Time between projectile-spawns
	sf::Int32 m_player_pss;

	//Temporary
	sf::RectangleShape * rec;
	
	float m_global_speed;

	float m_deltatime;
	sf::Clock deltaClock;
	//sf::Time deltaTime;

};