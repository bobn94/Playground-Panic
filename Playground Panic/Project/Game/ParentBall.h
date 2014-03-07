#pragma once
#include "stdafx.h"
#include "ParentUI.h"

class ParentBall : public sf::Sprite
{
public:
	ParentBall(sf::Texture * ball, sf::Color color);
	~ParentBall();
	void Update(sf::RenderWindow &m_window, sf::View &m_view);
	void Initialize();
	sf::Sprite GetSprite();
	float ball_x;
private:
	bool run_once;


};