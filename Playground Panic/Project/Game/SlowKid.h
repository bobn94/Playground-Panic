#pragma once

#include "stdafx.h"
#include "Enemy.h"

class PlayerObject;
class CountdownTimer;


class SlowKid : public Enemy
{
public:
	SlowKid(sf::Texture* texture, float radius, int atkTimer, bool special, sf::Texture* dirt_texture, std::string filepath);
	SlowKid(sf::Vector2f spawn_pos);
	~SlowKid();
	void SetSprite();
	void Update(float deltatime, float global_speed, PlayerObject* player, sf::Vector2f origin, sf::Vector2f target);
	bool IsHit();
	void SetHit(bool hit);

private:
	float m_pi;
	CountdownTimer* m_attack_timer;
	sf::Vector2f m_velocity;
	sf::Vector2f m_player_position;

	bool m_hit;
};