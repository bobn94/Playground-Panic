#include "stdafx.h"
#include "HealthBar.h"

HealthBar::HealthBar() 
{
}

HealthBar::HealthBar(sf::Sprite* sprite) : GameObject(sprite){

}
HealthBar::~HealthBar()
{
}

int HealthBar::Health()
{
	return 0;
}
void HealthBar::SetSprite()
{
}