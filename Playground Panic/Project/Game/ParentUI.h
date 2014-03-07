#pragma once

#include "stdafx.h"
#include "SlowKid.h"
#include "SpriteObject.h"
#include <iostream>

class Arrow;
class ParentBall;
class Indicator;

class ParentUI : public SpriteObject

{
public:
	ParentUI::ParentUI(sf::Texture *arrow, sf::Texture *indicator, sf::Texture *ball);
	~ParentUI();
	void Update(sf::RenderWindow &window, sf::View &view, sf::Vector2f player_pos, sf::Vector2f enemy_pos);

	void Draw(sf::RenderWindow &window);

	Arrow GetArrow();

	Indicator GetIndicator();

	ParentBall GetBall();

	void Initialize();
	//std::map<sf::Sprite*, SlowKid*>mm_Special_kids;

protected:
	sf::Color m_color;
	Arrow * m_arrow;
	ParentBall* m_parent_ball;
	Indicator* m_indicator;
	SlowKid *m_slow_kid;


};