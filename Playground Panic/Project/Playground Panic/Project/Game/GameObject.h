
#pragma once

#include "stdafx.h"
class Collider;
class Sprite;

class GameObject{
	friend class Level;
	friend class MenuState;
	friend class OptionsState;
public:
	GameObject(sf::Sprite* sprite, sf::Texture* texture = nullptr, Collider *collider = nullptr, int flag = 0);

	const sf::Vector2f &GetPosition() const;
	void SetPosition(const sf::Vector2f &position);
	bool HasTexture() const;
	sf::Texture* GetTexture();
	bool HasCollider() const;
	Collider* GetCollider();
	sf::Sprite* GetSprite();
	//sf::Shape* HasShape();

protected:
	sf::Vector2f m_position;
	sf::Texture* m_texture;
	Collider *m_collider;
	int m_flag;
	sf::Sprite* m_sprite;
};