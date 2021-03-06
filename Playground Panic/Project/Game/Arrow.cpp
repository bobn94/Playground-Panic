#include "stdafx.h"
#include "Arrow.h"
#include "ParentUI.h"


Arrow::Arrow(sf::Texture * arrow, sf::Color color)
{
	this->setTexture(*arrow);
	m_color = color;
	this->setColor(color);
	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
}
Arrow::~Arrow()
{

}
void Arrow::Update(sf::Vector2f enemy_pos, sf::Color color)
{
	m_color = color;
	this->setColor(color);
	this->setPosition(enemy_pos + sf::Vector2f(0.0f, -110.0f));
}

void Arrow::Initialize()
{
};
