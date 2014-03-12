#pragma once
#include "stdafx.h"
#include "UppgradeState.h"

UpgradeState::UpgradeState(){
	m_done = false;
}
bool UpgradeState::Enter(){
	if (!m_continue_btn_texture.loadFromFile("../data/textures/continue_btn.png"))
	{
		// This shit shouldn't happen
	}
	m_continue_btn_texture.setSmooth(true);
	
	m_continue_btn_sprite.setTexture(m_continue_btn_texture);
	m_continue_btn_sprite.setOrigin(m_continue_btn_sprite.getLocalBounds().width / 2, m_continue_btn_sprite.getLocalBounds().height / 2);
	return true;
}
void UpgradeState::Exit(){

}
bool UpgradeState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view){
	m_continue_btn_sprite.setPosition(m_window.getSize().x / 2, m_window.getSize().y);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
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