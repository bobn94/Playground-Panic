#pragma once
#include "StateManager.h"
#include "GameStateA.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "stdafx.h"
#include "CountdownTimer.h"

class HealthBar;
class PlayerObject;
class Collider;
class ProjectileObject;
class SlowKid;

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	float m_deltatime;
	sf::Clock deltaClock;
	sf::RenderWindow m_window;
	sf::View m_view;
	float m_zoom;
};