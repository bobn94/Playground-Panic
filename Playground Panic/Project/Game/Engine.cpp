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
	m_player = nullptr;
	m_player_collider = nullptr;
	m_global_speed = 1;
	m_player_pss = 100;
	m_enemies_to_spawn = 0;
}
Engine::~Engine(){

}
void Engine::Initialize(){
	srand((unsigned int) time(0));
	if (!m_player_texture.loadFromFile("../data/textures/FemalePlayer.png"))
	{
		// Shit happened
	}
	m_player_texture.setSmooth(true);

	if (!m_projectile_texture.loadFromFile("../data/textures/Sponge.png"))
	{
		// Shit happened
	}
	m_projectile_texture.setSmooth(true);

	if (!m_slow_kid_texture.loadFromFile("../data/textures/SlowChild2.png"))
	{
		// Shit happened
	}
	m_projectile_texture.setSmooth(true);

	if (!m_framehealthbar_texture.loadFromFile("../data/textures/HealthBar2.png"))
	{
		// Shit happened
	}
	m_framehealthbar_texture.setSmooth(true);

	if (!m_healthbar_texture.loadFromFile("../data/textures/spr_healthbar.png"))
	{
		// Shit happened
	}
	m_healthbar_texture.setSmooth(true);

	if (!m_frameheatbar_texture.loadFromFile("../data/textures/HealthBar2.png"))
	{
		// Shit happened
	}
	m_frameheatbar_texture.setSmooth(true);

	if (!m_heatbar_texture.loadFromFile("../data/textures/spr_heatbar.png"))
	{
		// Shit happened
	}
	m_heatbar_texture.setSmooth(true);

	/*
	float recWidth = 20.0f, recHeight = 15.0f;
	rec = new sf::RectangleShape(sf::Vector2f(recWidth, recHeight));
	rec->setPosition(sf::Vector2f(600.0f, 300.0f));
	rec->setOrigin(sf::Vector2f(recWidth / 2, recHeight / 2));
	*/
	//rec->setTexture(&m_player_texture);

	m_player_sprite = new sf::Sprite(m_player_texture);
	m_player_sprite->setScale(0.4f, 0.4f);
	//m_player_sprite.setOrigin(m_player_sprite.getLocalBounds().width / 2, m_player_sprite.getLocalBounds().height / 2);
	m_player_sprite->setOrigin((m_player_sprite->getLocalBounds().width / 2) - 2, (m_player_sprite->getLocalBounds().height / 2) + 32);
	
	m_player_collider = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player = new PlayerObject(m_player_sprite, float(128.0f), m_player_collider);
	m_player->SetPosition(sf::Vector2f(200.0f, 200.0f));	


	m_healthbar_sprite = new sf::Sprite(m_healthbar_texture);
	m_heatbar_sprite = new sf::Sprite(m_heatbar_texture);
	//m_healthbar_sprite->setTexture(m_healthbar_texture);

	/*if
	(sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
	m_healthbar_sprite->setScale(m_healthbar/ 100, 1);
	}*/
	m_framehealthbar_sprite.setTexture(m_framehealthbar_texture);
	m_frameheatbar_sprite.setTexture(m_frameheatbar_texture);
	m_heatbar_sprite->setPosition(0, 40);
	m_frameheatbar_sprite.setPosition(0, 40);

	/*
	AnimatedSprite* spritePlayer = m_sprite_manager->Load("../data/animations/player_idle.txt");
	m_player->AddAnimation("Idle", spritePlayer);
	*/
	if (!m_font.loadFromFile("../data/fonts/arial.ttf"))
	{
		// Error...
	}

}
void Engine::Run(){
	StateManager mgr;
		mgr.Attach(new MenuState());
		mgr.Attach(new GameStateA());
		mgr.Attach(new OptionsState());
		mgr.SetState("GameStateA");
		
		m_enemies_to_spawn = 1;
		mgr.isRunning = true;
		sf::RenderWindow m_window(sf::VideoMode(1080, 720), "Playground Panic");
		m_timer = new CountdownTimer();
		m_timer->SetTime(0, 0, 5);
		m_timer->Reset();
		m_timer->Start();
		m_levelup_timer = new CountdownTimer();
		m_levelup_timer->SetTime(0, 0, 10);
		m_levelup_timer->Reset();
		m_levelup_timer->Start();
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
			m_timer->Update();
			m_levelup_timer->Update();
			
			
			if(m_player->GetCurrentHealth() > m_player->GetMaxHealth()){
				m_player->SetCurrentHealth(m_player->GetMaxHealth());
			}
			if(10 * m_player->GetCurrentHealth() <= m_player->GetMaxHealth() * 10)
			{
				m_healthbar_sprite->setTextureRect(sf::IntRect(0, 0, 10*m_player->GetCurrentHealth(), 40));	
			}
			if(10 * m_player->GetWeaponHeat() <= m_player->GetWeaponMaxHeat() * 10)
			{
				m_heatbar_sprite->setTextureRect(sf::IntRect(0, 0, 10*m_player->GetWeaponHeat(), 40));	
			}
			if(m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss){
				m_player->SetWeaponHeat(m_player->GetWeaponHeat() - 0.002f);
				if(m_player->GetWeaponHeat() < 0){
					m_player->SetWeaponHeat(0.0f);
				}
			}
			if(m_player->GetWeaponHeat() <= 0 && m_player->GetOverheat()){
				m_player->SetOverheat(false);
			}
			if(m_levelup_timer->Done()){
				m_enemies_to_spawn += 1;
				m_levelup_timer->Reset();
				m_levelup_timer->Start();
			}
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss && m_player->GetWeaponHeat() < m_player->GetWeaponMaxHeat() && !m_player->GetOverheat())
			{
				
					m_projectile_sprite.push_back(new sf::Sprite(m_projectile_texture));
					m_projectile_sprite[m_projectile_sprite.size() - 1]->setScale(0.4f, 0.4f);
					m_projectile.push_back(new ProjectileObject(m_projectile_sprite[m_projectile_sprite.size() - 1], float(32.0f), new Collider(m_projectile_sprite[m_projectile_sprite.size() - 1]->getPosition(), sf::Vector2f(64.0f, 32.0f))));
					m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getPosition(), sf::Mouse::getPosition(m_window));
				

				/*m_projectile.push_back(new ProjectileObject(&m_projectile_sprite_temp, &m_projectile_texture, nullptr));
				m_projectile[0]->Initialize(m_player->GetSprite()->getPosition(), sf::Mouse::getPosition(m_window));
				m_projectile[0]->SetPosition(sf::Vector2f(200.0f, 200.0f));*/

				m_player_pst.restart();
				//m_player_pss = 10000000;

				if(m_player->GetWeaponHeat() >= m_player->GetWeaponMaxHeat() - 1.0f){
					m_player->SetOverheat(true);
				}
				m_player->SetWeaponHeat(m_player->GetWeaponHeat() + 1.0f);
				
			}
			if (m_timer->Done()){
				for(int i = 0; i < m_enemies_to_spawn; i++){
					m_slow_kid_sprite.push_back(new sf::Sprite(m_slow_kid_texture));
					m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->setScale(0.5f, 0.5f);
					m_slow_kid.push_back(new SlowKid(m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]/*, new Collider(sf::Vector2f((rand()%800 + 100 - m_window.getPosition().x), (rand()%500 + 100 - m_window.getPosition().y)), sf::Vector2f(128.0f, 128.0f)))*/, float(32.0f), rand()%4+1));
					m_slow_kid[m_slow_kid.size() - 1]->SetPosition(sf::Vector2f(rand()%800 + 100, rand()%500+100));
					m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->setOrigin(64.0f, 64.0f);
					m_timer->Reset();
					m_timer->Start();
				}
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

			{
				auto it = m_slow_kid.begin();
				int i = 0;
				while (it != m_slow_kid.end())
				{
					m_slow_kid[i]->Update(m_deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_player->GetPosition());
					++it;
					i++;
				}
			}

			 if (m_slow_kid.size() != 0 && m_projectile.size() != 0)
			{
				auto it = m_slow_kid.begin();
				for (int i = 0; i < m_slow_kid.size();)
					{
						int Destroyed = 0;
				for (int j = 0; j < m_projectile.size();)
					{
					if (Collisions->Overlap(m_slow_kid[i]->GetSprite()->getPosition(), m_projectile[j]->GetSprite()->getPosition(), m_slow_kid[i]->m_radius, m_projectile[j]->m_radius))
						{
							m_projectile[j]->SetPosition(sf::Vector2f(-999.0f, -999.0f));

							m_slow_kid[i]->m_dirtLevel -= 1;
							if (m_slow_kid[i]->m_dirtLevel <= 0)
							{
								delete (*it)->GetSprite();
								delete (*it)->GetCollider();
								m_slow_kid.erase(it);
								Destroyed = 1;

								/*std::cout << "Dirtlvl: ";
								for (int p = 0; p < m_slow_kid.size(); p++)
								{
									std::cout << m_slow_kid[p]->m_dirtLevel << ", ";
								}

								std::cout << std::endl;
								*/
							}
							j++;
						}
					else
					{
						j++;
					}
					if (Destroyed == 1)
					{
						i--;
						j = 9999999999999;


					}
				}
				i++;
			}
		}

			
			m_window.clear(sf::Color(0x11, 0x22, 0x33));
			
			*m_player_sprite = *m_player->GetSprite();
			//m_player_sprite.setColor(sf::Color(0x00, 0xAA, 0xAA, 0x88));
			m_window.draw(*m_player_sprite);
			
			for (int i = 0; i < m_projectile.size(); i++)
			{
				m_window.draw(*m_projectile[i]->GetSprite());
			}
			for (int i = 0; i < m_slow_kid.size(); i++)
			{
				m_window.draw(*m_slow_kid[i]->GetSprite());
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
			//m_window.setMouseCursorVisible(false);

			m_window.draw(*m_healthbar_sprite);
			
			m_window.draw(m_framehealthbar_sprite);

			m_window.draw(*m_heatbar_sprite);
			
			m_window.draw(m_frameheatbar_sprite);
			
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
	if (m_healthbar_sprite != nullptr)
	{
		delete m_healthbar_sprite;
		m_healthbar_sprite = nullptr;
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