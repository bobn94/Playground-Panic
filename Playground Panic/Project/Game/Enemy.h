#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <string>

class Enemy : public GameObject{
public:
	Enemy();
	Enemy(sf::Sprite* sprite, float radius);
	bool GetCanShoot();
	int GetDirt();
	float GetSpeed();
	int m_dirtLevel;
	float m_speed;
private:
	bool m_canShoot;
};