#pragma once
#include "stdafx.h"
#include "ParentUI.h"

class ParentBall : public sf::Sprite
{
public:
	ParentBall(sf::Texture * ball, sf::Color color, sf::View *view);
	~ParentBall();
	void Update(sf::RenderWindow &m_window, sf::View &m_view);
	void Initialize();
	sf::Sprite GetSprite();
	float ball_x;
	float GetDistance();
private:
	bool run_once;
	float m_distance;
	float randomvariable;


};