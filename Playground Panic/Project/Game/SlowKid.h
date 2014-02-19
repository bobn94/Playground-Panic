#include "stdafx.h"
#include "Enemy.h"

class SlowKid : public Enemy{
public:
	SlowKid(sf::Sprite* sprite, float radius);
	SlowKid(sf::Vector2f spawn_pos);
	~SlowKid();
	void SetSprite();
	void Update(float deltatime, float global_speed, sf::Vector2f playerPos, sf::Vector2f origin, sf::Vector2f target);
private:
	float m_pi;
	sf::Sprite *m_slow_kid_sprite;
	sf::Texture *m_slow_kid_texture;
	sf::Vector2f m_velocity;
	sf::Vector2f m_player_position;
};