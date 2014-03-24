#include "stdafx.h"
#include "ParentUI.h"
#include "Arrow.h"
#include "ParentBall.h"
#include "SlowKid.h"
#include "Indicator.h"
#include "SpriteObject.h"
#include <random>
#include <iostream>

ParentUI::ParentUI(sf::Texture *arrow, sf::Texture *indicator, sf::Texture *ball, sf::View *view)
: SpriteObject(arrow)
{
	m_color = sf::Color(rand() % 256, rand() % 256, rand() % 256, 255);

	m_arrow = new Arrow(arrow, m_color);
	m_indicator = new Indicator(indicator, m_color);
	m_parent_ball = new ParentBall(ball, m_color, view);
}

ParentUI::~ParentUI()
{
	if (m_arrow != nullptr)
	{
		delete m_arrow;
		m_arrow = nullptr;
	}
	if (m_indicator != nullptr)
	{
		delete m_indicator;
		m_indicator = nullptr;
	}
	if (m_parent_ball != nullptr)
	{
		delete m_parent_ball;
		m_parent_ball = nullptr;
	}
}
void ParentUI::Update(float deltatime, float global_speed, sf::RenderWindow &window, sf::View &view, sf::Vector2f player_pos, sf::Vector2f enemy_pos)
{

	m_arrow->Update(enemy_pos, m_color);
	m_indicator->Update(player_pos, enemy_pos, m_color);
	m_parent_ball->Update(deltatime, global_speed, window, view, m_color);
}

void ParentUI::Draw(sf::RenderWindow &window)
{
	window.draw(*m_arrow);
	window.draw(*m_indicator);
	window.draw(*m_parent_ball);
}

void ParentUI::Initialize()
{

}

Arrow ParentUI::GetArrow()
{
	return *m_arrow;
}

Indicator ParentUI::GetIndicator()
{
	return *m_indicator;
}

ParentBall ParentUI::GetBall()
{
	return *m_parent_ball;
}

sf::Color ParentUI::GetColor()
{
	return m_color;
}

void ParentUI::SetColor(sf::Color color)
{
	m_color = color;
}