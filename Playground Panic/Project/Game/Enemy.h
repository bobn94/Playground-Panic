#pragma once

#include "stdafx.h"
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(sf::Texture* texture, float radius, bool special);
	virtual ~Enemy();
	bool GetCanShoot();
	int GetDirt();
	void SetDirt(int dirt);
	float GetSpeed();
	bool GetSpecial();

protected:
	bool m_canShoot;
	bool m_special;
	int m_dirtLevel;
	float m_speed;
};