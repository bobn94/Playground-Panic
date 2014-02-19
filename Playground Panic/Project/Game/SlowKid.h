#include "stdafx.h"
#include "Enemy.h"

class PlayerObject;
class CountdownTimer;


class SlowKid : public Enemy{
public:
	SlowKid(sf::Sprite* sprite, float radius, int atkTimer);
	SlowKid(sf::Vector2f spawn_pos);
	~SlowKid();
	void SetSprite();
	void Update(float deltatime, float global_speed, PlayerObject* player, sf::Vector2f origin, sf::Vector2f target);
private:
	float m_pi;
	CountdownTimer* m_attack_timer;
	sf::Sprite *m_slow_kid_sprite;
	sf::Texture *m_slow_kid_texture;
	sf::Vector2f m_velocity;
	sf::Vector2f m_player_position;
};