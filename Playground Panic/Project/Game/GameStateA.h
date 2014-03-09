#pragma once

#include "stdafx.h"
#include "State.h"


class Collider;
class CountdownTimer;
class PlayerObject;
class ProjectileObject;
class SlowKid;
class BikeKid;
class Enemy;
class SpriteObject;
class ParentUI;
class Arrow;
class Indicator;
class ParentBall;


class GameStateA : public State {
public:
	GameStateA();

	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view);
	std::string Next();
	bool IsType(const std::string &type);

private:
	Collider* Collisions; //Do we ever use this? I'll probably check later
	sf::Vector2f m_mouse_position;

	SpriteObject* m_background;
	sf::Texture m_background_texture;

	//StateManager * mgr;
	CountdownTimer* m_timer;
	PlayerObject * m_player;
	Collider * m_player_collider;
	sf::Texture m_player_texture;

	std::vector<ProjectileObject*> m_projectile;
	sf::Texture m_projectile_texture;
	std::vector<Collider*> m_projectile_collider;

	std::vector<Enemy*> m_enemies;
	
	sf::Texture m_player_dirt_texture;
	sf::Texture m_slow_kid_dirt_texture;
	sf::Texture m_bike_kid_dirt_texture;

	std::vector<SlowKid*> m_slow_kid;
	sf::Texture m_slow_kid_texture;
	std::vector<Collider*> m_slow_kid_collider;

	std::vector<ParentUI*> m_parentUI;
	std::map<ParentUI*, SlowKid*>mm_special_kid;
	sf::Texture m_parent_ball_texture;
	sf::Texture m_arrow_texture;
	sf::Texture m_indicator_texture;

	SpriteObject *m_parent_bar;
	sf::Texture m_parent_bar_texture;

	std::vector<BikeKid*> m_bike_kid;
	sf::Texture m_bike_kid_texture;
	std::vector<Collider*> m_bike_kid_collider;

	SpriteObject *m_framehealthbar;
	sf::Texture m_framehealthbar_texture;

	SpriteObject *m_crosshair;
	sf::Texture m_crosshair_texture;

	SpriteObject *m_healthbar;
	sf::Texture m_healthbar_texture;

	SpriteObject *m_heatbar;
	sf::Texture m_heatbar_texture;

	SpriteObject *m_frameheatbar;
	sf::Texture m_frameheatbar_texture;

	CountdownTimer* m_levelup_timer;


	float m_healthbar_amount;

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

