#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <string>

class Enemy : GameObject{
public:
	bool GetCanShoot();
	std::string GetType();
	int GetDirt();
	int GetSpeed();
private:
	bool canShoot;
	std::string type;
	int dirtLevel;
	int speed;
};