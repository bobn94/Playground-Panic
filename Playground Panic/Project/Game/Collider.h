
#pragma once
#include "stdafx.h"


class Collider{
public:
	Collider();
	Collider(const sf::Vector2f &position, const sf::Vector2f &extention);

	bool Overlap(Collider &other, Collider &self, sf::Vector2f &offset);

	sf::Vector2f m_position;
	sf::Vector2f m_extention;

};