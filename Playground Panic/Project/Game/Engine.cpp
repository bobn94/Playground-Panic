#include "stdafx.h"
#include "Engine.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"
#include "SlowKid.h"
#include "Collider.h"
#include "CountdownTimer.h"
#include "HealthBar.h"
#include "Level.h"
#include <cmath>
#include <iostream>

Engine::Engine(){
	m_zoom = 1.4f;
}

Engine::~Engine(){

}

void Engine::Initialize(){
	srand((unsigned int) time(0));
	

	/*
	AnimatedSprite* spritePlayer = m_sprite_manager->Load("../data/animations/player_idle.txt");
	m_player->AddAnimation("Idle", spritePlayer);
	*/
}
void Engine::Run(){
	StateManager mgr;
		mgr.Attach(new MenuState());
		mgr.Attach(new GameStateA());
		mgr.Attach(new OptionsState());
		mgr.Attach(new UpgradeState());
		mgr.SetState("MenuState");
		mgr.isRunning = true;

		bool fullscreen = false;
		if (fullscreen)
		{
			m_window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Playground Panic", sf::Style::Fullscreen);
		}
		else
		{
			m_window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Playground Panic");
		}
		
		m_view.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
		m_view.zoom(m_zoom);
		m_window->setView(m_view);
		m_view.setCenter(-99.0f, -99.0f);

		while (mgr.IsRunning())
		{
			m_deltatime = deltaClock.restart().asSeconds() / 1000;

			//system("cls");
			
			mgr.Update(m_deltatime, *m_window, m_view, m_level);
		
			
		}

	//mgr.~StateManager();
}
void Engine::Cleanup(){
	/*if (m_player_texture)
	{
		delete m_player_texture;
	}*/

	

	//delete mgr;
}