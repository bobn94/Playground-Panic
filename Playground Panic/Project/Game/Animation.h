#pragma once
#include "stdafx.h"
#include <string>
#include <vector>

class Animation : public sf::Sprite {
public:
	Animation(sf::Texture texture, int x, int y, int width, int height);


	struct Frame {
		float duration;
		int x, y, width, height;
	};


	void Update(float deltatime);
	void AddFrame(Frame &frame);
	Animation* Load(std::string &filename, std::string &img_path);

private:
	float m_time;
	int m_current_frame;
	std::vector<Frame> m_animation;
};
