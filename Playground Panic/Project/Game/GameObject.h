
#pragma once

#include "stdafx.h"
class Collider;
class Sprite;

class GameObject
{
	friend class Level;
	friend class MenuState;
	friend class OptionsState;
public:
	GameObject();
	GameObject(sf::Texture* texture, float radius = 32, sf::Texture* dirt_texture = nullptr, Collider *collider = nullptr, int flag = 0);
	virtual ~GameObject();

	const sf::Vector2f &GetPosition() const;
	void SetPosition(const sf::Vector2f &position);
	bool HasTexture() const;
	sf::Texture* GetTexture();
	bool HasCollider() const;
	Collider* GetCollider();
	sf::Sprite* GetSprite();
	//sf::Shape* HasShape();
	float GetRadius();

	void Draw(sf::RenderWindow *window);

protected:
	sf::Vector2f m_position;
	sf::Texture* m_texture;
	sf::Texture* m_dirt_texture;
	Collider *m_collider;
	int m_flag;
	sf::Sprite* m_dirt_sprite1;
	sf::Sprite* m_sprite;
	float m_radius;
};