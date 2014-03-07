//SpriteObject.cpp

#include "stdafx.h"
#include "SpriteObject.h"

SpriteObject::SpriteObject(sf::Texture* texture) : GameObject(texture)
{
	m_sprite = new sf::Sprite(*m_texture);
}

SpriteObject::~SpriteObject()
{
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