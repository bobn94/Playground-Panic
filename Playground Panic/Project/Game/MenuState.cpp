#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MenuState.h"
#include "StateManager.h"


MenuState::MenuState() {
	m_done = false;
	m_changetoGameState = false;

	
};


bool MenuState::Enter() {
	if (!m_background_texture.loadFromFile("../data/textures/Menu_bg.png"))
	{
		// This shit shouldn't happen
	}
	m_background_texture.setSmooth(true);

	if (!m_start_game_texture.loadFromFile("../data/textures/start_game_btn.png"))
	{
		// This shit shouldn't happen
	}
	m_start_game_texture.setSmooth(true);

	if (!m_options_texture.loadFromFile("../data/textures/options_btn.png"))
	{
		// This shit shouldn't happen
	}
	m_options_texture.setSmooth(true);

	if (!m_exit_game_texture.loadFromFile("../data/textures/exit_game_btn.png"))
	{
		// This shit shouldn't happen
	}
	m_exit_game_texture.setSmooth(true);

	m_background_sprite.setTexture(m_background_texture);

	m_start_game_sprite.setTexture(m_start_game_texture);

	m_options_sprite.setTexture(m_options_texture);

	m_exit_game_sprite.setTexture(m_exit_game_texture);

	m_start_game_sprite.setOrigin(182, 63);
	m_options_sprite.setOrigin(182, 63);
	m_exit_game_sprite.setOrigin(182, 63);
	return true;
};

void MenuState::Exit() {


};

bool MenuState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view) {
	

	m_start_game_sprite.setScale(m_window.getSize().x / 1920.0f, m_window.getSize().y / 1080.0f);
	m_options_sprite.setScale(m_window.getSize().x / 1920.0f, m_window.getSize().y / 1080.0f);
	m_exit_game_sprite.setScale(m_window.getSize().x / 1920.0f, m_window.getSize().y / 1080.0f);
	
	//m_background_sprite.setPosition(m_view.getCenter().x - m_view.getSize().x / 2, m_view.getCenter().y - m_view.getSize().y / 2);
	m_start_game_sprite.setPosition(m_window.getSize().x / 2,  m_window.getSize().y / 5);
	m_options_sprite.setPosition(m_window.getSize().x / 2,  m_window.getSize().y / 5 * 2);
	m_exit_game_sprite.setPosition(m_window.getSize().x / 2,  m_window.getSize().y / 5 * 3);
	
	m_window.clear(sf::Color(0, 90, 0));
	//m_window.draw(m_background_sprite);
	m_window.draw(m_start_game_sprite);
	m_window.draw(m_options_sprite);
	m_window.draw(m_exit_game_sprite);
	
	m_window.display();

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		
		if(sf::Mouse::getPosition().x - m_window.getPosition().x + 20 >= m_start_game_sprite.getPosition().x && sf::Mouse::getPosition().x - m_window.getPosition().x + 20 <= m_start_game_sprite.getPosition().x + m_start_game_sprite.getOrigin().x * 2 && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 >= m_start_game_sprite.getPosition().y && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 <= m_start_game_sprite.getPosition().y + m_start_game_sprite.getOrigin().y * 2){
			m_next_state =  "GameStateA";
			return false;
		}
		else if(sf::Mouse::getPosition().x - m_window.getPosition().x + 20 >= m_options_sprite.getPosition().x && sf::Mouse::getPosition().x - m_window.getPosition().x + 20 <= m_options_sprite.getPosition().x + m_options_sprite.getOrigin().x * 2 && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 >= m_options_sprite.getPosition().y && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 <= m_options_sprite.getPosition().y + m_options_sprite.getOrigin().y * 2){
			m_next_state =  "OptionsState";
			return false;
		}
		else if(sf::Mouse::getPosition().x - m_window.getPosition().x + 20 >= m_exit_game_sprite.getPosition().x && sf::Mouse::getPosition().x - m_window.getPosition().x + m_view.getCenter().x + 20 <= m_exit_game_sprite.getPosition().x + m_exit_game_sprite.getOrigin().x * 2 && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 >= m_exit_game_sprite.getPosition().y && sf::Mouse::getPosition().y - m_window.getPosition().y + 30 <= m_start_game_sprite.getPosition().y + m_start_game_sprite.getOrigin().y * 2){
			m_window.close();
		}
	}

	return true;
};

void MenuState::Initialize() {
	
}


std::string MenuState::Next() {
	return m_next_state;
};

bool MenuState::IsType(const std::string &type) {
	return type.compare("MenuState") == 0;
};

 /*bool OptionsState::CheckCrosshairCollision(Vector2 &offset, SpriteManager* sprite_manager) {
	if(isOn = true) {
	StateManager mgr;
	 
	 if(SDL_BUTTON(1)) {
		for (auto i = 0UL; i < m_objects.size(); i++){
			if(m_objects[i]->HasCollider()) {
				Vector2 off;
					if(m_objects[i]->GetCollider()->Overlap(*m_resethighscoretext->GetCollider(), off)){

					if((off.m_x != 0 && off.m_x != offset.m_x) || (off.m_y != 0 && off.m_y != offset.m_y)){
						offset += off;
					}
				}

				if(offset.Length() > 0.0f && m_resetit){
				m_resetHighScore = true;
				return true;
			}

				if(m_objects[i]->GetCollider()->Overlap(*m_gametext->GetCollider(), off)){

					if((off.m_x != 0 && off.m_x != offset.m_x) || (off.m_y != 0 && off.m_y != offset.m_y)){
						offset += off;
					} 
				}

			}


			if(offset.Length() > 0.0f && m_GoGamestate){
				mgr.SetState("GameState");
				m_changetoGameState = true;
				return true;
			}
		return false;
	}
	 }}
 }
 */
