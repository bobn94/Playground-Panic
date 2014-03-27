
#pragma once

#include "stdafx.h"
class Collider;
class Sprite;

class GameObject
{
	friend class Level;
	friend class MenuState;
	friend class OptionsState;
public:
	GameObject();
	GameObject(sf::Texture* texture, float radius = 32, sf::Texture* dirt_texture = nullptr, std::string filepath = "", int flag = 0);
	virtual ~GameObject();

	struct Frame {
		float duration;
		int x, y, width, height;
	};

	const sf::Vector2f &GetPosition() const;
	void SetPosition(const sf::Vector2f &position);
	bool HasTexture() const;
	sf::Texture* GetTexture();
	bool HasCollider() const;
	Collider* GetCollider();
	sf::Sprite* GetSprite();
	//sf::Shape* HasShape();
	float GetRadius();
	void LoadAnimation(std::string path, sf::Texture* texture2);
	void UpdateFrame(float deltatime);

	void Draw(sf::RenderWindow *window);

private:
	float m_time;
	int m_current_frame;

protected:
	sf::Vector2f m_position;
	sf::Texture* m_texture;
	sf::Texture* m_dirt_texture;
	Collider *m_collider;
	int m_flag;
	sf::Sprite* m_dirt_sprite1;
	sf::Sprite* m_sprite;
	float m_radius;
	std::vector<Frame> m_animation;
	bool m_animated;
};