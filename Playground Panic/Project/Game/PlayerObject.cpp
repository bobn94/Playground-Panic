// PlayerObject.cpp

#include "stdafx.h"
#include "PlayerObject.h"
#include "Input.h"
#include "Collider.h"
#include "Sprite.h"
//#include "AnimatedSprite.h"

//using namespace sf;

PlayerObject::PlayerObject(sf::Texture* texture, float radius, Collider* collider, sf::Texture* dirt_texture, std::string filepath = "")
: GameObject(texture, radius, dirt_texture, filepath)
{
	m_speed = 70000;
	m_org_speed = m_speed;
	m_current_animation = nullptr;
	m_pi = 3.14159265359f;
	m_maxHP = 21;
	m_currentHP = 0;
	
	m_weapon_heat = 0;
	m_weapon_max_heat = 53;
	m_Overheat = false;

	m_sprite->setScale(0.7f, 0.7f);
	m_sprite->setOrigin((m_sprite->getLocalBounds().width / 2) - 2, (m_sprite->getLocalBounds().height / 2) + 32);

	m_dirt_sprite1->setScale(0.7f, 0.7f);
	m_dirt_sprite1->setOrigin((m_dirt_sprite1->getLocalBounds().width / 2) - 2, (m_dirt_sprite1->getLocalBounds().height / 2) + 32);
}

void PlayerObject::Update(float deltatime, float global_speed, sf::Vector2f mousePos)
{
	//////////Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_sprite->move(0.0f, -4.0f * deltatime * m_speed * global_speed);
		}
		else
		{
			m_sprite->move(0.0f, -5.0f * deltatime * m_speed * global_speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_sprite->move(0.0f, 4.0f * deltatime * m_speed * global_speed);
		}
		else
		{
			m_sprite->move(0.0f, 5.0f * deltatime * m_speed * global_speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_sprite->move(-4.0f * deltatime * m_speed * global_speed, 0.0f);
		}
		else
		{
			m_sprite->move(-5.0f * deltatime * m_speed * global_speed, 0.0f);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_sprite->move(4.0f * deltatime * m_speed * global_speed, 0.0f);
		}
		else
		{
			m_sprite->move(5.0f * deltatime * m_speed * global_speed, 0.0f);
		}
	}


	//////////////Rotation
	//Your origin
	sf::Vector2f origin = m_sprite->getPosition();

	//Calculate the direction vector
	sf::Vector2f dirVec = sf::Vector2f(mousePos.x - origin.x, mousePos.y - origin.y);

	//Calculate the length^2
	float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	//Change the mag to 1 (you dont need the y for getting the angle
	dirVec.x = (dirVec.x) / magSquare;

	//Get the angle and change it to deg (SFML need deg)
	float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

	if (m_sprite->getPosition().y < mousePos.y)
	{
		m_sprite->setRotation(90 + rotAngle);
		m_dirt_sprite1->setRotation(90 + rotAngle);
		m_dirt_sprite1->setColor( sf::Color(255,255,255,(255 * (GetCurrentHealth()/GetMaxHealth()))));
	}
	else if (m_sprite->getPosition().x == mousePos.x && m_sprite->getPosition().y == mousePos.y)
	{

	}
	else
	{
		m_sprite->setRotation(90 - rotAngle);
		m_dirt_sprite1->setRotation(90 - rotAngle);
		m_dirt_sprite1->setColor( sf::Color(255,255,255,(255 * (GetCurrentHealth() / GetMaxHealth()))));
			
	}

/*
	if (m_current_animation != nullptr)
	{
		m_current_animation->Update(deltatime);
	}
*/

	m_position = m_sprite->getPosition();

	/*if (HasCollider())
	{
		m_collider->m_position = m_sprite->getPosition();
	}*/

	if (m_dirt_texture != nullptr)
	{
		m_dirt_sprite1->setPosition(m_sprite->getPosition().x, m_sprite->getPosition().y);
	}

	if (m_animated)
	{
		UpdateFrame(deltatime);
	}
}
/*
void PlayerObject::AddAnimation(const std::string &name, AnimatedSprite *sprite)
{
	m_animations.insert(std::pair<std::string, AnimatedSprite*>(name, sprite));
	if (m_sprite == nullptr)
	{
		m_sprite = sprite;
		m_current_animation = sprite;
	}
}
*/
int PlayerObject::GetMiddle(int width)
{
	int temp = width / 2;
	return m_position.x + temp;
}

float PlayerObject::GetMaxHealth()
{
	return m_maxHP;
}

float PlayerObject::GetCurrentHealth()
{
	
	return m_currentHP;
}

void PlayerObject::SetCurrentHealth(float hp)
{
	m_currentHP = hp;
}

float PlayerObject::GetWeaponHeat(){
	return m_weapon_heat;
}

void PlayerObject::SetWeaponHeat(float heat){
	m_weapon_heat = heat;
}
float PlayerObject::GetWeaponMaxHeat(){
	return m_weapon_max_heat;
}
bool PlayerObject::GetOverheat(){
	return m_Overheat;
}
void PlayerObject::SetOverheat(bool truefalse){
	m_Overheat = truefalse;
}