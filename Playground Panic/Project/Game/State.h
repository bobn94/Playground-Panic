#pragma once
#include <string>

class SpriteManager;
class DrawManager;
class Level;

class State {
public:
	virtual ~State() {};
	virtual bool Enter() = 0;
	virtual void Exit() = 0;
	//virtual bool Update(float deltatime) = 0;
	virtual bool Update(float deltatime, sf::RenderWindow& m_window, sf::View& m_view, Level& level) = 0;
	//virtual void Draw(DrawManager* m_draw_manager) = 0;
	virtual std::string Next() = 0;
	virtual bool IsType(const std::string &type) = 0;
};
