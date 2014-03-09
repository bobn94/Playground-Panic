#include "stdafx.h"
#include "SlowKid.h"
#include "Collider.h"
#include "PlayerObject.h"
#include "CountdownTimer.h"
#include <iostream>

SlowKid::SlowKid(sf::Texture* texture, float radius, int atkTimer, bool special, sf::Texture* dirt_texture) : Enemy(texture, radius, special, dirt_texture)
{
	m_pi = 3.14159265359f;
	m_dirtLevel = 6;
	m_speed = 150000.0f;
	m_attack_timer = new CountdownTimer();
	m_attack_timer->SetTime(0, 0, atkTimer);
	m_attack_timer->Start();
	m_hit = false;

	m_sprite->setScale(0.6f, 0.6f);
	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2, m_sprite->getLocalBounds().height / 2);
	
	m_dirt_sprite1->setScale(0.6f, 0.6f);
	m_dirt_sprite1->setOrigin(m_dirt_sprite1->getLocalBounds().width / 2, m_dirt_sprite1->getLocalBounds().height / 2);
}
	
SlowKid::SlowKid(sf::Vector2f spawn_pos){
	m_pi = 3.14159265359f;		
}
SlowKid::~SlowKid(){
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
}
void SlowKid::SetSprite(){
		
}
void SlowKid::Update(float deltatime, float global_speed, PlayerObject *player, sf::Vector2f origin, sf::Vector2f target){
	m_sprite->setPosition(origin);
	m_position = origin;
	m_player_position = target;
	m_attack_timer->Update();
	float AngleX = target.x - origin.x;
	float AngleY = target.y - origin.y;

	float vectorLength = sqrt(AngleX * AngleX + AngleY * AngleY);

	float DirectionX = AngleX / vectorLength;
	float DirectionY = AngleY / vectorLength;
	m_velocity = sf::Vector2f(DirectionX * m_speed, DirectionY * m_speed);
	if(vectorLength >= 55 && vectorLength <= 600)
	{
		m_sprite->move(m_velocity * deltatime * global_speed);

		sf::Vector2f m_origin = m_sprite->getPosition();

	//Calculate the direction vector
		sf::Vector2f dirVec = sf::Vector2f(player->GetPosition().x - origin.x, player->GetPosition().y - origin.y);

	//Calculate the length^2
		float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	//Change the mag to 1 (you dont need the y for getting the angle
		dirVec.x = (dirVec.x) / magSquare;

	//Get the angle and change it to deg (SFML need deg)
		float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

		if (m_sprite->getPosition().y < player->GetPosition().y)
		{
			m_sprite->setRotation(90 + rotAngle);
			m_dirt_sprite1->setRotation(90 + rotAngle);
			m_dirt_sprite1->setColor(sf::Color(255,255,255,(255 * (GetDirt()/6))));
		}
		else if (m_sprite->getPosition().x == player->GetPosition().x && m_sprite->getPosition().y == player->GetPosition().y)
		{
		}
		else
		{
			m_sprite->setRotation(90 - rotAngle);
			m_dirt_sprite1->setRotation(90 - rotAngle);
			m_dirt_sprite1->setColor(sf::Color(255,255,255,(255 * (GetDirt()/6))));
		}


	/*
		if (m_current_animation != nullptr)
		{
			m_current_animation->Update(deltatime);
		}
	*/

		m_position = m_sprite->getPosition();

		if (HasCollider())
		{
			m_collider->m_position = m_sprite->getPosition();
		}
	}
	else if(vectorLength <= 10)
	{
		sf::Vector2f dirVec = sf::Vector2f(player->GetPosition().x - origin.x, player->GetPosition().y - origin.y);

	//Calculate the length^2
		float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	//Change the mag to 1 (you dont need the y for getting the angle
		dirVec.x = (dirVec.x) / magSquare;

	//Get the angle and change it to deg (SFML need deg)
		float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

		if (m_sprite->getPosition().y < player->GetPosition().y)
		{
			m_sprite->setRotation(90 + rotAngle);
			m_dirt_sprite1->setRotation(90 + rotAngle);
			m_dirt_sprite1->setColor(sf::Color(255,255,255,(255 * (GetDirt()/6))));
		}
		else if (m_sprite->getPosition().x == player->GetPosition().x && m_sprite->getPosition().y == player->GetPosition().y)
		{
		}
		else
		{
			m_sprite->setRotation(90 - rotAngle);
			m_dirt_sprite1->setRotation(90 - rotAngle);
			m_dirt_sprite1->setColor(sf::Color(255,255,255,(255 * (GetDirt()/6))));
		}

		if(m_attack_timer->Done()){
			player->SetCurrentHealth(player->GetCurrentHealth() + 1.0f);
			if(player->GetCurrentHealth() > player->GetMaxHealth()){
				player->SetCurrentHealth(player->GetMaxHealth());
			}
			//std::cout << player->GetCurrentHealth();
			m_attack_timer->Reset();
			m_attack_timer->Start();
		}
		
	}
	if(vectorLength <= 55){
		if(m_attack_timer->Done()){
		player->SetCurrentHealth(player->GetCurrentHealth() + 1.0f);
		if(player->GetCurrentHealth() > player->GetMaxHealth()){
			player->SetCurrentHealth(player->GetMaxHealth());
		}
		//std::cout << player->GetCurrentHealth();
		m_attack_timer->Reset();
		m_attack_timer->Start();
	}
	}
	if(m_dirtLevel < 0){
		m_dirtLevel = 0;
	}
	if (m_dirt_sprite1 != nullptr){
		m_dirt_sprite1->setPosition(m_sprite->getPosition().x, m_sprite->getPosition().y);
	}
}

bool SlowKid::IsHit()
{
	return m_hit;
}

void SlowKid::SetHit(bool hit)
{
	m_hit = hit;
}