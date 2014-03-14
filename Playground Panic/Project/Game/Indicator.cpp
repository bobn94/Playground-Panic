#include "stdafx.h"
#include "Indicator.h"
#include "Sprite.h"

Indicator::Indicator(sf::Texture * indicator, sf::Color color)
{
	this->setTexture(*indicator);
	m_color = color;
	this->setColor(m_color);
	this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
}
Indicator::~Indicator()
{
}

void Indicator::Update(sf::Vector2f player_pos, sf::Vector2f enemy_pos, sf::Color color)
{
	m_color = color;
	this->setColor(color);
	this->setPosition(player_pos);
	
	float AngleX = enemy_pos.x - player_pos.x;
	float AngleY = enemy_pos.y - player_pos.y;

	float vectorLength = sqrt(AngleX * AngleX + AngleY * AngleY);

	if (vectorLength < 700.0f)
	{
		this->setColor(sf::Color(0, 0, 0, 0));
	}
	else
	{
		this->setColor(m_color);
	}

	sf::Vector2f dirVec = sf::Vector2f(player_pos.x - enemy_pos.x, player_pos.y - enemy_pos.y);
	float magSquare = std::sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));
	dirVec.x = (dirVec.x) / magSquare;
	float rotAngle = std::acos(dirVec.x) * (180 / 3.14f);

	if (this->getPosition().y > enemy_pos.y)
	{
		this->setRotation(180 + rotAngle);
	}
	else if (player_pos.x == enemy_pos.x && player_pos.y == enemy_pos.y)
	{
	}
	else
	{
		this->setRotation(180 - rotAngle);
	}
}

void Indicator::Initialize()
{

}
