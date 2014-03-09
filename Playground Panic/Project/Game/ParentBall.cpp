
#include "stdafx.h"
#include "ParentBall.h"

ParentBall::ParentBall(sf::Texture * ball, sf::Color color)
{
	this->setTexture(*ball);
	this->setColor(color);
	ball_x = 0;
}

ParentBall::~ParentBall()
{

}

void ParentBall::Update(sf::RenderWindow &window, sf::View &view)
{

	this->setPosition(view.getCenter().x - (view.getSize().x / 2) + this->getPosition().x, view.getCenter().y + 800 - (view.getSize().y / 2));
	this->move(0.01f, 0.0f);


};

void ParentBall::Initialize()
{

}

