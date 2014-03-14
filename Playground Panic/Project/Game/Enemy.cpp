#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	//I don't want this one here ._.
}

Enemy::Enemy(sf::Texture* texture, float radius, bool special, sf::Texture* dirt_texture) : GameObject(texture, radius, dirt_texture)
{
	m_special = special;
	if (m_special == true)
	{
		//std::cout << "SpecialKid" << std::endl;
	}
	m_on_target = false;
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

float Enemy::GetDirt(){
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

bool Enemy::OnTarget()
{
	return m_on_target;
}

void Enemy::OnTarget(bool bl)
{
	m_on_target = bl;
}