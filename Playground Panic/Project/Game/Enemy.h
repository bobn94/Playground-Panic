#pragma once

#include "stdafx.h"
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(sf::Texture* texture, float radius, bool special, sf::Texture* dirt_texture, std::string filepath = "");
	virtual ~Enemy();
	bool GetCanShoot();
	float GetDirt();
	void SetDirt(int dirt);
	float GetSpeed();
	bool GetSpecial();
	bool OnTarget();
	void OnTarget(bool bl);

protected:
	bool m_canShoot;
	bool m_special;
	float m_dirtLevel;
	float m_speed;
	bool m_hit; //Fix this for enemy-collision
	sf::Vector2f m_target;
	bool m_on_target;
};