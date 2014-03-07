#include "stdafx.h"
#include "Arrow.h"
#include "ParentUI.h"


Arrow::Arrow(sf::Texture * arrow, sf::Color color)
{
	this->setTexture(*arrow);
}
Arrow::~Arrow()
{

}
void Arrow::Update(sf::Vector2f enemy_pos)
{
	this->setPosition(enemy_pos);
	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
	this->setRotation(280.0f);
}

void Arrow::Initialize()
{
};
