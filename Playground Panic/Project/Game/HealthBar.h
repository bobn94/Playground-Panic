// HealtBar.h

#pragma once

#include "GameObject.h"
#include <map>
#include <string>
#include "stdafx.h"

class Sprite;
class Collider;
class AnimatedSprite;

class HealthBar : public GameObject
{
public:
	HealthBar();
	~HealthBar();
	void HealthBar::SetSprite();
	HealthBar(sf::Texture* texture);
	int Health();
	float m_healthfull;
	//void Update(float deltatime);
	//void AddAnimation(const std::string &name, AnimatedSprite *sprite);
private:
	sf::Sprite *m_framehealthbar_sprite;
	sf::Texture *m_framehealthbar_texture;
	sf::Sprite *m_healthbar_sprite;
	sf::Texture *m_healthbar_texture;
/*protected:
	AnimatedSprite *m_current_animation;
	std::map<std::string, AnimatedSprite*> m_animations;*/
};