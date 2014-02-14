#include "stdafx.h"
#include "Engine.h"
#include "GameObject.h"
#include "PlayerObject.h"

Engine::Engine(){
	m_player = nullptr;
	m_global_speed = 70000;
}
Engine::~Engine(){

}
void Engine::Initialize(){
	
	//Temporary
	
	if (!m_player_texture.loadFromFile("../data/textures/FemalePlayer.png"))
	{
		// Shit happened
	}
	m_player_texture.setSmooth(true);
	float recWidth = 20.0f, recHeight = 15.0f;
	rec = new sf::RectangleShape(sf::Vector2f(recWidth, recHeight));
	rec->setPosition(sf::Vector2f(600.0f, 300.0f));
	rec->setOrigin(sf::Vector2f(recWidth / 2, recHeight / 2));
	//rec->setTexture(&m_player_texture);
	//m_player_sprite->setTexture(&m_player_texture);

	m_player_sprite.setTexture(m_player_texture);

	//Collider* colliderPlayer = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player_sprite.setOrigin(m_player_sprite.getLocalBounds().width / 2, m_player_sprite.getLocalBounds().height / 2);
	m_player = new PlayerObject(&m_player_sprite, &m_player_texture, nullptr);
	m_player->SetPosition(sf::Vector2f(200.0f, 200.0f));
	



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
		mgr.SetState("MenuState");

		mgr.isRunning = true;
		sf::RenderWindow m_window(sf::VideoMode(1080, 720), "Playground Panic");
		while(mgr.IsRunning())
		{
			sf::Event event;
			while(m_window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
				{
					mgr.isRunning = false;
				}
			}
			
			m_deltatime = deltaClock.restart().asSeconds() / 1000;

			m_player->Update(m_deltatime, m_global_speed, sf::Mouse::getPosition(m_window));
			
			
			m_window.clear(sf::Color(0x11, 0x22, 0x33));
			
			m_player_sprite = *m_player->GetSprite();
			m_window.draw(m_player_sprite);
			
			m_window.display();
		}
}
void Engine::Cleanup(){
	/*if (m_player_texture)
	{
		delete m_player_texture;
	}*/
}