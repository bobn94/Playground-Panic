#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <string>

class Enemy : public GameObject{
public:
	Enemy();
	Enemy(sf::Sprite* sprite, Collider* collider);
	bool GetCanShoot();
	int GetDirt();
	float GetSpeed();
private:
	bool m_canShoot;
	int m_dirtLevel;
	float m_speed;
};