// PlayerObject.h

#pragma once

#include "GameObject.h"
#include <map>
#include <string>
#include "stdafx.h"

class Keyboard;
class Sprite;
class Collider;
class AnimatedSprite;

class PlayerObject : public GameObject
{
public:
	PlayerObject(sf::Sprite* sprite, sf::Texture* texture = nullptr, Collider* collider = nullptr);

	void Update(float deltatime, float global_speed, sf::Vector2i mousePos);
	void Collision(bool hit);
	int GetMiddle(int width);

	void AddAnimation(const std::string &name, AnimatedSprite *sprite);

protected:
	Keyboard* m_keyboard;
	int m_speed;
	int m_org_speed;
	float m_pi;

	AnimatedSprite *m_current_animation;
	std::map<std::string, AnimatedSprite*> m_animations;
};