#pragma once

#include "stdafx.h"
#include <iostream>
#include "ParentUI.h"

class Sprite;

class Indicator : public sf::Sprite
{
public:
	Indicator(sf::Texture * indicator, sf::Color color);
	~Indicator();
	void Update(sf::Vector2f player_pos);
	void Initialize();
	sf::Sprite GetSprite();

private:


};