// ProjectileObject.h

#pragma once

#include "GameObject.h"
#include <map>
#include <string>
#include "stdafx.h"

class Sprite;
class Collider;
class AnimatedSprite;

class ProjectileObject : public GameObject
{
public:
	ProjectileObject(sf::Texture* texture, float radius, std::string filepath = "", int type = 0);
	~ProjectileObject();
	void Initialize(sf::Vector2f origin, sf::Vector2f target, sf::Vector2f player_position);

	void Update(float deltatime, float global_speed, sf::Vector2i mousePos);
	void Collision(bool hit);
	int GetMiddle(int width);
	int GetType();
	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

protected:
	int m_speed;
	int m_org_speed;
	float m_pi;
	int m_type; //0 = player, 1 = enemy
	/*sf::Vector2f m_position;
	sf::Vector2f m_target;*/
	sf::Vector2f m_velocity;
	sf::Vector2f m_mouse_position;

	AnimatedSprite *m_current_animation;
	std::map<std::string, AnimatedSprite*> m_animations;
};