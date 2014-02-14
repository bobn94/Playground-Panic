#include "stdafx.h"
#include "Sprite.h"
#include "GameObject.h"
//#include "Collider.h"

GameObject::GameObject(sf::Sprite* sprite, Collider *collider, int flag)
:m_position(0.0f, 0.0f)
,m_sprite(sprite)
,m_collider(collider)
,m_flag(flag)
{
	
}
	GameObject::GameObject(){

	}
	const sf::Vector2f &GameObject::GetPosition() const {
		return m_position;
	}
	void GameObject::SetPosition(const sf::Vector2f &position){
		m_position = position;
		m_sprite->setPosition(position.x, position.y);
	}
	bool GameObject::HasTexture() const{
		return m_texture;
	}
	sf::Texture* GameObject::GetTexture(){
		return m_texture;
	}
	
	bool GameObject::HasCollider() const{
		
		return m_collider != nullptr;
	}
	Collider* GameObject::GetCollider(){
		return m_collider;
	}

	sf::Sprite* GameObject::GetSprite(){
		return m_sprite;
	}