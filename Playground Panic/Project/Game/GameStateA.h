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
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level);
	std::string Next();
	bool IsType(const std::string &type);
private:
	Collider* Collisions; //Do we ever use this? I'll probably check later
	sf::Vector2f m_mouse_position;

	std::string m_next_state;
	/////////////////////////////////////SOUND

	sf::SoundBuffer steam_buffer;
	sf::Sound steam_sound;

	sf::SoundBuffer kids_booing_buffer;
	sf::Sound kids_booing_sound;

	sf::SoundBuffer insane_guy_buffer;
	sf::Sound insane_guy_sound;

	sf::SoundBuffer YAY_buffer;
	sf::Sound sound_YAY;

	sf::Sound kid_oof;
	sf::SoundBuffer kid_oof_buffer;

	sf::Sound mud_hit;
	sf::SoundBuffer mud_hit_buffer;

	sf::Sound soundshoot1;
	sf::SoundBuffer shoot1;

	sf::Sound soundkidhit;
	sf::SoundBuffer splashkid;

	sf::Music music;
	//////////////////////////////////////

	SpriteObject *m_varning;
	sf::Texture m_varning_texture;

	SpriteObject* m_background;
	sf::Texture m_background_texture;
	SpriteObject* m_background_overlay;
	sf::Texture m_background_overlay_texture;

	//StateManager * mgr;
	CountdownTimer* m_timer;
	PlayerObject * m_player;
	Collider * m_player_collider;
	sf::Texture m_player_texture;
	std::string m_player_female_walk_path;

	std::vector<ProjectileObject*> m_projectile;
	sf::Texture m_projectile_texture;
	std::string m_projectile_path;
	std::vector<Collider*> m_projectile_collider;

	std::vector<Enemy*> m_enemies;

	sf::Texture m_player_dirt_texture;
	sf::Texture m_slow_kid_dirt_texture;
	sf::Texture m_bike_kid_dirt_texture;

	std::vector<SlowKid*> m_slow_kid;
	sf::Texture m_slow_kid_texture;
	std::string m_slow_kid_path;
	std::vector<Collider*> m_slow_kid_collider;

	std::vector<BikeKid*> m_bike_kid;
	sf::Texture m_bike_kid_texture;
	std::string m_bike_kid_path;
	std::vector<Collider*> m_bike_kid_collider;
	sf::Texture m_projectile_mud_texture;

	std::vector<ParentUI*> m_parentUI;
	std::map<ParentUI*, SlowKid*>mm_special_kid;
	sf::Texture m_parent_ball_texture;
	sf::Texture m_arrow_texture;
	sf::Texture m_indicator_texture;

	SpriteObject *m_parent_bar;
	sf::Texture m_parent_bar_texture;
	SpriteObject *m_uibg;
	sf::Texture m_uibg_texture;

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

	SpriteObject *m_clear;
	sf::Texture m_clear_texture;

	CountdownTimer* m_levelup_timer;

	sf::Vector2f m_point_house;
	sf::Vector2f m_point_street;

	float m_healthbar_amount;

	sf::Clock m_player_pst;
	//Time between projectile-spawns
	sf::Int32 m_player_pss;

	sf::Clock m_enemy_pst;
	sf::Int32 m_enemy_pss;

	sf::Clock m_health_pst;
	sf::Int32 m_health_pss;

	sf::Clock m_end_time;
	sf::Int32 m_end_pause;

	sf::Clock m_blink_pst;
	sf::Int32 m_blink_pss;
	bool m_varning_shit_happens;

	std::vector<Collider*> m_map_colliders;

	float m_global_speed;


	//sf::Time deltaTime;

	int m_enemies_to_spawn;

	int m_special_to_spawn;

	bool m_first_run;

	bool m_continue;
};

