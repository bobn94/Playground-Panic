
#include "stdafx.h"
#include "ParentBall.h"

ParentBall::ParentBall(sf::Texture * ball, sf::Color color, sf::View *view)
{
	m_distance = 0.0f;
	this->setTexture(*ball);
	m_color = color;
	randomvariable = rand() % 1500000;
	m_speed = 1500000.0f + randomvariable;
	this->setColor(color);
	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
	this->setPosition(view->getCenter().x - (view->getSize().x / 2), view->getCenter().y - 60 + (view->getSize().y / 3));
	//ball_x = 0;
}

ParentBall::~ParentBall()
{

}

void ParentBall::Update(float deltatime, float global_speed, sf::RenderWindow &window, sf::View &view, sf::Color color)
{
	m_color = color;
	this->setColor(color);
	this->setScale(0.643f, 0.643f);
	m_distance += 0.01f * m_speed * deltatime * global_speed;

	if (m_distance <= 880.0f)
	{
		this->setPosition(view.getCenter().x - (view.getSize().x / 2) + m_distance, view.getCenter().y - 52 + (view.getSize().y / 2));
	}
	else
	{
		this->setPosition(view.getCenter().x - (view.getSize().x / 2) + 880, view.getCenter().y - 52 + (view.getSize().y / 2));
	}
};

void ParentBall::Initialize()
{

}

float ParentBall::GetDistance()
{
	return m_distance;
}

