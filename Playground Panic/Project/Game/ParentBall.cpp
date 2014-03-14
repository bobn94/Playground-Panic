
#include "stdafx.h"
#include "ParentBall.h"

ParentBall::ParentBall(sf::Texture * ball, sf::Color color, sf::View *view)
{
	m_distance = 0.0f;
	this->setTexture(*ball);
	m_color = color;
	this->setColor(color);
	this->setPosition(view->getCenter().x - (view->getSize().x / 2), view->getCenter().y - 60 + (view->getSize().y / 2));
	//ball_x = 0;
	//randomvariable = ( rand() % 2)/1000;
}

ParentBall::~ParentBall()
{

}

void ParentBall::Update(sf::RenderWindow &window, sf::View &view, sf::Color color)
{
	m_color = color;
	this->setColor(color);
	m_distance += 0.01f;
	if (m_distance <= 860.0f)
	{
		this->setPosition(view.getCenter().x - (view.getSize().x / 2) + m_distance, view.getCenter().y - 127 + (view.getSize().y / 2));
	}
	else
	{
		this->setPosition(view.getCenter().x - (view.getSize().x / 2) + 860, view.getCenter().y - 120 + (view.getSize().y / 2));
	}
};

void ParentBall::Initialize()
{

}

float ParentBall::GetDistance()
{
	return m_distance;
}

