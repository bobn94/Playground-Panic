#include "stdafx.h"
#include "Engine.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"
#include "Collider.h"

Engine::Engine(){
	m_player = nullptr;
	m_player_collider = nullptr;
	m_global_speed = 1;
	m_player_pss = 100;
}
Engine::~Engine(){

}
void Engine::Initialize(){
	
	if (!m_player_texture.loadFromFile("../data/textures/FemalePlayer.png"))
	{
		// Shit happened
	}
	m_player_texture.setSmooth(true);

	if (!m_projectile_texture.loadFromFile("../data/textures/TestPlayer.png"))
	{
		// Shit happened
	}
	m_projectile_texture.setSmooth(true);

	/*
	float recWidth = 20.0f, recHeight = 15.0f;
	rec = new sf::RectangleShape(sf::Vector2f(recWidth, recHeight));
	rec->setPosition(sf::Vector2f(600.0f, 300.0f));
	rec->setOrigin(sf::Vector2f(recWidth / 2, recHeight / 2));
	*/
	//rec->setTexture(&m_player_texture);

	m_player_sprite.setTexture(m_player_texture);
	m_player_sprite.setScale(0.4f, 0.4f);
	//m_player_sprite.setOrigin(m_player_sprite.getLocalBounds().width / 2, m_player_sprite.getLocalBounds().height / 2);
	m_player_sprite.setOrigin((m_player_sprite.getLocalBounds().width / 2) - 2, (m_player_sprite.getLocalBounds().height / 2) + 32);
	
	m_player_collider = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player = new PlayerObject(&m_player_sprite);
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
		while (mgr.IsRunning())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					mgr.isRunning = false;
				}
			}

			m_deltatime = deltaClock.restart().asSeconds() / 1000;

			/////////////////////////////////////////////////////////

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))// && m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss)
			{
				m_projectile_sprite.push_back(new sf::Sprite(m_projectile_texture));
				m_projectile_sprite[m_projectile_sprite.size() - 1]->setScale(0.7f, 0.7f);
				m_projectile.push_back(new ProjectileObject(m_projectile_sprite[m_projectile_sprite.size() - 1]));
				m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getPosition(), sf::Mouse::getPosition(m_window));
				
				/*m_projectile.push_back(new ProjectileObject(&m_projectile_sprite_temp, &m_projectile_texture, nullptr));
				m_projectile[0]->Initialize(m_player->GetSprite()->getPosition(), sf::Mouse::getPosition(m_window));
				m_projectile[0]->SetPosition(sf::Vector2f(200.0f, 200.0f));*/

				m_player_pst.restart();
				//m_player_pss = 10000000;
			}

			m_player->Update(m_deltatime, m_global_speed, sf::Mouse::getPosition(m_window));

			{
				auto it = m_projectile.begin();
				int i = 0;
				while (it != m_projectile.end())
				{
					m_projectile[i]->Update(m_deltatime, m_global_speed, sf::Mouse::getPosition(m_window));
					++it;
					i++;
				}
			}
			
			m_window.clear(sf::Color(0x11, 0x22, 0x33));
			
			m_player_sprite = *m_player->GetSprite();
			//m_player_sprite.setColor(sf::Color(0x00, 0xAA, 0xAA, 0x88));
			m_window.draw(m_player_sprite);
			
			for (int i = 0; i < m_projectile.size(); i++)
			{
				m_window.draw(*m_projectile[i]->GetSprite());
			}
			

			{
				//auto it = m_projectile.begin();
				//for (auto it = m_projectile.cbegin(); it != m_projectile.cend() /* not hoisted */; /* no increment */)
				for (int i = 0; i < m_projectile.size();)
				{
					auto it = m_projectile.begin();
					if ((m_projectile[i]->GetPosition().x < -100
						|| m_projectile[i]->GetPosition().y < -100
						|| m_projectile[i]->GetPosition().x > m_window.getSize().x + 100
						|| m_projectile[i]->GetPosition().y > m_window.getSize().y + 100
						)// && 1 == 0
						)
					{
						//it.erase(it++);
						//m_projectile.erase(++it);
						delete (*it)->GetSprite();
						delete (*it)->GetCollider();
						m_projectile.erase(it++);
					}
					else
					{
						//++it;
						i++;
					}
				}
				//while (it != m_projectile.end())
				//{
				//	if ((m_projectile[i]->GetPosition().x < -100
				//		|| m_projectile[i]->GetPosition().y < -100
				//		|| m_projectile[i]->GetPosition().x > m_window.getSize().x + 100
				//		|| m_projectile[i]->GetPosition().y > m_window.getSize().y + 100
				//		)// && 1 == 0
				//		)
				//	{
				//		delete (*it)->GetSprite();
				//		m_projectile.erase(it);
				//		//delete (*it);
				//	}
				//	++it;
				//	i++;
				//}
			}

/*
			auto it = m_projectile.begin();
			while (it != m_projectile.end())
			{
				m_window.draw(*m_projectile[0]->GetSprite());
			}*/
			m_window.setMouseCursorVisible(false);
			
			m_window.display();
		}

	//mgr.~StateManager();
}
void Engine::Cleanup(){
	/*if (m_player_texture)
	{
		delete m_player_texture;
	}*/

	if (m_player != nullptr)
	{
		delete m_player;
		m_player = nullptr;
	}
	if (m_player_collider != nullptr)
	{
		delete m_player_collider;
		m_player_collider = nullptr;
	}

	{
		auto it = m_projectile.begin();
		while (it != m_projectile.end())
		{
			delete (*it)->GetSprite();
			delete (*it)->GetCollider();
			delete (*it);
			++it;
		}
		m_projectile.clear();
		//m_projectile_sprite.clear();
		//m_projectile_collider.clear();
	}

	//delete mgr;
}