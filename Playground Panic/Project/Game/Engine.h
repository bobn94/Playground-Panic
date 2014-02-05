#pragma once
#include "StateManager.h"
#include "GameStateA.h"
#include "OptionsState.h"
#include "MenuState.h"
#include "stdafx.h"

class Engine{
public:
	Engine();
	~Engine();
	void Initialize();
	void Run();
	void Cleanup();

private:
	sf::RenderWindow m_window;
};