// ProjectileObject.cpp

#include "stdafx.h"
#include "ProjectileObject.h"
#include "Collider.h"
#include "Sprite.h"
//#include "AnimatedSprite.h"

#include <iostream>

//using namespace sf;

ProjectileObject::ProjectileObject(sf::Texture* texture, float radius, std::string filepath, int type)
: GameObject(texture, radius, nullptr, filepath, type)
{
	m_type = type;
	m_speed = 1000000;
	m_org_speed = m_speed;
	m_current_animation = nullptr;
	m_pi = 3.14159265359f;
	
	m_sprite = new sf::Sprite(*m_texture);
	if (m_type == 0)
	{
		m_sprite->setScale(0.6f, 0.6f);
	}
}

ProjectileObject::~ProjectileObject()
{
	delete m_sprite;
	//delete m_collider;
}

void ProjectileObject::Initialize(sf::Vector2f origin, sf::Vector2f target, sf::Vector2f player_position)
{
	//m_sprite->setPosition(origin);
	//m_position = origin;
	m_mouse_position = target;
/*
	float AngleX = origin.x - target.x;
	float AngleY = origin.y - target.y;
*/
	float AngleX = target.x - origin.x;
	float AngleY = target.y - origin.y;

	float vectorLength = sqrt(AngleX * AngleX + AngleY * AngleY);

	float DirectionX = AngleX / vectorLength;
	float DirectionY = AngleY / vectorLength;

	m_velocity = sf::Vector2f(DirectionX * m_speed, DirectionY * m_speed);

	//////////////Rotation
	//Your origin
	//sf::Vector2f origin = m_sprite->getPosition();

	//Calculate the direction vector
	sf::Vector2f dirVec = sf::Vector2f(target.x - origin.x, target.y - origin.y);

	//Calculate the length^2
	float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	//Change the mag to 1 (you dont need the y for getting the angle
	dirVec.x = (dirVec.x) / magSquare;

	//Get the angle and change it to deg (SFML need deg)
	float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

	if (m_sprite->getPosition().y < player_position.y)
	{
		//Mouse below player
		if (m_sprite->getPosition().y < target.y)
		{
			//std::cout << "1 -" << std::endl;
			m_sprite->setRotation(90 - rotAngle);
		}
		else if (m_sprite->getPosition().x == target.x && m_sprite->getPosition().y == target.y)
		{
		}
		//Mouse above player
		else
		{
			//std::cout << "2 -" << std::endl;
			m_sprite->setRotation(90 - rotAngle);
		}
	}
	else
	{
		//Mouse below player
		if (m_sprite->getPosition().y < target.y)
		{
			//std::cout << "3 +" << std::endl;
			m_sprite->setRotation(90 + rotAngle);
		}
		else if (m_sprite->getPosition().x == target.x && m_sprite->getPosition().y == target.y)
		{
		}
		//Mouse above player
		else
		{
			//std::cout << "4 +" << std::endl;
			m_sprite->setRotation(90 + rotAngle);
		}
	}

}

void ProjectileObject::Update(float deltatime, float global_speed, sf::Vector2i mousePos) //Remove mousePos unless we do homing
{

	m_sprite->move(m_velocity * deltatime * global_speed);

	if (1 == 0) //Homing
	{
		//////////////Rotation
		//Your origin
		sf::Vector2f origin = m_sprite->getPosition();

		//Calculate the direction vector
		sf::Vector2f dirVec = sf::Vector2f(m_mouse_position.x - origin.x, m_mouse_position.y - origin.y);

		//Calculate the length^2
		float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

		//Change the mag to 1 (you dont need the y for getting the angle
		dirVec.x = (dirVec.x) / magSquare;

		//Get the angle and change it to deg (SFML need deg)
		float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

		if (m_sprite->getPosition().y < m_mouse_position.y)
		{
			m_sprite->setRotation(90 + rotAngle);
		}
		else if (m_sprite->getPosition().x == m_mouse_position.x && m_sprite->getPosition().y == m_mouse_position.y)
		{
		}
		else
		{
			m_sprite->setRotation(90 - rotAngle);
		}
	}

	if (m_animated)
	{
		UpdateFrame(deltatime);
	}

	m_position = m_sprite->getPosition();

	/*if (HasCollider())
	{
		m_collider->m_position = m_sprite->getPosition();
	}*/
}
/*
void ProjectileObject::AddAnimation(const std::string &name, AnimatedSprite *sprite)
{
m_animations.insert(std::pair<std::string, AnimatedSprite*>(name, sprite));
if (m_sprite == nullptr)
{
m_sprite = sprite;
m_current_animation = sprite;
}
}
*/
int ProjectileObject::GetMiddle(int width)
{
	int temp = width / 2;
	return m_position.x + temp;
}

int ProjectileObject::GetType()
{
	return m_type;
}