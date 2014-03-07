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
	PlayerObject(sf::Texture* texture, float radius, Collider* collider);

	void Update(float deltatime, float global_speed, sf::Vector2f mousePos);
	void Collision(bool hit);
	int GetMiddle(int width);
	void AddAnimation(const std::string &name, AnimatedSprite *sprite);
	float GetCurrentHealth();
	float GetMaxHealth();
	void SetCurrentHealth(float hp);
	float GetWeaponHeat();
	float GetWeaponMaxHeat();
	void SetWeaponHeat(float heat);
	bool GetOverheat();
	void SetOverheat(bool tf);

protected:
	Keyboard* m_keyboard;
	int m_speed;
	int m_org_speed;
	float m_pi;
	float m_currentHP;
	float m_maxHP;
	AnimatedSprite *m_current_animation;
	std::map<std::string, AnimatedSprite*> m_animations;

	bool m_Overheat;
	float m_weapon_heat;
	float m_weapon_max_heat;
};