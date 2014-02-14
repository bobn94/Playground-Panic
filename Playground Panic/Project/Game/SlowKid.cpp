#include "stdafx.h"
#include "SlowKid.h"

	SlowKid::SlowKid(sf::Sprite* sprite, Collider* collider) : Enemy(sprite, collider){
		m_pi = 3.14159265359f;

	}
	
	SlowKid::SlowKid(sf::Vector2f spawn_pos){
		m_pi = 3.14159265359f;
		
	}
	SlowKid::~SlowKid(){
		m_pi = 3.14159265359f;

	}
	void SlowKid::SetSprite(){
		
	}
	void SlowKid::Update(float deltatime, float global_speed, sf::Vector2f playerPos){
		sf::Vector2f origin = m_sprite->getPosition();

	//Calculate the direction vector
	sf::Vector2f dirVec = sf::Vector2f(playerPos.x - origin.x, playerPos.y - origin.y);

	//Calculate the length^2
	float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

	//Change the mag to 1 (you dont need the y for getting the angle
	dirVec.x = (dirVec.x) / magSquare;

	//Get the angle and change it to deg (SFML need deg)
	float rotAngle = std::acos(dirVec.x) * (180 / m_pi);

	if (m_sprite->getPosition().y < playerPos.y)
	{
		// - 13
		m_sprite->setRotation(90 + rotAngle);
	}
	else if (m_sprite->getPosition().x == playerPos.x && m_sprite->getPosition().y == playerPos.y)
	{
	}
	else
	{
		// - 13
		m_sprite->setRotation(90 - rotAngle);
	}


/*
	if (m_current_animation != nullptr)
	{
		m_current_animation->Update(deltatime);
	}
*/

	m_position = m_sprite->getPosition();

	//if (HasCollider())
	//{
		//m_collider->m_position = m_sprite->getPosition();
	//}
}	