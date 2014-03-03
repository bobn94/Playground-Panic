
#include "stdafx.h"
#include <iostream>
#include "GameObject.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"
#include "SlowKid.h"
#include "Collider.h"
#include "CountdownTimer.h"
#include "HealthBar.h"
#include <cmath>
#include <iostream>
#include "GameStateA.h"
//#include "Level.h"


GameStateA::GameStateA(){
	
	m_player = nullptr;
	m_player_collider = nullptr;
	m_global_speed = 1.0f;
	m_player_pss = 100;
	m_enemies_to_spawn = 0;
};


bool GameStateA::Enter() {

	if (!m_background_texture.loadFromFile("../data/textures/background.png"))
	{
		// This shit shouldn't happen
	}
	m_background_texture.setSmooth(true);
	
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

	if (!m_crosshair_texture.loadFromFile("../data/textures/crosshair.png"))
	{
		// Shit happened
	}
	m_crosshair_texture.setSmooth(true);

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

	if (!m_heatbar_texture.loadFromFile("../data/textures/spr_healthbar.png"))
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

	m_background_sprite.setTexture(m_background_texture);

	m_player_sprite = new sf::Sprite(m_player_texture);
	m_player_sprite->setScale(0.7f, 0.7f);
	//m_player_sprite.setOrigin(m_player_sprite.getLocalBounds().width / 2, m_player_sprite.getLocalBounds().height / 2);
	m_player_sprite->setOrigin((m_player_sprite->getLocalBounds().width / 2) - 2, (m_player_sprite->getLocalBounds().height / 2) + 32);
	
	m_player_collider = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player = new PlayerObject(m_player_sprite, float(128.0f), m_player_collider);
	m_player->SetPosition(sf::Vector2f(2490.0f, 900.0f));

	m_healthbar_sprite = new sf::Sprite(m_healthbar_texture);
	m_framehealthbar_sprite.setTexture(m_framehealthbar_texture);

	m_healthbar_sprite = new sf::Sprite(m_healthbar_texture);
	m_heatbar_sprite = new sf::Sprite(m_heatbar_texture);

	m_crosshair_sprite = new sf::Sprite(m_crosshair_texture);

	m_framehealthbar_sprite.setTexture(m_framehealthbar_texture);
	m_frameheatbar_sprite.setTexture(m_frameheatbar_texture);
	m_heatbar_sprite->setPosition(0, 40);
	m_frameheatbar_sprite.setPosition(0, 40);

	m_enemies_to_spawn = 1;

	m_timer = new CountdownTimer();
	m_timer->SetTime(0, 0, 1);
	m_timer->Reset();
	m_timer->Start();

	m_levelup_timer = new CountdownTimer();
	m_levelup_timer->SetTime(0, 0, 15);
	m_levelup_timer->Reset();
	m_levelup_timer->Start();

	return true;
};

bool GameStateA::Update(float deltatime, sf::RenderWindow &m_window, sf::View &m_view)
{
	m_timer->Update();
	
	sf::Vector2f m_view_position = sf::Vector2f(-99.0f, -99.0f);

	if (m_view.getCenter().x == -99 && m_view.getCenter().y == -99)
	{
		//std::cout << "Setting view to the player" << std::endl;
		m_view.setCenter(m_player->GetPosition());
	}
	else if ((m_view.getCenter().x - (m_view.getSize().x / 2)) / 1.4f <= 1
		|| (m_view.getCenter().x + (m_view.getSize().x / 2)) / 1.4f >= (m_background_sprite.getGlobalBounds().width / 1.4f) - 1
		|| (m_view.getCenter().y - (m_view.getSize().y / 2)) / 1.4f <= 1
		|| (m_view.getCenter().y + (m_view.getSize().y / 2)) / 1.4f >= (m_background_sprite.getGlobalBounds().height / 1.4f) - 1)
	{
		if ((m_view.getCenter().x - (m_view.getSize().x / 2)) / 1.4f <= 1
			|| (m_view.getCenter().x + (m_view.getSize().x / 2)) / 1.4f >= (m_background_sprite.getGlobalBounds().width / 1.4f) - 1)
		{
			//std::cout << "Setting m_view_position.x to m_view's center x" << std::endl;
			//m_view.setCenter(m_view.getCenter().x, m_player->GetPosition().y);
			m_view_position.x = m_view.getCenter().x;
		}
		if ((m_view.getCenter().y - (m_view.getSize().y / 2)) / 1.4f <= 1
			|| (m_view.getCenter().y + (m_view.getSize().y / 2)) / 1.4f >= (m_background_sprite.getGlobalBounds().height / 1.4f) - 1)
		{
			//std::cout << "Setting m_view_position.y to m_view's center y" << std::endl;
			//m_view.setCenter(m_player->GetPosition().x, m_view.getCenter().y);
			m_view_position.y = m_view.getCenter().y;
		}
		
		//Bug-checks
		if (m_view_position.x < -98)
		{
			//std::cout << "m_view_position.x < -50" << std::endl;
			m_view.setCenter(m_player->GetPosition().x, m_view_position.y);
		}
		else if (m_view_position.y < -98)
		{
			//std::cout << "m_view_position.y < -50" << std::endl;
			m_view.setCenter(m_view_position.x, m_player->GetPosition().y);
		}
		else
		{
			//std::cout << "Setting view to m_view_position" << std::endl;
			m_view.setCenter(m_view_position);
		}
	}
	else
	{
		//std::cout << "Setting view to the player" << std::endl;
		m_view.setCenter(m_player->GetPosition());
	}
	//std::cout << "m_view_position = " << m_view_position.x << ", " << m_view_position.y << std::endl;
	//std::cout << "Current position of the view: " << m_view.getCenter().x << ", " << m_view.getCenter().y << std::endl;
	//std::cout << "Current position of the player: " << m_player->GetPosition().x << ", " << m_player->GetPosition().y << std::endl;

	if (m_player->GetPosition().x > m_view.getSize().x / 2 
		&& m_player->GetPosition().x + m_view.getSize().x / 2 < m_background_sprite.getGlobalBounds().width)
	{
		//std::cout << "Setting view to the player's x" << std::endl;
		//float meh = m_player->GetPosition().x + m_view.getSize().x / 2, meh2 = m_background_sprite.getGlobalBounds().width;
		//std::cout << meh << " " << meh2 << std::endl;
		m_view.setCenter(m_player->GetPosition().x, m_view.getCenter().y);
	}

	if (m_player->GetPosition().y > m_view.getSize().y / 2
		&& m_player->GetPosition().y + m_view.getSize().y / 2 < m_background_sprite.getGlobalBounds().height)
	{
		//std::cout << "Setting view to the player's x" << std::endl;
		//float meh = m_player->GetPosition().y + m_view.getSize().y / 2, meh2 = m_background_sprite.getGlobalBounds().height;
		//std::cout << meh << " " << meh2 << std::endl;
		m_view.setCenter(m_view.getCenter().x, m_player->GetPosition().y);
	}

	//if (m_player->GetPosition().x > m_view.getCenter().x 
	//	&& m_player->GetPosition().x > (m_background_sprite.getGlobalBounds().width / 1.4f) - (m_view.getSize().x / 2) 
	//	|| m_player->GetPosition().x > m_view.getCenter().x 
	//	&& m_player->GetPosition().x < (m_background_sprite.getGlobalBounds().width / 1.4f) - (m_view.getSize().x / 2))
	//	//(m_player->GetPosition().x < m_view.getSize().x / 2
	//	//&& m_player->GetPosition().x < (m_background_sprite.getTexture()->getSize().x / 1.4f) - ((m_background_sprite.getGlobalBounds().width / 1.4f) - m_player->GetPosition().x)) 
	//	//|| m_player->GetPosition().x > m_view.getSize().x / 2 
	//	//&& m_player->GetPosition().x <= (m_background_sprite.getGlobalBounds().width / 1.4f) - ((m_background_sprite.getGlobalBounds().width / 1.4f) - m_player->GetPosition().x)
	//	//) //Fix other corner
	//{
	//	std::cout << "Setting view to the player's x" << std::endl;
	//	m_view.setCenter(m_player->GetPosition().x, m_view.getCenter().y);
	//}
	//if (m_player->GetPosition().y > m_view.getCenter().y && m_player->GetPosition().y > (m_background_sprite.getGlobalBounds().height / 1.4f) - (m_view.getSize().y / 2) || m_player->GetPosition().y > m_view.getCenter().y && m_player->GetPosition().y < (m_background_sprite.getGlobalBounds().height / 1.4f) - (m_view.getSize().y / 2))
	//{
	//	std::cout << "Setting view to the player's y" << std::endl;
	//	m_view.setCenter(m_view.getCenter().x, m_player->GetPosition().y);
	//}
	/*if ()
	{
		m_view.setCenter(m_player->GetPosition().x, m_view.getCenter().y);
	}
	if ()
	{
		m_view.setCenter(m_view.getCenter().x, m_player->GetPosition().y);
	}*/



	/*std::cout << "Current position of the view: " << m_view.getCenter().x << ", " << m_view.getCenter().y << std::endl;
	std::cout << "Current position of the player: " << m_player->GetPosition().x << ", " << m_player->GetPosition().y << std::endl;*/

	m_window.setView(m_view);
			
	m_mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window)) + static_cast<sf::Vector2f>(m_view.getCenter()) - static_cast<sf::Vector2f>((m_view.getSize() / 2.0f)) / 1.4f;
			
	m_healthbar_sprite->setPosition(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - (m_view.getSize().y / 2));
	m_framehealthbar_sprite.setPosition(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - (m_view.getSize().y / 2));
	m_heatbar_sprite->setPosition(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y + 40 - (m_view.getSize().y / 2));
	m_frameheatbar_sprite.setPosition(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y + 40 - (m_view.getSize().y / 2));

	if(m_player->GetCurrentHealth() > m_player->GetMaxHealth())
	{
		m_player->SetCurrentHealth(m_player->GetMaxHealth());
	}
	if(10 * m_player->GetCurrentHealth() <= m_player->GetMaxHealth() * 10)
	{
		m_healthbar_sprite->setTextureRect(sf::IntRect(0, 0, 10*m_player->GetCurrentHealth(), 40));	
	}

	if (10 * m_player->GetWeaponHeat() <= m_player->GetWeaponMaxHeat() * 10)
	{
		m_heatbar_sprite->setTextureRect(sf::IntRect(0, 0, 10 * m_player->GetWeaponHeat(), 40));
	}
	
	if (m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss)
		{
			m_player->SetWeaponHeat(m_player->GetWeaponHeat() - 0.003f);
			if (m_player->GetWeaponHeat() < 0)
			{
				m_player->SetWeaponHeat(0.0f);
			}
		}

	if (m_player->GetWeaponHeat() <= 0 && m_player->GetOverheat()){
		m_player->SetOverheat(false);
	}
	if (m_levelup_timer->Done())
	{
		if (m_enemies_to_spawn < 10)
		{
			m_enemies_to_spawn += 1;
			m_levelup_timer->Reset();
			m_levelup_timer->Start();
			std::cout << m_enemies_to_spawn << std::endl;
		}
		else
		{
			m_levelup_timer->Stop();
		}
	}

	if(m_player->GetCurrentHealth() == m_player->GetMaxHealth())
	{
		return false;
	}

	if (m_player->GetWeaponHeat() >= m_player->GetWeaponMaxHeat() - 1.0f)
	{
		m_player->SetOverheat(true);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss && !m_player->GetOverheat())
	{
		m_projectile_sprite.push_back(new sf::Sprite(m_projectile_texture));
		m_projectile_sprite[m_projectile_sprite.size() - 1]->setScale(0.6f, 0.6f);
		m_projectile.push_back(new ProjectileObject(m_projectile_sprite[m_projectile_sprite.size() - 1], float(8.0f), new Collider(m_projectile_sprite[m_projectile_sprite.size() - 1]->getPosition(), sf::Vector2f(16.0f, 16.0f))));
		m_projectile[m_projectile.size() - 1]->SetPosition(m_player->GetSprite()->getTransform().transformPoint(128.0f, 10.0f)); //128.0f, 10.0f
		//m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getTransform().transformPoint(128.0f, 250.0f), m_mouse_position, m_view.getCenter() - m_view.getSize() / 2.0f);
		m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getTransform().transformPoint(128.0f, 250.0f), m_mouse_position, m_player->GetPosition());

		/*m_projectile.push_back(new ProjectileObject(&m_projectile_sprite_temp, &m_projectile_texture, nullptr));
		m_projectile[0]->Initialize(m_player->GetSprite()->getPosition(), sf::Mouse::getPosition(m_window));
		m_projectile[0]->SetPosition(sf::Vector2f(200.0f, 200.0f));*/

		m_player_pst.restart();
		//m_player_pss = 10000000;

		if (m_player->GetWeaponHeat() >= m_player->GetWeaponMaxHeat() - 1.0f)
		{
			m_player->SetOverheat(true);
		}
		m_player->SetWeaponHeat(m_player->GetWeaponHeat() + 1.0f);
	}

	if (m_timer->Done())
	{
		for (int i = 0; i < m_enemies_to_spawn; i++)
		{
			m_slow_kid_sprite.push_back(new sf::Sprite(m_slow_kid_texture));
			m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->setScale(0.6f, 0.6f);
			m_slow_kid.push_back(new SlowKid(m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]/*, new Collider(sf::Vector2f((rand()%800 + 100 - m_window.getPosition().x), (rand()%500 + 100 - m_window.getPosition().y)), sf::Vector2f(128.0f, 128.0f)))*/, float(32.0f), rand() % 4 + 3));
			m_slow_kid[m_slow_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background_sprite.getGlobalBounds().width + 100, rand() % (int)m_background_sprite.getGlobalBounds().height + 100));
			m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->setOrigin(m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->getLocalBounds().width / 2, m_slow_kid_sprite[m_slow_kid_sprite.size() - 1]->getLocalBounds().height / 2);
			m_timer->Reset();
			m_timer->Start();
			//std::cout << "Slow Kid created - " << m_slow_kid.size() << std::endl;
		}
	}

	m_player->Update(deltatime, m_global_speed, m_mouse_position);

	{
		auto it = m_projectile.begin();
		int i = 0;
		while (it != m_projectile.end())
		{
			m_projectile[i]->Update(deltatime, m_global_speed, sf::Mouse::getPosition(m_window));
			++it;
			i++;
		}
	}

	{
		for(int i = 0; i < m_slow_kid.size(); i++)
		{
			for(int j = 0; j < m_slow_kid.size(); j++)
			{
				if(i != j)
				{
					sf::Vector2f offset;
					if(Collisions->Overlap(m_slow_kid[i]->GetPosition(), m_slow_kid[j]->GetPosition(), m_slow_kid[i]->m_radius, m_slow_kid[j]->m_radius, offset))
					{
						if(offset.x > 0 && offset.y > 0)
						{
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + offset / 8.0f);
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x <= 0 && offset.y <= 0)
						{
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + offset * 8.0f);
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x > 0 && offset.y <= 0)
						{
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f((offset.x / 8.0f), (offset.y * 8.0f)));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x <= 0 && offset.y > 0)
						{
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f((offset.x * 8.0f), (offset.y / 8.0f)));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						
						/*if(offset.x >= 0 && offset.y >= 0){
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f(1.0f, 1.0f));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x < 0 && offset.y >= 0){
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f(-1.0f, 1.0f));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x < 0 && offset.y < 0){
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f(-1.0f, -1.0f));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}
						else if(offset.x >= 0 && offset.y < 0){
							m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + sf::Vector2f(1.0f, -1.0f));
							m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
						}*/
					}
					
					
				}
			}
			/*
						m_slow_kid[j]->GetSprite()->setPosition(m_slow_kid[j]->GetSprite()->getPosition() + offset / 4.0f);
						m_slow_kid[j]->SetPosition(m_slow_kid[j]->GetSprite()->getPosition());
			*/
			m_slow_kid[i]->Update(deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_player->GetPosition());
		}
		
			
			
		
	}

	if (m_slow_kid.size() != 0 && m_projectile.size() != 0)
	{
		for (int i = m_slow_kid.size() - 1; i >= 0; i--)
		{
			for (int j = m_projectile.size() - 1; j >= 0; j--)
			{
				if (Collisions->Overlap(m_slow_kid[i]->GetPosition(), m_projectile[j]->GetPosition(), m_slow_kid[i]->m_radius, m_projectile[j]->m_radius))
				{
					//std::cout << m_slow_kid[i]->GetPosition().x << "-" << m_slow_kid[i]->GetPosition().y << " " << m_projectile[j]->GetPosition().x << "-" << m_projectile[j]->GetPosition().y << std::endl;
					//m_projectile[j]->SetPosition(sf::Vector2f(-999.0f, -999.0f));
					//std::cout << "Before: " << m_slow_kid.size() << " " << m_projectile.size() << " After: ";

					//delete m_projectile[j]->GetSprite();
					//delete m_projectile[j]->GetCollider();
					m_projectile.erase(m_projectile.begin() + j);

					m_slow_kid[i]->m_dirtLevel -= 1;
					if (m_slow_kid[i]->m_dirtLevel <= 0)
					{
						//delete m_slow_kid[i]->GetSprite();
						//delete m_slow_kid[i]->GetCollider();
						m_slow_kid.erase(m_slow_kid.begin() + i);
					}
					//std::cout << m_slow_kid.size() << " " << m_projectile.size() << std::endl;
					//std::cout << i << " " << j << std::endl;
				}
			}

		}
	}
	{
		//auto it = m_projectile.begin();
		//for (auto it = m_projectile.cbegin(); it != m_projectile.cend() /* not hoisted */; /* no increment */)
		for (int i = 0; i < m_projectile.size();)
		{
			auto it = m_projectile.begin();
			if ((m_projectile[i]->GetPosition().x < m_player->GetPosition().x - 800
				|| m_projectile[i]->GetPosition().y < m_player->GetPosition().y - 600
				|| m_projectile[i]->GetPosition().x > m_player->GetPosition().x + 800
				|| m_projectile[i]->GetPosition().y > m_player->GetPosition().y + 600
				)// && 1 == 0
				)
			{
				//it.erase(it++);
				//m_projectile.erase(++it);
				//delete (*it)->GetSprite();
				//delete (*it)->GetCollider();
				m_projectile.erase(it++);
			}
			else
			{
				i++;
			}
		}
	}

	m_window.clear(sf::Color(18, 45, 0));
	m_window.draw(m_background_sprite);
			
	for (int i = 0; i < m_projectile.size(); i++)
	{
		m_window.draw(*m_projectile[i]->GetSprite());
	}
	for (int i = 0; i < m_slow_kid.size(); i++)
	{
		m_window.draw(*m_slow_kid[i]->GetSprite());
	}
			
	sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					
					m_window.close();
					
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					
					return false;
				
				}
		
			}
			

/*
	auto it = m_projectile.begin();
	while (it != m_projectile.end())
	{
		m_window.draw(*m_projectile[0]->GetSprite());
	}*/
	//m_window.setMouseCursorVisible(false);
			

	*m_player_sprite = *m_player->GetSprite();
	//m_player_sprite.setColor(sf::Color(0x00, 0xAA, 0xAA, 0x88));
	m_window.draw(*m_player_sprite);

	m_window.draw(*m_heatbar_sprite);
	m_window.draw(m_frameheatbar_sprite);

	m_window.draw(*m_healthbar_sprite);
	m_window.draw(m_framehealthbar_sprite);
			
	m_window.display();

	return true;	
};

void GameStateA::Exit() {
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
			//delete (*it)->GetSprite();
			//delete (*it)->GetCollider();
			delete (*it);
			++it;
		}
		m_projectile.clear();
		//m_projectile_sprite.clear();
		//m_projectile_collider.clear();
	}

	{
		auto it = m_slow_kid.begin();
		while (it != m_slow_kid.end())
		{
			//delete (*it)->GetSprite();
			//delete (*it)->GetCollider();
			delete (*it);
			++it;
		}
		m_slow_kid.clear();
	}
};

std::string GameStateA::Next() {
	return "MenuState";
};

bool GameStateA::IsType(const std::string &type) {
	return type.compare("GameStateA") == 0;
};