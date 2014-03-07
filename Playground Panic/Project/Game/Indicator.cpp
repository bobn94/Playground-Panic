#include "stdafx.h"
#include "Indicator.h"
#include "Sprite.h"

Indicator::Indicator(sf::Texture * indicator, sf::Color color)
{
	this->setTexture(*indicator);
}
Indicator::~Indicator()
{
}

void Indicator::Update(sf::Vector2f player_pos)
{
	this->setPosition(player_pos);
	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
	this->setRotation(280.0f);
}

void Indicator::Initialize()
{

}
