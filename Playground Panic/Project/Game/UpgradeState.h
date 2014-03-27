#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include "State.h"


class SpriteManager;
class Sprite;
class GameObject;
class Level;

class UpgradeState : public State {
public:
	UpgradeState();
	
	bool Enter();
	void Exit();
	bool Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level);
	void Initialize();
	std::string Next();
	bool IsType(const std::string &type);
private:
	std::string m_next_state;
	bool m_done;
	sf::Texture m_continue_btn_texture;
	sf::Sprite m_continue_btn_sprite;
	sf::Texture m_background_texture;
	sf::Sprite m_background_sprite;
};