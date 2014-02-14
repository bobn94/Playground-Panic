// ProjectileObject.cpp

#include "stdafx.h"
#include "ProjectileObject.h"
#include "Collider.h"
#include "Sprite.h"
//#include "AnimatedSprite.h"

//using namespace sf;

ProjectileObject::ProjectileObject(sf::Sprite* sprite, Collider* collider)
: GameObject(sprite, collider)
{
	m_speed = 1000000;
	m_org_speed = m_speed;
	m_current_animation = nullptr;
	m_pi = 3.14159265359f;
}

void ProjectileObject::Initialize(sf::Vector2f origin, sf::Vector2i target)
{
	m_sprite->setPosition(origin);
	m_position = origin;
	m_mouse_position = target;

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

	if (m_sprite->getPosition().y < target.y)
	{
		// - 13
		m_sprite->setRotation(90 + rotAngle);
	}
	else if (m_sprite->getPosition().x == target.x && m_sprite->getPosition().y == target.y)
	{
	}
	else
	{
		// - 13
		m_sprite->setRotation(90 - rotAngle);
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
			// - 13
			m_sprite->setRotation(90 + rotAngle);
		}
		else if (m_sprite->getPosition().x == m_mouse_position.x && m_sprite->getPosition().y == m_mouse_position.y)
		{
		}
		else
		{
			// - 13
			m_sprite->setRotation(90 - rotAngle);
		}
	}

	/*
	if (m_current_animation != nullptr)
	{
	m_current_animation->Update(deltatime);
	}
	*/

	//m_sprite->setPosition(m_mouse_position.x, m_mouse_position.y);

	m_position = m_sprite->getPosition();

	if (HasCollider())
	{
		m_collider->m_position = m_sprite->getPosition();
	}
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