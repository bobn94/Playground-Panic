#include "stdafx.h"
#include "Engine.h"

Engine::Engine(){

}
Engine::~Engine(){

}
void Engine::Initialize(){
	

}
void Engine::Run(){
	StateManager mgr;
		mgr.Attach(new MenuState());
		mgr.Attach(new GameStateA());
		mgr.Attach(new OptionsState());
		mgr.SetState("MenuState");

		mgr.isRunning = true;
		sf::RenderWindow m_window(sf::VideoMode(1024, 640), "Playground Panic");
		while(mgr.IsRunning()){
			sf::Event event;
			while(m_window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				mgr.isRunning = false;
			}
		}
		
		}
}
void Engine::Cleanup(){

}