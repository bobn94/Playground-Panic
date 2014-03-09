#include "stdafx.h"
#include "Sprite.h"
#include "GameObject.h"
//#include "Collider.h"

GameObject::GameObject(sf::Texture* texture, float radius, sf::Texture* dirt_texture, Collider *collider, int flag)
:m_position(0.0f, 0.0f)
,m_texture(texture)
,m_collider(collider)
,m_flag(flag)
,m_radius(radius)
,m_dirt_texture(dirt_texture)
{
	m_sprite = new sf::Sprite(*m_texture);
	if(m_dirt_texture != nullptr){
		m_dirt_sprite1 = new sf::Sprite(*m_dirt_texture);
	}
}

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

const sf::Vector2f &GameObject::GetPosition() const 
{
	return m_position;
}

void GameObject::SetPosition(const sf::Vector2f &position)
{
	m_position = position;
	m_sprite->setPosition(position.x, position.y);
}

bool GameObject::HasTexture() const
{
	return m_texture;
}

sf::Texture* GameObject::GetTexture()
{
	return m_texture;
}
	
bool GameObject::HasCollider() const
{
		
	return m_collider != nullptr;
}

Collider* GameObject::GetCollider()
{
	return m_collider;
}

sf::Sprite* GameObject::GetSprite()
{
	return m_sprite;
}

void GameObject::Draw(sf::RenderWindow *window)
{
	window->draw(*m_sprite);
	if(m_dirt_texture != nullptr)
	{
		window->draw(*m_dirt_sprite1);
	}
}

float GameObject::GetRadius()
{
	return m_radius;
}
