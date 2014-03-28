#include "stdafx.h"
#include "Sprite.h"
#include "GameObject.h"
#include <fstream>
#include <sstream>
#include <iostream>
//#include "Collider.h"

GameObject::GameObject(sf::Texture* texture, float radius, sf::Texture* dirt_texture, std::string filepath, int flag)
:m_position(0.0f, 0.0f)
,m_texture(texture)
,m_flag(flag)
,m_radius(radius)
,m_dirt_texture(dirt_texture)
{
	m_sprite = new sf::Sprite(*m_texture);
	if (filepath != "")
	{
		LoadAnimation(filepath, m_texture);
		m_animated = true;
		m_current_frame = 0;
		m_time = 0.0f;
	}	
	else
	{
		m_animated = false;
	}

	if (m_dirt_texture != nullptr)
	{
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

void GameObject::LoadAnimation(std::string path, sf::Texture* texture)
{
	std::ifstream stream;
	stream.open(path.c_str());
	bool first = true;
	if (!stream.is_open())
	{
		return;
	}
	std::string row;
	stream >> row;

	for (int j = m_animation.size() - 1; j >= 0; j--)
	{
		m_animation.erase(m_animation.begin() + j);
	}

	std::string imgpath;
	int rownr = 0;
	while (!stream.eof())
	{
		rownr++;
		if (first)
		{
			std::getline(stream, row) >> imgpath;
			texture->loadFromFile("../data/textures/Animation/" + imgpath);
			m_sprite->setTexture(*texture);
			first = false;
		}
		else
		{
			std::getline(stream, row);
		}
		if (row.length() == 0)
		{
			continue;
		}
		std::stringstream ss(row);

		Frame frame;

		ss >> frame.duration;
		ss >> frame.x;
		ss >> frame.y;
		ss >> frame.width;
		ss >> frame.height;
		
		if (first)
		{
			//m_sprite->setTextureRect(sf::IntRect(frame.x, frame.y, frame.width, frame.height));
			first = false;
		}
		m_animation.push_back(frame);
	}

	stream.close();
}

void GameObject::UpdateFrame(float deltatime)
{
	m_time += 1000 * deltatime;
	//std::cout << m_time << std::endl;
	if (m_time >= m_animation[m_current_frame].duration) {
		m_time = 0.0f;
		m_current_frame = ++m_current_frame % m_animation.size();

		Frame &frame = m_animation[m_current_frame];
		m_sprite->setTextureRect(sf::IntRect(frame.x, frame.y, frame.width, frame.height));
	}
}