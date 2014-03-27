#pragma once
#include "stdafx.h"
#include <iostream>
#include "UpgradeState.h"

UpgradeState::UpgradeState(){
	m_done = false;
}
bool UpgradeState::Enter()
{
	if (!m_continue_btn_texture.loadFromFile("../data/textures/continue_btn.png"))
	{
		std::cout << "Loading Error";
	}
	m_continue_btn_texture.setSmooth(true);
	
	if (!m_background_texture.loadFromFile("../data/textures/Loading.png"))
	{
		std::cout << "Loading Error";
	}
	m_background_texture.setSmooth(true);
	m_continue_btn_sprite.setTexture(m_continue_btn_texture);
	m_continue_btn_sprite.setOrigin(m_continue_btn_sprite.getLocalBounds().width / 2, m_continue_btn_sprite.getLocalBounds().height / 2);

	m_background_sprite.setTexture(m_background_texture);
	m_background_sprite.setOrigin(m_background_sprite.getLocalBounds().width / 2, m_background_sprite.getLocalBounds().height / 2);
	return true;
}

void UpgradeState::Exit()
{
	//delete things
}

void UpgradeState::Initialize(){

}

bool UpgradeState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level)
{
	//m_window.setView(m_view);
	m_view.setCenter(m_view.getSize().x / 2, m_view.getSize().y / 2);
	//m_view.setCenter(400.0f, 400.0f);
	m_window.setView(m_view);
	m_continue_btn_sprite.setPosition(m_view.getCenter());
	m_background_sprite.setPosition(m_view.getCenter());
	if (m_window.getSize().x < 1200.0f)
	{
		m_background_sprite.setScale(m_window.getSize().x / 1080.0f, m_window.getSize().y / 720.0f);
	}
	else
	{
		m_background_sprite.setScale(1.4f, 1.4f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		sf::Texture loading;
		if (!loading.loadFromFile("../data/textures/Loading.png"))
		{
			// This shit shouldn't happen
		}

		sf::Sprite load_sprite(loading);
		load_sprite.setPosition(m_view.getSize().x / 2 - load_sprite.getLocalBounds().width / 2, m_view.getSize().y / 1.5 - load_sprite.getLocalBounds().width / 2);
		m_window.clear(sf::Color(0, 90, 0));
		m_window.draw(load_sprite);
		m_window.display();
		m_next_state =  "GameStateA";
		return false;
	}
	m_window.clear(sf::Color(0, 90, 0));
	m_window.draw(m_background_sprite);
	m_window.draw(m_continue_btn_sprite);
	m_window.display();
	return true;
}

std::string UpgradeState::Next()
{
	return m_next_state;
}

bool UpgradeState::IsType(const std::string &type)
{
	return type.compare("UpgradeState") == 0;
}