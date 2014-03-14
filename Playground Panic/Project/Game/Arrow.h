#pragma once

#include "stdafx.h"
#include <iostream>
#include "ParentUI.h"

class Sprite;

class Arrow : public sf::Sprite
{
public:
	Arrow(sf::Texture * arrow, sf::Color color);
	~Arrow();
	void Update(sf::Vector2f enemy_pos, sf::Color color);
	void Initialize();
private:
	sf::Color m_color;
};