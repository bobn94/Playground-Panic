
#pragma once
#include "stdafx.h"


class Collider{
public:
	Collider();
	Collider(sf::Vector2f position, sf::Vector2f extention);

	bool Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2, sf::Vector2f &offset);
	bool Overlap(Collider *map, sf::Vector2f origo1, float radius1, sf::Vector2f &offset);
	bool Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2);
	bool Overlap(Collider &self, Collider &other, sf::Vector2f &offset);
	sf::Vector2f m_position;
	sf::Vector2f m_extention;

};