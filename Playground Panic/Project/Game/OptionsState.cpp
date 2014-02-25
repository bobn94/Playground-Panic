#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "OptionsState.h"
#include "StateManager.h"


OptionsState::OptionsState() {
	m_done = false;
	m_resetHighScore = false;
	m_changetoGameState = false;

	
};


bool OptionsState::Enter() {
	return true;
};

void OptionsState::Exit() {


};

bool OptionsState::Update(float deltatime, sf::RenderWindow& m_window, sf::View &m_view) {
	
	
	
	return !m_done;
};

void OptionsState::Initialize() {
	
}

/*void OptionsState::Draw(DrawManager* m_draw_manager) {
	TTF_Init();
	
	m_draw_manager->Draw(m_BackgroundSprite, 0, 0);

	
	TTF_Font* m_font = TTF_OpenFont("../data/fonts/duckhunt.ttf", 250);
	SDL_Color m_foregroundColor = { 72, 205, 222 };
	SDL_Color m_backgroundColor = { 0, 0, 0 };
	SDL_Surface* screen = TTF_RenderText_Shaded(m_font, "Duck", m_foregroundColor, m_backgroundColor);
	m_draw_manager->Draw(screen, 170, 100);
	SDL_FreeSurface(screen);
	screen = TTF_RenderText_Shaded(m_font, "Hunt", m_foregroundColor, m_backgroundColor);
	m_draw_manager->Draw(screen, 320, 300);
	SDL_FreeSurface(screen);


	SDL_Color m_foregroundColor2 = { 255, 255, 255 };
	m_font = TTF_OpenFont("../data/fonts/emulogic.ttf", 35);
	screen = TTF_RenderText_Shaded(m_font, "Reset highscore", m_foregroundColor2, m_backgroundColor);
	m_draw_manager->Draw(screen, 255, 550);
	SDL_FreeSurface(screen);


	screen = TTF_RenderText_Shaded(m_font, "Start game", m_foregroundColor2, m_backgroundColor);
	m_draw_manager->Draw(screen, 350, 630);
	SDL_FreeSurface(screen);


	m_draw_manager->Draw(
		m_resethighscoretext->GetSprite(),
		m_resethighscoretext->GetPosition().m_x,
		m_resethighscoretext->GetPosition().m_y);

	m_draw_manager->Draw(
		m_gametext->GetSprite(),
		m_gametext->GetPosition().m_x,
		m_gametext->GetPosition().m_y);


	int highscore[10];
	std::ifstream stream("../data/score/score.txt");
	if(!stream.is_open()){
		return;
	}


	std::string row;
	unsigned int cords_count = 0;
	stream >> cords_count;
	std::getline(stream, row);
	for(unsigned int i = 0; i < cords_count; i++){
		std::getline(stream, row);
		std::stringstream ss(row);
		std::string ch;
		int score;
		ss >> ch;
		ss >> highscore[i];
	}
	


	std::stringstream hisc;

	hisc <<  highscore[0];

	SDL_Color m_foregroundColor3 = { 64, 228, 48 };
	screen = TTF_RenderText_Shaded(m_font, "Highscore: ", m_foregroundColor3, m_backgroundColor);
	m_draw_manager->Draw(screen, 230, 750);
	SDL_FreeSurface(screen);
	screen = TTF_RenderText_Shaded(m_font, hisc.str().c_str(), m_foregroundColor3, m_backgroundColor);
	m_draw_manager->Draw(screen, 630, 750);
	SDL_FreeSurface(screen);


	for(auto i = 0UL; i < m_objects.size(); i++){
		m_draw_manager->Draw(m_objects[i]->GetSprite(), 
			m_objects[i]->GetPosition().m_x, 
			m_objects[i]->GetPosition().m_y);

	}

	
	TTF_Quit();
};
*/
std::string OptionsState::Next() {
	return m_next_state;
};

bool OptionsState::IsType(const std::string &type) {
	return type.compare("OptionsState") == 0;
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

 void OptionsState::ResetHighscore(){
	if (m_resetHighScore = true) {
		std::ofstream ostream("../data/score/score.txt");
		ostream.clear();
		ostream << "10\n";
		for (int i = 0; i <= 9; ++i){
			ostream << (i+1);
			ostream << " ";
			ostream << 0;
			ostream << "\n";
		}
	};
}