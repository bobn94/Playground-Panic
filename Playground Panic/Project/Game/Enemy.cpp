#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	//I don't want this one here ._.
}

Enemy::Enemy(sf::Texture* texture, float radius, bool special) : GameObject(texture, radius)
{
	m_special = special;
	if (m_special == true)
	{
		//std::cout << "SpecialKid" << std::endl;
	}
}

Enemy::~Enemy()
{
	if (m_sprite != nullptr)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}
	if (m_collider != nullptr)
	{
		delete m_collider;
		m_collider = nullptr;
	}
	//delete this;
}

bool Enemy::GetCanShoot(){
	return m_canShoot;
}

int Enemy::GetDirt(){
	return m_dirtLevel;
}

void Enemy::SetDirt(int dirt){
	m_dirtLevel = dirt;
}

float Enemy::GetSpeed(){
	return m_speed;
}

bool Enemy::GetSpecial()
{
	return m_special;
}