// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace sf;

int _tmain(int argc, _TCHAR* argv[])
{
	RenderWindow window(VideoMode(1024, 640), "Meep");
	CircleShape shape(10.0f);
	CircleShape shape2(10.0f);
	CircleShape shape3(10.0f);
	Clock clocks;
	Time tid;
	float dir_x = 1.0f, dir_y = 1.0f, testFloat, testFloat2, dir_x2 = 1.0f, dir_y2 = 1.0f, testFloat3, testFloat4;
	int sekunder = 0, minuter = 0, timmar = 0, prev_sekunder = 0, red = 0, green = 0, blue = 255, change = 0;
	char current = 'R';
	shape2.setFillColor(Color(255,0,0,255));
	shape3.setFillColor(Color(0,0,255,255));
	window.setMouseCursorVisible(false);
	shape3.setPosition(500,500);
	shape2.setPosition(0,0);
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed){
				window.close();
			}
			else if(event.type == Event::KeyPressed){

			}
			else if(event.type == Event::KeyReleased){

			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		/*if(Mouse::isButtonPressed(Mouse::Button::Left)){
			window.setSize(Vector2u(1024, 640));
		}
		if(Mouse::isButtonPressed(Mouse::Button::Right)){
			window.setSize(Vector2u(1024, 240));
		}*/



		tid = clocks.getElapsedTime();
		sekunder = tid.asSeconds();
		if(sekunder == 60){
			minuter += 1;
			clocks.restart();
			sekunder = 0;
		}
		if(minuter == 60){
			timmar += 1;
			minuter = 0;
		}
		if(timmar == 24){
			timmar = 0;
		}
		
		dir_x = shape.getPosition().x - shape2.getPosition().x;
		dir_y = shape.getPosition().y - shape2.getPosition().y;
		dir_x2 = shape2.getPosition().x - shape3.getPosition().x;
		dir_y2 = shape2.getPosition().y - shape3.getPosition().y;
		if(sekunder != prev_sekunder){
			system("cls");
			if(timmar < 10){
				std::cout << 0 << timmar << ":";
			}
			else{
				std::cout << timmar << ":";
			}
			if(minuter < 10){
				std::cout << 0 << minuter << ":";
			}
			else{
				std::cout << minuter << ":";
			}
			if(sekunder < 10){
				std::cout << 0 << sekunder;
			}
			else{
				std::cout << sekunder << std::endl;
			}
			
			//std::cout << timmar << ":" << minuter << ":" << sekunder << std::endl;
			prev_sekunder = sekunder;
		}
		change += 1;
		if(change == 50){
			change = 0;
			if(current == 'R'){
				red += 1;
				blue -= 1;
				if(red == 255){
					current = 'G';
				}
			}
			else if(current == 'G'){
				green += 1;
				red -= 1;
				if(green == 255){
					current = 'B';
				
				}
			}
			else{
				green -= 1;
				blue += 1;
				if(blue == 255){
					current = 'R';
				}
			}
		}
		shape.setFillColor(Color(red,green,blue,255));

		window.clear(Color(0x11, 0x22, 0x33, 0xff));
		shape.setPosition(Mouse::getPosition().x - window.getPosition().x - 10, Mouse::getPosition().y - window.getPosition().y - 30);
		
		window.draw(shape);
		
		window.draw(shape2);
		window.draw(shape3);
		window.display();
		
		testFloat = shape2.getPosition().x +(0.00015f * dir_x);
		testFloat2 = shape2.getPosition().y  +(0.00015f * dir_y);
		testFloat3 = shape3.getPosition().x +(0.00015f * dir_x2);
		testFloat4 = shape3.getPosition().y  +(0.00015f * dir_y2);
		shape2.setPosition(testFloat, testFloat2);
		shape3.setPosition(testFloat3, testFloat4);
	}
	return 0;
}
/*
	StateManager
	InputManager
	AudioManager
	CollisionManager
	/EntityManager/
	DrawManager
	BulletManager
	EnemyManager

	SpriteManager
	Sprite
*/