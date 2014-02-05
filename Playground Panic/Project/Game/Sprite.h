#pragma once
#include "stdafx.h"
struct SDL_Texture;
struct SDL_Surface;

class Sprite: sf::Sprite{
	friend class DrawManager;
	friend class SpriteManager;

public:
	Sprite(sf::Texture *texture, int x, int y, int width, int height);
protected:
	sf::Texture texture;
	int m_x;
	int m_y;
	int m_height;
	int m_width;
};