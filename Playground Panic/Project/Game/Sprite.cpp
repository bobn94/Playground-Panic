#include "Sprite.h"
//#include "SpriteManager.h"

Sprite::Sprite(sf::Texture *texture, int x, int y, int width, int height):sf::Sprite(*texture){
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}
