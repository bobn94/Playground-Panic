// SpriteObject.h

#pragma once

#include "GameObject.h"
#include <map>
#include <string>
#include "stdafx.h"

//class Sprite;
class Collider;

class SpriteObject : public GameObject
{
public:
	SpriteObject(sf::Texture* texture, std::string filepath = "");
	~SpriteObject();
	void Update(float deltatime);
private:

};