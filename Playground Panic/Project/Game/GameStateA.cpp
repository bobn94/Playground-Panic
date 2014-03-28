
#include "stdafx.h"
#include <iostream>
//#include "GameObject.h"
#include "GameStateA.h"
#include "PlayerObject.h"
#include "ProjectileObject.h"

#include "SlowKid.h"
#include "BikeKid.h"
#include "ParentUI.h"
#include "ParentBall.h"
#include "HealthBar.h"
#include "Level.h"
#include "Collider.h"
#include "CountdownTimer.h"
#include "SpriteObject.h"
#include "ParentUI.h"

#include <cmath>
#include <iostream>
//#include "Level.h"


GameStateA::GameStateA()
{
	m_player = nullptr;
	m_player_collider = nullptr;
	m_global_speed = 1.0f;
	m_player_pss = 300;
	m_enemy_pss = 100;
	m_end_pause = -1;
	m_enemies_to_spawn = 0;
	m_blink_pss = 500;
	m_varning_shit_happens = false;
};


bool GameStateA::Enter()
{
	//////////////////////MUIC///////////////////////////////////////////////////
	if (!music.openFromFile("../data/sounds/Monkeys Spinning Monkeys.wav"))
	{
		// error...
	}
	//////////////////////SOUND//////////////////////////////////////////////////
	if (!steam_buffer.loadFromFile("../data/sounds/steam.wav"))
	{
		// error...
	}
	if (!kids_booing_buffer.loadFromFile("../data/sounds/kids_booing_1.wav"))
	{
		// error...
	}
	if (!insane_guy_buffer.loadFromFile("../data/sounds/Losing_insane.wav"))
	{
		// error...
	}
	if (!YAY_buffer.loadFromFile("../data/sounds/YAY_1.wav"))
	{
		// error...
	}
	if (!mud_hit_buffer.loadFromFile("../data/sounds/Gettinghitbymud.wav"))//THere is no fucking collision. You have to wait, sry :b
	{
		// error...
	}
	if (!kid_oof_buffer.loadFromFile("../data/sounds/kid_oof.wav"))
	{
		// error...
	}
	if (!shoot1.loadFromFile("../data/sounds/air.wav"))
	{
		// error...
	}
	if (!splashkid.loadFromFile("../data/sounds/water.wav"))
	{
		// error...
	}
	/////////////////////TEXTURE/////////////////////////////////////////////////

	if (!m_background_texture.loadFromFile("../data/textures/Background.png"))
	{
		// This shit shouldn't happen
	}
	m_background_texture.setSmooth(true);

	if (!m_background_overlay_texture.loadFromFile("../data/textures/Buskar.png"))
	{
		// This shit shouldn't happen
	}
	m_background_overlay_texture.setSmooth(true);

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

	if (!m_projectile_mud_texture.loadFromFile("../data/textures/mud1.png"))
	{
		// Shit happened
	}
	m_projectile_mud_texture.setSmooth(true);

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

	if (!m_framehealthbar_texture.loadFromFile("../data/textures/Dirt bar border.png"))
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

	if (!m_healthbar_texture.loadFromFile("../data/textures/Dirt bar.png"))
	{
		// Shit happened
	}
	m_healthbar_texture.setSmooth(true);

	if (!m_frameheatbar_texture.loadFromFile("../data/textures/Temperature border.png"))
	{
		// Shit happened
	}
	m_frameheatbar_texture.setSmooth(true);

	if (!m_heatbar_texture.loadFromFile("../data/textures/temperature bar.png"))
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

	if (!m_parent_bar_texture.loadFromFile("../data/textures/parent meter.png"))
	{
		// Shit happened
	}
	m_parent_bar_texture.setSmooth(true);

	if (!m_uibg_texture.loadFromFile("../data/textures/UI base.png"))
	{
		// Shit happened
	}
	m_uibg_texture.setSmooth(true);

	if (!m_arrow_texture.loadFromFile("../data/textures/IndicatorChild.png"))
	{
		// Shit happened
	}
	m_arrow_texture.setSmooth(true);

	if (!m_clear_texture.loadFromFile("../data/textures/daycleared.png"))
	{
		// Shit happened
	}
	m_clear_texture.setSmooth(true);

	if (!m_varning_texture.loadFromFile("../data/textures/parentswarning.png"))
	{
		// Shit happened
	}
	m_varning_texture.setSmooth(true);

	m_player_female_walk_path = "../data/textures/Animation/femwalk.txt";
	m_slow_kid_path = "../data/textures/Animation/slowkidwalk.txt";
	m_bike_kid_path = "../data/textures/Animation/bikeKidWalk.txt";
	m_projectile_path = "../data/textures/Animation/spongeAnim.txt";

	m_map_colliders.push_back(new Collider(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(175, 2787)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(0, 2787), sf::Vector2f(1920, 453)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(1920, 2985), sf::Vector2f(1460, 255)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(3380, 2780), sf::Vector2f(2156, 460)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(5536, 0), sf::Vector2f(224, 3240)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(3509, 0), sf::Vector2f(2027, 113)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(3024, 0), sf::Vector2f(485, 420)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(1810, 0), sf::Vector2f(1213, 878)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(175, 0), sf::Vector2f(1636, 332)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(175, 332), sf::Vector2f(1119, 125)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(175, 457), sf::Vector2f(992, 78)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(175, 535), sf::Vector2f(729, 225)));
	m_map_colliders.push_back(new Collider(sf::Vector2f(175, 760), sf::Vector2f(443, 208)));

	m_background = new SpriteObject(&m_background_texture);
	m_background_overlay = new SpriteObject(&m_background_overlay_texture);

	m_player_collider = new Collider(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(20.0f, 30.0f));
	m_player = new PlayerObject(&m_player_texture, float(128.0f), m_player_collider, &m_player_dirt_texture, m_player_female_walk_path);
	m_player->SetPosition(sf::Vector2f(2490.0f, 900.0f));

	m_heatbar = new SpriteObject(&m_heatbar_texture);
	m_frameheatbar = new SpriteObject(&m_frameheatbar_texture);
	m_healthbar = new SpriteObject(&m_healthbar_texture);
	m_framehealthbar = new SpriteObject(&m_framehealthbar_texture);

	m_parent_bar = new SpriteObject(&m_parent_bar_texture);
	m_parent_bar->GetSprite()->setScale(0.643f, 1);
	m_uibg = new SpriteObject(&m_uibg_texture);

	m_clear = new SpriteObject(&m_clear_texture);
	m_clear->GetSprite()->setColor(sf::Color::Transparent);
	m_clear->GetSprite()->setOrigin(m_clear->GetSprite()->getLocalBounds().width / 2, m_clear->GetSprite()->getLocalBounds().height / 2);

	m_crosshair = new SpriteObject(&m_crosshair_texture);
	m_crosshair->GetSprite()->setOrigin(m_crosshair->GetSprite()->getLocalBounds().width / 2, m_crosshair->GetSprite()->getLocalBounds().height / 2);
	m_crosshair->GetSprite()->setScale(0.6f, 0.6f);

	m_varning = new SpriteObject(&m_varning_texture);
	m_varning->SetPosition(sf::Vector2f(-999, -999));
	m_point_house = sf::Vector2f(2490.0f, 850.0f);
	m_point_street = sf::Vector2f(2509.0f, 3357.0f);

	m_enemies_to_spawn = 1;

	m_timer = new CountdownTimer();
	m_timer->SetTime(0, 0, 3);
	m_timer->Reset();
	m_timer->Start();

	m_levelup_timer = new CountdownTimer();
	m_levelup_timer->SetTime(0, 0, 15);
	m_levelup_timer->Reset();
	m_levelup_timer->Start();
	m_first_run = true;
	m_continue = true;
	return true;
};

bool GameStateA::Update(float deltatime, sf::RenderWindow &m_window, sf::View &m_view, Level& level)
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			music.stop();
			m_window.close();
			return false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			music.stop();
			m_window.close();
			return false;

		}

	}

	if (m_first_run)
	{
		if (m_window.getSize().x == 1080){
			m_parent_bar->GetSprite()->setScale(0.643f, 1);
		}
		m_enemies_to_spawn = level.GetKidsToSpawn() + level.GetSpecialToSpawn();
		m_special_to_spawn = level.GetSpecialToSpawn();

		m_heatbar->GetSprite()->setScale(0.726f, 0.726f);
		m_end_pause = -1;
		m_end_time.restart();

		if (m_window.getSize().x != 80) //'tis useless
		{
			m_parent_bar->GetSprite()->setScale(0.643f, 0.643f);
			m_uibg->GetSprite()->setScale(0.643f, 0.643f);
			m_framehealthbar->GetSprite()->setScale(0.643f, 0.643f);
			m_frameheatbar->GetSprite()->setScale(0.643f, 0.643f);
			m_heatbar->GetSprite()->setScale(0.466818f, 0.466818f);
			m_healthbar->GetSprite()->setScale(0.643f, 0.643f);
			m_varning->GetSprite()->setScale(0.643f, 0.643f);

		}
		else
		{
			m_parent_bar->GetSprite()->setScale(0.643f, 0.643f);
			m_uibg->GetSprite()->setScale(0.643f, 0.643f);
			m_framehealthbar->GetSprite()->setScale(0.643f, 0.643f);
			m_healthbar->GetSprite()->setScale(0.643f, 0.643f);
			m_varning->GetSprite()->setScale(0.643f, 0.643f);
			m_heatbar->GetSprite()->setScale(0.726f, 0.726f);
			m_frameheatbar->GetSprite()->setScale(0.643f, 0.643f);
		}
		//////Sound and music//////
		music.play();
		music.setLoop(true);
		/////////////////////////

		m_first_run = false;
	}
	m_timer->Update();
	if(m_player->GetCurrentHealth() >= m_player->GetMaxHealth()){
		m_window.close();
	}
	sf::Vector2f m_view_position = sf::Vector2f(-99.0f, -99.0f);

	if (m_view.getCenter().x == -99 && m_view.getCenter().y == -99)
	{
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

	/*std::cout << m_parentUI.size() << std::endl;
	for (int i = 0; i < m_parentUI.size(); i++)
	{
		std::cout << m_parentUI[i]->GetColor().r << ", " << m_parentUI[i]->GetColor().g << ", " << m_parentUI[i]->GetColor().b << std::endl;
	}*/

	m_healthbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 153 + (m_view.getSize().y / 2)));
	m_framehealthbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 153 + (m_view.getSize().y / 2)));
	m_heatbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 113 + (m_view.getSize().y / 2)));
	m_frameheatbar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 113 + (m_view.getSize().y / 2)));
	m_parent_bar->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 73 + (m_view.getSize().y / 2)));
	m_uibg->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2), m_view.getCenter().y - 131 + (m_view.getSize().y / 2)));
	m_clear->SetPosition(sf::Vector2f(m_player->GetPosition().x, m_player->GetPosition().y - 300));

	if (m_player->GetCurrentHealth() > m_player->GetMaxHealth())
	{
		m_player->SetCurrentHealth(m_player->GetMaxHealth());
	}
	if (40 * m_player->GetCurrentHealth() <= m_player->GetMaxHealth() * 40)
	{
		m_healthbar->GetSprite()->setTextureRect(sf::IntRect(0, 0, 14.5f * m_player->GetCurrentHealth(), m_healthbar->GetSprite()->getLocalBounds().height));
	}

	if (10 * m_player->GetWeaponHeat() <= m_player->GetWeaponMaxHeat() * 40)
	{
		m_heatbar->GetSprite()->setTextureRect(sf::IntRect(0, 0, 11.5f * m_player->GetWeaponHeat(), m_heatbar->GetSprite()->getLocalBounds().height));
	}

	if (m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss)
	{
		m_player->SetWeaponHeat(m_player->GetWeaponHeat() - 4000.0f * deltatime);
		if (m_player->GetWeaponHeat() < 0)
		{
			m_player->SetWeaponHeat(0.0f);
		}
	}

	if (m_player->GetWeaponHeat() <= 0 && m_player->GetOverheat())
	{
		m_player->SetOverheat(false);
		steam_sound.stop();
		steam_sound.setLoop(false);
	}

	if (m_player->GetCurrentHealth() == m_player->GetMaxHealth())
	{
		insane_guy_sound.setBuffer(insane_guy_buffer);//going insane guy voice
		insane_guy_sound.play();
		
		return false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_player_pst.getElapsedTime().asMilliseconds() > m_player_pss && !m_player->GetOverheat())
	{
		m_projectile.push_back(new ProjectileObject(&m_projectile_texture, float(8.0f), m_projectile_path, 0));
		m_projectile[m_projectile.size() - 1]->SetPosition(m_player->GetSprite()->getTransform().transformPoint(65.0f, -35.0f)); //128.0f, 10.0f
		m_projectile[m_projectile.size() - 1]->Initialize(m_player->GetSprite()->getTransform().transformPoint(65.0f, 300.0f), m_mouse_position, m_player->GetPosition());
		m_projectile[m_projectile.size() - 1]->GetSprite()->setTextureRect(sf::IntRect(0, 0, 35, 111));

		soundshoot1.setBuffer(shoot1);
		soundshoot1.play();

		m_player_pst.restart();
		//m_player_pss = 10000000;

		if (m_player->GetWeaponHeat() >= m_player->GetWeaponMaxHeat() - 1.0f)
		{
			steam_sound.setBuffer(steam_buffer);
			steam_sound.play();
			steam_sound.setLoop(true);
			m_player->SetOverheat(true);
		}
		m_player->SetWeaponHeat(m_player->GetWeaponHeat() + 500000.0f * deltatime);
	}

	if (m_enemies.size() > 0)
	{
		//std::cout << m_enemy_pst.getElapsedTime().asMilliseconds() * (m_enemies.size() / 50.0f) << " > " << m_enemy_pss << std::endl;
		if (m_enemy_pst.getElapsedTime().asMilliseconds() * (m_enemies.size() / 70.0f) > m_enemy_pss)
		{
			int enemy = rand() % m_enemies.size();
			if (m_enemies[enemy]->GetCanShoot() && m_enemies[enemy]->GetDirt() > 0)
			{
				m_projectile.push_back(new ProjectileObject(&m_projectile_mud_texture, float(8.0f), "", 1));
				m_projectile[m_projectile.size() - 1]->SetPosition(m_enemies[enemy]->GetSprite()->getTransform().transformPoint(53.0f, -35.0f));
				m_projectile[m_projectile.size() - 1]->Initialize(m_enemies[enemy]->GetSprite()->getTransform().transformPoint(53.0f, 300.0f), m_player->GetPosition(), m_enemies[enemy]->GetPosition());
			}

			m_enemy_pst.restart();
		}
	}
	if (m_enemies_to_spawn > 0 || m_special_to_spawn > 0)
	{
		if (m_timer->Done())
		{
			if (m_enemies_to_spawn == 0)
			{
				m_timer->SetTime(0, 0, 2);
			}
			else
			{
				m_timer->SetTime(0, 0, 1);
			}
			if (m_enemies_to_spawn > 0)
			{
				//Read from a textfile into an object?
				if (rand() % 2 == 1)
				{
					m_slow_kid.push_back(new SlowKid(&m_slow_kid_texture, float(32.0f), rand() % 4 + 3, false, &m_slow_kid_dirt_texture, m_slow_kid_path));
					m_slow_kid[m_slow_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background->GetSprite()->getGlobalBounds().width + 400, rand() % (int)m_background->GetSprite()->getGlobalBounds().height + 400));
					m_enemies.push_back(m_slow_kid[m_slow_kid.size() - 1]);
				}
				else
				{
					//m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture/*, new Collider(sf::Vector2f((rand()%800 + 100 - m_window.getPosition().x), (rand()%500 + 100 - m_window.getPosition().y)), sf::Vector2f(128.0f, 128.0f)))*/, float(32.0f), rand() % 4 + 3));

					m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture, float(32.0f), rand() % 4 + 3, false, &m_bike_kid_dirt_texture, m_bike_kid_path));
					m_bike_kid[m_bike_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background->GetSprite()->getGlobalBounds().width + 400, rand() % (int)m_background->GetSprite()->getGlobalBounds().height + 400));
					m_enemies.push_back(m_bike_kid[m_bike_kid.size() - 1]);
				}
				m_enemies_to_spawn -= 1;

				//std::cout << "Slow Kid created - " << m_slow_kid.size() << std::endl;

			}
			else if (m_special_to_spawn > 0)
			{
				if (rand() % 2 == 1)
				{
					m_slow_kid.push_back(new SlowKid(&m_slow_kid_texture, float(32.0f), rand() % 4 + 3, true, &m_slow_kid_dirt_texture, m_slow_kid_path));
					m_slow_kid[m_slow_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % ((int)m_background->GetSprite()->getGlobalBounds().height - 400) + 400, rand() % ((int)m_background->GetSprite()->getGlobalBounds().height - 400) + 400));
					m_enemies.push_back(m_slow_kid[m_slow_kid.size() - 1]);
				}
				else
				{
					//m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture/*, new Collider(sf::Vector2f((rand()%800 + 100 - m_window.getPosition().x), (rand()%500 + 100 - m_window.getPosition().y)), sf::Vector2f(128.0f, 128.0f)))*/, float(32.0f), rand() % 4 + 3));

					m_bike_kid.push_back(new BikeKid(&m_bike_kid_texture, float(32.0f), rand() % 4 + 3, true, &m_bike_kid_dirt_texture, m_bike_kid_path));
					m_bike_kid[m_bike_kid.size() - 1]->SetPosition(sf::Vector2f(rand() % (int)m_background->GetSprite()->getGlobalBounds().width + 400, rand() % (int)m_background->GetSprite()->getGlobalBounds().height + 400));
					m_enemies.push_back(m_bike_kid[m_bike_kid.size() - 1]);
				}
				m_parentUI.push_back(new ParentUI(&m_arrow_texture, &m_indicator_texture, &m_parent_ball_texture, &m_view));
				m_special_to_spawn -= 1;

			}

			m_timer->Reset();
			m_timer->Start();
		}
	}

	m_player->Update(deltatime, m_global_speed, m_mouse_position);

	for (int i = 0; i < m_parentUI.size(); i++)
	{
		bool p = true;
		if (m_parentUI[i]->GetBall().GetDistance() > 700.0f)
		{
			p = false;
			m_varning_shit_happens = true;
			m_varning->SetPosition(sf::Vector2f(m_view.getCenter().x - (m_view.getSize().x / 2) + 900, m_view.getCenter().y - 300 + (m_view.getSize().y / 2)));
		}

		/*if (p == false)
		{
			m_varning_shit_happens = false;
			m_varning->GetSprite()->setColor(sf::Color::Transparent);
		}*/

	}
	if (m_blink_pst.getElapsedTime().asMilliseconds() > m_blink_pss && m_varning_shit_happens)
	{
		if (m_varning->GetSprite()->getColor() == sf::Color::White)
		{
			m_varning->GetSprite()->setColor(sf::Color::Transparent);
		}
		else
		{
			m_varning->GetSprite()->setColor(sf::Color::White);
		}
		m_blink_pst.restart();
	}

	{
		int j = 0;
		for (int i = 0; i < m_enemies.size(); i++)
		{
			if (m_enemies[i]->GetSpecial())
			{
				m_parentUI[j]->Update(deltatime, m_global_speed, m_window, m_view, m_player->GetPosition(), m_enemies[i]->GetPosition());
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

	for (int i = 0; i < m_map_colliders.size(); i++)
	{
		sf::Vector2f offset(0.0f, 0.0f);
		if (Collisions->Overlap(m_map_colliders[i], m_player->GetPosition(), m_player->GetRadius(), offset))
		{
			m_player->GetSprite()->setPosition(m_player->GetSprite()->getPosition() + offset);
		}
	}

	for (int i = 0; i < m_enemies.size(); i++)
	{
		for (int j = i; j < m_enemies.size(); j++)
		{
			if (i != j)
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

	if (m_enemies.size() != m_slow_kid.size() + m_bike_kid.size())
	{
		std::cout << "Shit's about to go down" << std::endl;
	}

	if (m_projectile.size() > 0) //This is against my principles, so much redundancy
	{
		for (int j = m_projectile.size() - 1; j >= 0; j--)
		{
			if (m_projectile[j]->GetType() > 0 && Collisions->Overlap(m_player->GetPosition(), m_projectile[j]->GetPosition(), m_player->GetRadius(), m_projectile[j]->GetRadius()))
			{
				//std::cout << m_player->GetPosition().x << "-" << m_player->GetPosition().y << " " << m_projectile[j]->GetPosition().x << "-" << m_projectile[j]->GetPosition().y << std::endl;
				//m_projectile[j]->SetPosition(sf::Vector2f(-999.0f, -999.0f));
				//std::cout << "Before: " << m_enemies.size() << " " << m_projectile.size() << " After: ";

				delete m_projectile[j];
				m_projectile.erase(m_projectile.begin() + j);

				m_player->SetCurrentHealth(m_player->GetCurrentHealth() + 1.0f);
				mud_hit.setBuffer(mud_hit_buffer);
				mud_hit.play();
			}
		}
	}

	if (m_enemies.size() > 0 && m_projectile.size() > 0)
	{
		for (int i = m_enemies.size() - 1; i >= 0; i--)
		{
			for (int j = m_projectile.size() - 1; j >= 0; j--)
			{
				if (m_projectile[j]->GetType() == 0 && Collisions->Overlap(m_enemies[i]->GetPosition(), m_projectile[j]->GetPosition(), m_enemies[i]->GetRadius(), m_projectile[j]->GetRadius()))
				{
					delete m_projectile[j];
					m_projectile.erase(m_projectile.begin() + j);

					m_enemies[i]->SetDirt(m_enemies[i]->GetDirt() - 1);
					
					if (m_enemies[i]->GetDirt() == 5 || m_enemies[i]->GetDirt() == 3 || m_enemies[i]->GetDirt() == 1)
					{
						kid_oof.setBuffer(kid_oof_buffer);
						kid_oof.play();
					}

					if (m_special_to_spawn == 0)
					{
						bool okay = true;
						for (int k = 0; k < m_enemies.size(); k++)
						{
							if (m_enemies[k]->GetSpecial() == 1 && m_enemies[k]->GetDirt() > 0)
							{
								okay = false;
							}
						}
						if (okay)
						{
							m_clear->GetSprite()->setColor(sf::Color::White);
							m_end_pause = 5000;
							m_end_time.restart();
							sound_YAY.setBuffer(YAY_buffer);//folk skriker YAY!!!!
							sound_YAY.play();
						}
					}
				}
			}
		}
	}

	for (int i = m_projectile.size() - 1; i >= 0; i--)
	{
		if ((m_projectile[i]->GetPosition().x < m_player->GetPosition().x - 800
			|| m_projectile[i]->GetPosition().y < m_player->GetPosition().y - 600
			|| m_projectile[i]->GetPosition().x > m_player->GetPosition().x + 800
			|| m_projectile[i]->GetPosition().y > m_player->GetPosition().y + 600
			)// && 1 == 0
			)
		{
			delete m_projectile[i];
			m_projectile.erase(m_projectile.begin() + i);
		}
	}

	{
		int k = -1;
		for (int i = 0; i < m_slow_kid.size(); i++)
		{
			if (m_slow_kid[i]->GetSpecial())
			{
				k++;
			}
			if (m_slow_kid[i]->GetSpecial() && m_slow_kid[i]->GetDirt() <= 0)
			{
				m_slow_kid[i]->Update(deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_point_street);
				m_parentUI[k]->SetColor(sf::Color(0, 0, 0, 0));
			}
			else if (m_slow_kid[i]->GetDirt() <= 0)
			{
				m_slow_kid[i]->Update(deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_point_house);
			}
			else
			{
				m_slow_kid[i]->Update(deltatime, m_global_speed, m_player, m_slow_kid[i]->GetPosition(), m_player->GetPosition());
			}
		}
	}

	{
		int k = -1;
		for (int i = 0; i < m_bike_kid.size(); i++)
		{
			if (m_bike_kid[i]->GetSpecial())
			{
				k++;
			}

			if (m_bike_kid[i]->GetSpecial() && m_bike_kid[i]->GetDirt() <= 0)
			{
				m_bike_kid[i]->Update(deltatime, m_global_speed, m_player, m_bike_kid[i]->GetPosition(), m_point_street);
				m_parentUI[k]->SetColor(sf::Color::Transparent);
			}
			else if (m_bike_kid[i]->GetDirt() <= 0)
			{
				m_bike_kid[i]->Update(deltatime, m_global_speed, m_player, m_bike_kid[i]->GetPosition(), m_point_house);
			}
			else
			{
				m_bike_kid[i]->Update(deltatime, m_global_speed, m_player, m_bike_kid[i]->GetPosition(), m_player->GetPosition());
			}
		}
	}

	{
		int k = m_parentUI.size();
		for (int i = m_enemies.size() - 1; i >= 0; i--)
		{
			if (m_enemies[i]->GetSpecial())
			{
				k--;
			}

			if (m_enemies[i]->OnTarget() && m_enemies[i]->GetDirt() <= 0 || m_end_time.getElapsedTime().asMilliseconds() > m_end_pause && m_end_pause != -1)
			{
				if (m_enemies[i]->GetSpecial())
				{
					delete m_parentUI[k];
					m_parentUI.erase(m_parentUI.begin() + k);
				}
				
				for (int l = m_slow_kid.size() - 1; l >= 0; l--)
				{
					if (m_slow_kid[l]->GetPosition() == m_enemies[i]->GetPosition())
					{
						level.m_score += 10;

						//delete m_slow_kid[l];
						m_slow_kid.erase(m_slow_kid.begin() + l);
					}
				}
				for (int l = m_bike_kid.size() - 1; l >= 0; l--)
				{
					if (m_bike_kid[l]->GetPosition() == m_enemies[i]->GetPosition())
					{
						level.m_score += 15;

						//delete m_bike_kid[l];
						m_bike_kid.erase(m_bike_kid.begin() + l);
					}
				}

				delete m_enemies[i];
				m_enemies.erase(m_enemies.begin() + i);
				//delete m_enemies[i];

				if (m_parentUI.size() == 0 || m_end_time.getElapsedTime().asMilliseconds() > m_end_pause && m_end_pause != -1 && m_special_to_spawn > 0 )
				{
					steam_sound.stop();
					steam_sound.setLoop(false);

					level.NextDay();
					m_next_state = "UpgradeState";
					m_continue = false;
				}
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

	m_crosshair->SetPosition(m_mouse_position);
	m_window.setMouseCursorVisible(false);

	m_player->Draw(&m_window);
	m_background_overlay->Draw(&m_window);
	m_uibg->Draw(&m_window);
	m_frameheatbar->Draw(&m_window);
	m_heatbar->Draw(&m_window);
	m_framehealthbar->Draw(&m_window);
	m_parent_bar->Draw(&m_window);
	m_healthbar->Draw(&m_window);
	m_varning->Draw(&m_window);
	m_clear->Draw(&m_window);
	m_crosshair->Draw(&m_window);

	if (m_parentUI.size() > 0)
	{
		for (int j = 0; j<m_parentUI.size(); j++)
		{
			m_parentUI[j]->Draw(m_window);
		}
	}
	m_window.display();

	//std::cout << m_enemies.size() << " ";
	//std::cout << m_slow_kid.size() << " ";
	//std::cout << m_bike_kid.size() << " ";
	//std::cout << m_projectile.size() << std::endl;

	return m_continue;
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
			if (*it != nullptr)
			{
				delete (*it);
				*it = nullptr;
			}
			++it;
		}
		m_projectile.clear();
	}

	{
		auto it = m_slow_kid.begin();
		while (it != m_slow_kid.end())
		{
			if (*it != nullptr)
			{
				delete (*it);
				*it = nullptr;
			}
			++it;
		}
		m_slow_kid.clear();
	}

	{
		auto it = m_bike_kid.begin();
		while (it != m_bike_kid.end())
		{
			if (*it != nullptr)
			{
				delete (*it);
				*it = nullptr;
			}
			++it;
		}
		m_bike_kid.clear();
	}

	{
	/*	auto it = m_enemies.begin();
		while (it != m_enemies.end())
		{
			if (*it != nullptr)
			{
				delete (*it);
				*it = nullptr;
			}
			++it;
		}*/
		m_enemies.clear();
	}

	{
		auto it = m_parentUI.begin();
		while (it != m_parentUI.end())
		{
			if (*it != nullptr)
			{
				delete (*it);
				*it = nullptr;
			}
			++it;
		}
		m_parentUI.clear();
	}

	if (m_heatbar != nullptr)
	{
		delete m_heatbar;
		m_heatbar = nullptr;
	}

	if (m_framehealthbar != nullptr)
	{
		delete m_framehealthbar;
		m_framehealthbar = nullptr;
	}

	if (m_uibg != nullptr)
	{
		delete m_uibg;
		m_uibg = nullptr;
	}

	if (m_crosshair != nullptr)
	{
	delete m_crosshair;
	m_crosshair = nullptr;
	}

	if (m_frameheatbar != nullptr)
	{
		delete m_frameheatbar;
		m_frameheatbar = nullptr;
	}

	if (m_levelup_timer != nullptr)
	{
		delete m_levelup_timer;
		m_levelup_timer = nullptr;
	}

	if (m_timer != nullptr)
	{
		delete m_timer;
		m_timer = nullptr;
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
	return m_next_state;
};

bool GameStateA::IsType(const std::string &type) {
	return type.compare("GameStateA") == 0;
};