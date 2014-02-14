#include "stdafx.h"
#include "Enemy.h"

bool Enemy::GetCanShoot(){
	return canShoot;
}
std::string Enemy::GetType(){
	return type;
}
int Enemy::GetDirt(){
	return dirtLevel;
}
int Enemy::GetSpeed(){
	return speed;
}