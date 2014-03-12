#pragma once
#include <vector>

class State;
class DrawManager;
class SpriteManager;
class Level;

class StateManager {
public:
	StateManager();
	~StateManager();

	 void Attach(State *state);
	 void Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view, Level& level);
	 //void Draw(DrawManager* m_draw_manager);
	 void SetState(const std::string &type);
	 void ChangeState();
	 bool IsRunning();

	 bool isRunning;
	 State *m_current;
private:
	std::vector<State*> m_states;
	
};