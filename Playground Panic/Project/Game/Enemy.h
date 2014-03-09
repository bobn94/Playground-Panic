#pragma once

#include "stdafx.h"
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(sf::Texture* texture, float radius, bool special, sf::Texture* dirt_texture);
	virtual ~Enemy();
	bool GetCanShoot();
	float GetDirt();
	void SetDirt(int dirt);
	float GetSpeed();
	bool GetSpecial();

protected:
	bool m_canShoot;
	bool m_special;
	float m_dirtLevel;
	float m_speed;
};