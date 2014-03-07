#include "stdafx.h"
#include "HealthBar.h"

HealthBar::HealthBar() 
{
}

HealthBar::HealthBar(sf::Texture* texture) : GameObject(texture)
{
}
HealthBar::~HealthBar()
{
	if (m_sprite != nullptr)
	{
		delete m_sprite;
	}
}

int HealthBar::Health()
{
	return 0;
}
void HealthBar::SetSprite()
{
}