#pragma once
#include "StateManager.h"
#include "GameStateA.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "stdafx.h"
#include "CountdownTimer.h"

class HealthBar;
class PlayerObject;
class Collider;
class ProjectileObject;
class SlowKid;

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	Collider* Collisions;
	sf::RenderWindow m_window;
	//StateManager * mgr;
	CountdownTimer* m_timer;
	PlayerObject * m_player;
	Collider * m_player_collider;
	sf::Sprite *m_player_sprite;
	sf::Texture m_player_texture;

	std::vector<ProjectileObject*> m_projectile;
	std::vector<sf::Sprite*> m_projectile_sprite;
	sf::Texture m_projectile_texture;
	std::vector<Collider*> m_projectile_collider;

	std::vector<SlowKid*> m_slow_kid;
	std::vector<sf::Sprite*> m_slow_kid_sprite;
	sf::Texture m_slow_kid_texture;
	std::vector<Collider*> m_slow_kid_collider;

	sf::Sprite m_framehealthbar_sprite;
	sf::Texture m_framehealthbar_texture;

	sf::Sprite *m_healthbar_sprite;
	sf::Texture m_healthbar_texture;

	float m_healthbar;

	sf::Clock m_player_pst;
	//Time between projectile-spawns
	sf::Int32 m_player_pss;

	sf::Clock m_health_pst;
	//Time between projectile-spawns
	sf::Int32 m_health_pss;

	//Temporary
	sf::RectangleShape * rec;
	
	float m_global_speed;

	float m_deltatime;
	sf::Clock deltaClock;
	//sf::Time deltaTime;

};