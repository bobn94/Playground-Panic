#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "MenuState.h"
#include "StateManager.h"


MenuState::MenuState() {
	m_done = false;


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

	m_start_game_sprite.setOrigin(m_start_game_sprite.getLocalBounds().width / 2, m_start_game_sprite.getLocalBounds().height / 2);
	m_options_sprite.setOrigin(m_options_sprite.getLocalBounds().width / 2, m_options_sprite.getLocalBounds().height / 2);
	m_exit_game_sprite.setOrigin(m_exit_game_sprite.getLocalBounds().width / 2, m_exit_game_sprite.getLocalBounds().height / 2);
	return true;
};

void MenuState::Exit() {


};

bool MenuState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level) {
	m_view.setCenter(m_view.getSize().x / 2, m_view.getSize().y / 2);
	m_window.setView(m_view);

	if (m_window.getSize().x < 1200.0f)
	{
		m_background_sprite.setScale(m_window.getSize().x / 1080.0f, m_window.getSize().y / 720.0f);
	}
	else
	{
		m_background_sprite.setScale(1.4f, 1.4f);
	}
	m_start_game_sprite.setScale(m_window.getSize().x / 1080.0f, m_window.getSize().y / 720.0f);
	m_options_sprite.setScale(m_window.getSize().x / 1080.0f, m_window.getSize().y / 720.0f);
	m_exit_game_sprite.setScale(m_window.getSize().x / 1080.0f, m_window.getSize().y / 720.0f);

	m_background_sprite.setPosition(m_view.getCenter().x - m_view.getSize().x / 2, m_view.getCenter().y - m_view.getSize().y / 2);
	m_start_game_sprite.setPosition(m_view.getCenter().x / 2, m_view.getSize().y / 2);
	m_options_sprite.setPosition(m_view.getCenter().x / 2, m_view.getSize().y / 1.5);
	m_exit_game_sprite.setPosition(m_view.getCenter().x / 2, m_view.getSize().y / 1.2);


	m_window.clear(sf::Color(0, 90, 0));
	m_window.draw(m_background_sprite);
	m_window.draw(m_start_game_sprite);
	//m_window.draw(m_options_sprite);
	//m_window.draw(m_exit_game_sprite);

	m_window.display();
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
			m_window.close();
			return false;

		}

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

		
		sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window)) + static_cast<sf::Vector2f>(m_view.getCenter()) - static_cast<sf::Vector2f>((m_view.getSize() / 6.0f)) / 7.0f;

			mouse_position.y /= 2;
			mouse_position.x /= 2;
			mouse_position.y += 127;
			mouse_position.x -= 206;
		
		if (mouse_position.x + 20 >= m_start_game_sprite.getPosition().x
			&& mouse_position.x + 20 <= m_start_game_sprite.getPosition().x + m_start_game_sprite.getOrigin().x * 2
			&& mouse_position.y + 30 >= m_start_game_sprite.getPosition().y
			&& mouse_position.y + 30 <= m_start_game_sprite.getPosition().y + m_start_game_sprite.getOrigin().y * 2)
		{

			/*sf::Sprite load_sprite(loading);
			load_sprite.setPosition(m_window.getSize().x / 2 - load_sprite.getLocalBounds().width / 2, m_window.getSize().y / 1.5 - load_sprite.getLocalBounds().width / 2);
			m_window.clear(sf::Color(0, 90, 0));
			m_window.draw(m_background_sprite);
			m_window.display();*/

			m_next_state = "GameStateA";
			return false;
		}
		/*else if(mouse_position.x - m_window.getPosition().x + 20 >= m_options_sprite.getPosition().x
		&& mouse_position.x - m_window.getPosition().x + 20 <= m_options_sprite.getPosition().x + m_options_sprite.getOrigin().x * 2
		&& mouse_position.y - m_window.getPosition().y + 30 >= m_options_sprite.getPosition().y
		&& mouse_position.y - m_window.getPosition().y + 30 <= m_options_sprite.getPosition().y + m_options_sprite.getOrigin().y * 2)
		{
		m_next_state =  "OptionsState";
		return false;
		}
		else if(mouse_position.x - m_window.getPosition().x + 20 >= m_exit_game_sprite.getPosition().x
		&& mouse_position.x - m_window.getPosition().x + m_view.getCenter().x + 20
		<= m_exit_game_sprite.getPosition().x + m_exit_game_sprite.getOrigin().x * 2
		&& mouse_position.y - m_window.getPosition().y + 30 >= m_exit_game_sprite.getPosition().y
		&& mouse_position.y - m_window.getPosition().y + 30 <= m_start_game_sprite.getPosition().y + m_start_game_sprite.getOrigin().y * 2)
		{
			m_window.close();
		}*/
	}

	return true;
};

void MenuState::Initialize() 
{

}


std::string MenuState::Next() 
{
	return m_next_state;
};

bool MenuState::IsType(const std::string &type)
{
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
