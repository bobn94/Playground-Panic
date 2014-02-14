#include "stdafx.h"
#include "Collider.h"
#include <cmath>

Collider::Collider()
	:m_position(0.0f, 0.0f)
,m_extention(0.0f, 0.0f)
{

}

Collider::Collider(const sf::Vector2f &position, const sf::Vector2f &extention)
	:m_position(position)
	,m_extention(extention){

	}

bool Collider::Overlap(Collider &other, Collider &self, sf::Vector2f &offset){
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
							other.m_position.x += -dx;
						}
						else

						{
							offset.x = dx;
							other.m_position.x += dx;
						}
				}
 				else
					{
						if(self.m_position.y < other.m_position.y)
						{
							offset.y = -dy;
							other.m_position.y += -dy;
						}
						else

						{
							offset.y = dy;
							other.m_position.y += dy;
						}
    
					
					}
				
				
				return true;
			}
		}
		return false;
	}