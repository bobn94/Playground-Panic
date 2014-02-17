#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(){

}
Enemy::Enemy(sf::Sprite* sprite, float radius) : GameObject(sprite, radius){

}
bool Enemy::GetCanShoot(){
	return m_canShoot;
}
int Enemy::GetDirt(){
	return m_dirtLevel;
}
float Enemy::GetSpeed(){
	return m_speed;
}