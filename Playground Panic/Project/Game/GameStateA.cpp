
#include "stdafx.h"
#include <iostream>
//#include "GameObject.h"
#include "GameStateA.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"

#include "SlowKid.h"
#include "BikeKid.h"
#include "ParentUI.h"
#include "HealthBar.h"

#include "Collider.h"
#include "CountdownTimer.h"
#include "SpriteObject.h"

#include <cmath>
#include <iostream>
//#include "Level.h"


GameStateA::GameStateA()
{	
	m_player = nullptr;
	m_player_collider = nullptr;
	m_global_speed = 1.0f;
	m_player_pss = 100;
	m_enemies_to_spawn = 0;
};


bool GameStateA::Enter() 
{
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

	if (!m_slow_kid_texture.loadFromFile("../data/textures/SlowKid.png"))
	{
		// Shit happened
	}
	m_slow_kid_texture.setSmooth(true);

	if (!m_bike_kid_texture.loadFromFile("../data/textures/BikeKid.png"))
	{
		// Shit happened
	}
	m_bike_kid_texture.setSmooth(true);

	if (!m_framehealthbar_texture.loadFromFile("../data/textures/HealthBar2.png"))
	{
		// Shit happened
	}
	m_framehealthbar_texture.setSmooth(true);
	
	if (!m_player_dirt_texture.loadFromFile("../data/textures/Dirt sprites/Playerfemaledirt3.png"))
	{
		// Shit happened
	}
	m_player_dirt_texture.setSmooth(true);

	if (!m_slow_kid_dirt_texture.loadFromFile("../data/textures/Dirt sprites/enemy slow kid dirt 3.png"))
	{
		// Shit happened
	}
	m_slow_kid_dirt_texture.setSmooth(true);

	if (!m_bike_kid_dirt_texture.loadFromFile("../data/textures/Dirt sprites/Enemy bike kid dirt 3.png"))
	{
		// Shit happened
	}
	m_bike_kid_dirt_texture.setSmooth(true);

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

	if (!m_indicator_texture.loadFromFile("../data/textures/Indicator.png"))
	{
		// Shit happened
	}
	m_indicator_texture.setSmooth(true);

	if (!m_parent_ball_texture.loadFromFile("../data/textures/Parent_ball.png"))
	{
		// Shit happened
	}
	m_parent_ball_texture.setSmooth(true);

	if (!m_parent_bar_texture.loadFromFile("../data/textures/parent_bar.png"))
	{
		// Shit happened
	}
	m_parent_bar_texture.setSmooth(true);

	if (!m_arrow_texture.loadFromFile("../data/textures/IndicatorChild.png"))
	{
		// Shit happened
	}
	m_arrow_texture.setSmooth(true);

	/*
	float recWidth = 20.0f, recHeight = 15.0f;
	rec = new sf::RectangleShape(sf::Vector2f(recWidth, recHeight));
	rec->setPosition(sf::Vector2f(600.0f, 300.0f));
	rec->setOrigin(sf::Vector2f(recWidth / 2, recHeight / 2));
	*/
	//rec->setTexture(&m_player_texture);

	m_background = new SpriteObject(&m_background_texture);
	
	m_player_collider = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player = new PlayerObject(&m_player_texture, float(128.0f), m_player_collider, &m_player_dirt_texture);
	m_player->SetPosition(sf::Vector2f(2490.0f, 900.0f));

	m_heatbar = new SpriteObject(&m_heatbar_texture);
	m_frameheatbar = new SpriteObject(&m_frameheatbar_texture);
	m_healthbar = new SpriteObject(&m_healthbar_texture);
	m_framehealthbar = new SpriteObject(&m_framehealthbar_texture);

	m_parent_bar = new SpriteObject(&m_parent_bar_texture);

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
		|| (m_view.getCenter().x + (m_view.getSize().x / 2)) / 1.4f >= (m_background->GetSprite()->getGlobalBounds().width / 1.4f) - 1
		|| (m_view.getCenter().y - (m_view.getSize().y / 2)) / 1.4f <= 1
		|| (m_view.getCenter().y + (m_view.getSize().y / 2)) / 1.4f >= (m_background->GetSprite()->getGlobalBounds().height / 1.4f) - 1)
	{
		if ((m_view.getCenter().x - (m_view.getSize().x / 2)) / 1.4f <= 1
			|| (m_view.getCenter().x + (m_view.getSize().x / 2)) / 1.4f >= (m_background->GetSprite()->getGlobalBounds().width / 1.4f) - 1)
		{
			//std::cout << "Setting m_view_position.x to m_view's center x" << std::endl;
			m_view_position.x = m_view.getCenter().x;
		}
		if ((m_view.getCenter().y - (m_view.getSize().y / 2)) / 1.4f <= 1
			|| (m_view.getCenter().y + (m_view.getSize().y / 2)) / 1.4f >= (m_background->GetSprite()->getGlobalBounds().height / 1.4f) - 1)
		{
			//std::cout << "Setting m_view_position.y to m_view's center y" << std::endl;
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
		&& m_player->GetPosition().x + m_view.getSize().x / 2 < m_background->GetSprite()->getGlobalBounds().width)
	{
		//std::cout << "Setting view to the player's x" << std::endl;
		//float meh = m_player->GetPosition().x + m_view.getSize().x / 2, meh2 = m_background_sprite.getGlobalBounds().width;
		//std::cout << meh << " " << meh2 << std::endl;
		m_view.setCenter(m_player->GetPosition().x, m_view.getCenter().y);
	}

	if (m_player->GetPosition().y > m_view.getSize().y / 2
		&& m_player->GetPosition().y + m_view.getSize().y / 2 < m_background->GetSprite()->getGlobalBounds().height)
	{
		//std::cout << "Setting view to the player's x" << std::endl;
		//float meh = m_player->GetPosition().y + m_view.getSize().y / 2, meh2 = m_background_sprite.getGlobalBounds().height;
		//std::cout << meh << " " << meh2 << std::endl;
		m_view.setCenter(m_view.getCenter().x, m_player->GetPosition().y);
	}

	/*std::cout << "Current position of the view: " << m_view.getCenter().x << ", " << m_view.getCenter().y << std::endl;
	std::cout << "Current position of the player: " << m_player->GetPosition().x << ", " << m_player->GetPosition().y << std::endl;*/

	m_window.setView(m_view);
			
	m_mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window)) + static_cast<sf::Vector2f>(m_view.getCenter()) - static_cast<sf::Vector2f>((m_view.getSize() / 2.0f)) / 1.4f;
	

	m_healthbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - (m_view.getSize().y / 2)));
	m_framehealthbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - (m_view.getSize().y / 2)));
	m_heatbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y + 40 - (m_view.getSize().y / 2)));
	m_frameheatbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y + 40 - (m_view.getSize().y / 2)));
	m_parent_bar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y + 800 - (m_view.getSize().y / 2)));

	if(m_player->GetCurrentHealth() > m_player->GetMaxHealth())
	{
		m_player->SetCurrentHealth(m_player->GetMaxHealth());
	}
	if(10 * m_player->GetCurrentHealth() <= m_player->GetMaxHealth() * 10)
	{
		m_healthbar->GetSprite()->setTextureRect(sf::IntRect(0, 0, 10*m_player->GetCurrentHealth(), 40));	
	}

	if (10 * m_player->GetWeaponHeat() <= m_player->GetWeaponMaxHeat() * 10)
	{
		m_heatbar->GetSprite()->setTextureRect(sf::IntRect(0, 0, 10 * m_player->GetWeaponHeat(), 40));
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
		m_projectile.push_back(new ProjectileObject(&m_projectile_texture, float(8.0f)/*, new Collider(m_projectile_sprite[m_projectile_sprite.size() - 1]->getPosition(), sf::Vector2f(16.0f, 16.0f))*/));
		m_projectile[m_projectile.size() - 1]->SetPosition(m_player->GetSprite()->getTransform().transformPoint(53.0f, -35.0f)); //128.0f, 10.0f
		m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getTransform().transformPoint(53.0f, 300.0f), m_mouse_position, m_player->GetPosition());

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
		int special = 1;
		for (int i = 0; i < m_enemies_to_spawn; i++)
		{
			//Read from a textfile into an object?
			if (rand() % 2 == 1)
			{
				m_slow_kid.push_back(new SlowKid(&m_slow_kid_texture, float(32.0f), rand() % 4 + 3, special-- > 0, &m_slow_kid_dirt_texture));
				m_slow_kid[m_slow_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background->GetSprite()->getGlobalBounds().width + 400, rand() % (int)m_background->GetSprite()->getGlobalBounds().height + 400));
				m_enemies.push_back(m_slow_kid[m_slow_kid.size() - 1]);
			}
			else
			{
				//m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture/*, new Collider(sf::Vector2f((rand()%800 + 100 - m_window.getPosition().x), (rand()%500 + 100 - m_window.getPosition().y)), sf::Vector2f(128.0f, 128.0f)))*/, float(32.0f), rand() % 4 + 3));
				m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture, float(32.0f), rand() % 4 + 3, special-- > 0, &m_bike_kid_dirt_texture));
				m_bike_kid[m_bike_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background->GetSprite()->getGlobalBounds().width + 400, rand() % (int)m_background->GetSprite()->getGlobalBounds().height + 400));
				m_enemies.push_back(m_bike_kid[m_bike_kid.size() - 1]);
			}

			if (m_enemies[m_enemies.size() - 1]->GetSpecial())
			{
				m_parentUI.push_back(new ParentUI(&m_arrow_texture, &m_indicator_texture, &m_parent_ball_texture));
			}

			m_timer->Reset();
			m_timer->Start();
			//std::cout << "Slow Kid created - " << m_slow_kid.size() << std::endl;
		}
	}

	m_player->Update(deltatime, m_global_speed, m_mouse_position);

	{//////////Uppdaterad
		int j = 0;
		for (int i = 0; i < m_enemies.size(); i++)
		{
			if (m_enemies[i]->GetSpecial())
			{
				m_parentUI[j]->Update(m_window, m_view, m_player->GetPosition(), m_enemies[i]->GetPosition());
				j++;
			}
		}
	}

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
		for(int i = 0; i < m_enemies.size(); i++)
		{
			for(int j = 0; j < m_enemies.size(); j++)
			{
				if(i != j)
				{
					sf::Vector2f offset;
					if (Collisions->Overlap(m_enemies[i]->GetPosition(), m_enemies[j]->GetPosition(), m_enemies[i]->GetRadius(), m_enemies[j]->GetRadius(), offset))
					{
						//if (!m_enemies[j]->IsHit())
						{
							//m_enemies[j]->SetHit(true);
							if (offset.x > 0 && offset.y > 0)
							{
								m_enemies[j]->GetSprite()->setPosition(m_enemies[j]->GetSprite()->getPosition() + offset / 20.0f);
								m_enemies[j]->SetPosition(m_enemies[j]->GetSprite()->getPosition());
							}
							else if (offset.x <= 0 && offset.y <= 0)
							{
								m_enemies[j]->GetSprite()->setPosition(m_enemies[j]->GetSprite()->getPosition() + offset * 20.0f);
								m_enemies[j]->SetPosition(m_enemies[j]->GetSprite()->getPosition());
							}
							else if (offset.x > 0 && offset.y <= 0)
							{
								m_enemies[j]->GetSprite()->setPosition(m_enemies[j]->GetSprite()->getPosition() + sf::Vector2f((offset.x / 20.0f), (offset.y * 20.0f)));
								m_enemies[j]->SetPosition(m_enemies[j]->GetSprite()->getPosition());
							}
							else if (offset.x <= 0 && offset.y > 0)
							{
								m_enemies[j]->GetSprite()->setPosition(m_enemies[j]->GetSprite()->getPosition() + sf::Vector2f((offset.x * 20.0f), (offset.y / 20.0f)));
								m_enemies[j]->SetPosition(m_enemies[j]->GetSprite()->getPosition());
							}
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
			//m_enemies[i]->SetHit(true);
		}
		for (int i = 0; i < m_slow_kid.size(); i++)
		{
			m_slow_kid[i]->Update(deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_player->GetPosition());
		}
		for (int i = 0; i < m_bike_kid.size(); i++)
		{
			m_bike_kid[i]->Update(deltatime, m_global_speed, m_player, m_bike_kid[i]->GetPosition(), m_player->GetPosition());
		}
			
		
	}

	if (m_enemies.size() != 0 && m_projectile.size() != 0)
	{
		int k = 0;
		for (int i = m_enemies.size() - 1; i >= 0; i--)
		{
			for (int j = m_projectile.size() - 1; j >= 0; j--)
			{
				if (Collisions->Overlap(m_enemies[i]->GetPosition(), m_projectile[j]->GetPosition(), m_enemies[i]->GetRadius(), m_projectile[j]->GetRadius()))
				{
					//std::cout << m_enemies[i]->GetPosition().x << "-" << m_enemies[i]->GetPosition().y << " " << m_projectile[j]->GetPosition().x << "-" << m_projectile[j]->GetPosition().y << std::endl;
					//m_projectile[j]->SetPosition(sf::Vector2f(-999.0f, -999.0f));
					//std::cout << "Before: " << m_enemies.size() << " " << m_projectile.size() << " After: ";

					m_projectile.erase(m_projectile.begin() + j);
					//delete m_projectile[j];

					m_enemies[i]->SetDirt(m_enemies[i]->GetDirt() - 1);
					if (m_enemies[i]->GetDirt() <= 0)
					{
						//delete m_enemies[i]->GetSprite();
						//delete m_enemies[i]->GetCollider();
						if (m_enemies[i]->GetSpecial())
						{
							m_parentUI.erase(m_parentUI.begin() + k);
							//delete m_parentUI[k];
						}
						m_enemies.erase(m_enemies.begin() + i);
						//delete m_enemies[i];

						////Remove this and alter it into Enemy.cpp
						//for (int j = 0; j < m_slow_kid.size(); j++)
						//{
						//	if (m_slow_kid[j]->GetSprite() == nullptr)
						//	{
						//		delete m_slow_kid[j];
						//	}
						//}
						//for (int j = 0; j < m_bike_kid.size(); j++)
						//{
						//	if (m_bike_kid[j]->GetSprite() == nullptr)
						//	{
						//		delete m_bike_kid[j];
						//	}
						//}
					}
					//std::cout << m_enemies.size() << " " << m_projectile.size() << std::endl;
					//std::cout << i << " " << j << std::endl;
				}
			}
			if (m_enemies[i]->GetSpecial())
			{
				k++;
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
				m_projectile.erase(it++);
			}
			else
			{
				i++;
			}
		}
	}

	m_window.clear(sf::Color(18, 45, 0));
	m_background->Draw(&m_window);
		

	for (int i = 0; i < m_projectile.size(); i++)
	{
		//m_window.draw(*m_projectile[i]->GetSprite());
		m_projectile[i]->Draw(&m_window);
	}
	for (int i = 0; i < m_enemies.size(); i++)
	{
		//m_window.draw(*m_enemies[i]->GetSprite());
		m_enemies[i]->Draw(&m_window);
	}
			
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
					
			return false;
				
		}
		
	}
		
	//m_window.setMouseCursorVisible(false);
			
	m_player->Draw(&m_window);

	m_heatbar->Draw(&m_window);
	m_frameheatbar->Draw(&m_window);
	m_healthbar->Draw(&m_window);
	m_framehealthbar->Draw(&m_window);
	///////////////////////////////////////////////////////////Change
	m_parent_bar->Draw(&m_window);

	if (m_parentUI.size() > 0)
	{
		for (int j = 0; j<m_parentUI.size(); j++)
		{
			m_parentUI[j]->Draw(m_window);
		}
	}
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

	if (m_healthbar != nullptr)
	{
		delete m_healthbar;
		m_healthbar = nullptr;
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

	/*delete &m_background_texture;
	delete &m_player_texture;
	delete &m_projectile_texture;
	delete &m_crosshair_texture;
	delete &m_slow_kid_texture;
	delete &m_bike_kid_texture;
	delete &m_framehealthbar_texture;
	delete &m_healthbar_texture;
	delete &m_frameheatbar_texture;
	delete &m_heatbar_texture;
	delete &m_indicator_texture;
	delete &m_parent_ball_texture;
	delete &m_parent_bar_texture;
	delete &m_arrow_texture;*/
};

std::string GameStateA::Next() {
	return "MenuState";
};

bool GameStateA::IsType(const std::string &type) {
	return type.compare("GameStateA") == 0;
};