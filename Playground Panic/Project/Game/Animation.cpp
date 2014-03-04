#pragma once
#include "stdafx.h"
#include "Animation.h"
#include <fstream>
#include <sstream>
#include <map>
#include <string>


Animation::Animation(sf::Texture texture, int x, int y, int width, int height)
	: sf::Sprite(texture, sf::IntRect(x, y, width, height)) {
	m_time = 0.0f;
	m_current_frame = 0;
	
};

void Animation::Update(float deltatime) {
	m_time += deltatime;
	if(m_time >= m_animation[m_current_frame].duration) {
		m_time = 0.0f;
		m_current_frame = ++m_current_frame % m_animation.size();

		Frame &frame = m_animation[m_current_frame];
		setTextureRect(sf::IntRect(frame.x, frame.y, frame.width, frame.height));
	};
};

void Animation::AddFrame(Frame &frame) {
	m_animation.push_back(frame);
};
Animation* Animation::Load(std::string &filename, std::string &img_path){
		std::ifstream stream;
		stream.open(filename.c_str());
		if(!stream.is_open()){
			return nullptr;
		}
		std::string row;
		stream >> row;
		
		sf::Texture texture;
		texture.loadFromFile(img_path);

		Animation *sprite = new Animation(texture, 0, 0, 0, 0);

		while(!stream.eof()){
			std::getline(stream, row);
			if(row.length() == 0){
				continue;
			}
			std::stringstream ss(row);

			Animation::Frame frame;

			ss >> frame.duration;
			ss >> frame.x;
			ss >> frame.y;
			ss >> frame.width;
			ss >> frame.height;
			sprite->AddFrame(frame);

		}
	
		
		stream.close();
		return sprite;
	}
