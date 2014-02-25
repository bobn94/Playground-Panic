#include "stdafx.h"
#include "Engine.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"
#include "SlowKid.h"
#include "Collider.h"
#include "CountdownTimer.h"
#include "HealthBar.h"
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
		mgr.SetState("GameStateA");
		mgr.isRunning = true;
		
		
		sf::RenderWindow m_window(sf::VideoMode(1080, 720), "Playground Panic");
		
		m_view.setSize(sf::Vector2f(m_window.getSize().x, m_window.getSize().y));
		m_view.zoom(m_zoom);
		m_window.setView(m_view);
		while (mgr.IsRunning())
		{
			m_deltatime = deltaClock.restart().asSeconds() / 1000;
			
			mgr.Update(m_deltatime, m_window, m_view);
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