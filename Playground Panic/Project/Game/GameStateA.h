#pragma once

#include "stdafx.h"
#include "State.h"


class Collider;
class CountdownTimer;
class PlayerObject;
class ProjectileObject;
class SlowKid;


class GameStateA : public State {
public:
	GameStateA();

	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view);
	std::string Next();
	bool IsType(const std::string &type);

private:
	Collider* Collisions;
	
	
	sf::Vector2f m_mouse_position;

	sf::Sprite m_background_sprite;
	sf::Texture m_background_texture;

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

	sf::Sprite *m_crosshair_sprite;
	sf::Texture m_crosshair_texture;

	sf::Sprite *m_healthbar_sprite;
	sf::Texture m_healthbar_texture;

	CountdownTimer* m_levelup_timer;

	sf::Sprite *m_heatbar_sprite;
	sf::Texture m_heatbar_texture;

	sf::Sprite m_frameheatbar_sprite;
	sf::Texture m_frameheatbar_texture;


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

	
	//sf::Time deltaTime;
	
	int m_enemies_to_spawn;
};

