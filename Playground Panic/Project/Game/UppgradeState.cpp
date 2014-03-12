#pragma once
#include "stdafx.h"
#include <iostream>
#include "UppgradeState.h"

UpgradeState::UpgradeState(){
	m_done = false;
}
bool UpgradeState::Enter(){
	if (!m_continue_btn_texture.loadFromFile("../data/textures/continue_btn.png"))
	{
		std::cout << "Loading Error";
	}
	m_continue_btn_texture.setSmooth(true);
	
	m_continue_btn_sprite.setTexture(m_continue_btn_texture);
	m_continue_btn_sprite.setOrigin(m_continue_btn_sprite.getLocalBounds().width / 2, m_continue_btn_sprite.getLocalBounds().height / 2);
	return true;
}
void UpgradeState::Exit(){

}
bool UpgradeState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level){
	m_continue_btn_sprite.setPosition(1080 / 2, m_window.getSize().y / 2);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
		sf::Texture loading;
			if (!loading.loadFromFile("../data/textures/Loading.png"))
			{
				// This shit shouldn't happen
			}

			sf::Sprite load_sprite(loading);
			load_sprite.setPosition(m_window.getSize().x / 2 - load_sprite.getLocalBounds().width / 2, m_window.getSize().y / 1.5 - load_sprite.getLocalBounds().width / 2);
			m_window.clear(sf::Color(0, 90, 0));
			m_window.draw(load_sprite);
			m_window.display();
		m_next_state =  "GameStateA";
		return false;
	}
	m_window.clear(sf::Color(0, 90, 0));
	m_window.draw(m_continue_btn_sprite);
	m_window.display();
	return true;
}
void UpgradeState::Initialize(){

}
std::string UpgradeState::Next(){
	return m_next_state;
}
bool UpgradeState::IsType(const std::string &type){
	return type.compare("UpgradeState") == 0;
}