#include "stdafx.h"
#include "Collider.h"
#include <cmath>

Collider::Collider()
:m_position(0,0)
	,m_extention(0,0){

}

Collider::Collider(sf::Vector2f position, sf::Vector2f extention)
	:m_position(position)
	,m_extention(extention){

	}

bool Collider::Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2, sf::Vector2f &offset){
	if(sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)) + ((origo2.x - origo1.x)*(origo2.x - origo1.x))) < radius1 + radius2){
		offset.x = (radius1 + radius2) - sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)));
		offset.y = (radius1 + radius2) - sqrt(((origo2.x - origo1.x)*(origo2.x - origo1.x)));
		return true;
	}
	else{
		return false;
	}
}
bool Collider::Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2){
	if(sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)) + ((origo2.x - origo1.x)*(origo2.x - origo1.x))) < radius1 + radius2){
		return true;
	}
	else{
		return false;
	}
}
bool Collider::Overlap(Collider &self, Collider &other, sf::Vector2f &offset){
	float A = self.m_extention.x * 0.5f;
		float B = other.m_extention.x * 0.5f;
		float C = (self.m_position.x + A) - (other.m_position.x + B);

		if(fabs(C) < A + B){
			float Q = self.m_extention.y * 0.5f;
			float P = other.m_extention.y * 0.5f;
			float Z = (self.m_position.y + Q) - (other.m_position.y + P);
			if(fabs(Z) <= Q + P){
				float dx = fabs(C) - (A+B);
				float dy = fabs(Z) - (Q+P);
				if(dx >= dy && dy < -1)
				{
					if(self.m_position.x < other.m_position.x)
						{
							offset.x = -dx;
							//other.m_position.x += -dx;
						}
						else

						{
							offset.x = dx;
							//other.m_position.x += dx;
						}
				}
 				else
					{
						if(self.m_position.y < other.m_position.y)
						{
							offset.y = -dy;
							//other.m_position.y += -dy;
						}
						else

						{
							offset.y = dy;
							//other.m_position.y += dy;
						}
    
					
					}
				
				
				return true;
			}
		}
		return false;
}