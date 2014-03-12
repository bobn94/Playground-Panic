
#include "stdafx.h"
#include "ParentBall.h"

ParentBall::ParentBall(sf::Texture * ball, sf::Color color, sf::View *view)
{
	m_distance = 0.0f;
	this->setTexture(*ball);
	this->setColor(color);
	this->setPosition(view->getCenter().x - (view->getSize().x / 2), view->getCenter().y - 60 + (view->getSize().y / 2));
	//ball_x = 0;
	//randomvariable = ( rand() % 2)/1000;
}

ParentBall::~ParentBall()
{

}

void ParentBall::Update(sf::RenderWindow &window, sf::View &view)
{
	std::cout << this->getPosition().x << ", " << 
		this->getPosition().y << " - " << (sf::Vector2f(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y + 800 - (view.getSize().y / 2))
		- this->getPosition()).x << ", " << (sf::Vector2f(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y + 800 - (view.getSize().y / 2))
		- this->getPosition()).y << std::endl;
	/*this->setPosition(
		this->getPosition() + sf::Vector2f(1.0f, 0.0f) 
		+ (sf::Vector2f(view.getCenter().x - (view.getSize().x / 2), view.getCenter().y - 60 + (view.getSize().y / 2))
		- this->getPosition())
		);*/
	
	m_distance += 0.70f;//+ randomvariable;
	if(m_distance <= 700.0f)
	{
	this->setPosition(view.getCenter().x - (view.getSize().x / 2) + m_distance, view.getCenter().y + 800 - (view.getSize().y / 2));
	}
	else {
		this->setPosition(view.getCenter().x - (view.getSize().x / 2) + 700, view.getCenter().y + 800 - (view.getSize().y / 2));
	}
//this->move(0.1f, 0.0f);
};

void ParentBall::Initialize()
{

}

float ParentBall::GetDistance()
{
	return m_distance;
}

