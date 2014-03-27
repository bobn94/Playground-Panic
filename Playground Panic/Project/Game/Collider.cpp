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

bool Collider::Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2, sf::Vector2f &offset){//circle vs circle collision. Offset used to move an object after collision
	if(sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)) + ((origo2.x - origo1.x)*(origo2.x - origo1.x))) < radius1 + radius2){
		offset.x = (radius1 + radius2) - sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)));
		offset.y = (radius1 + radius2) - sqrt(((origo2.x - origo1.x)*(origo2.x - origo1.x)));
		return true;
	}
	else{
		return false;
	}
}

bool Collider::Overlap(Collider *map, sf::Vector2f origo1, float radius1, sf::Vector2f &offset)
{
	//Circle vs Box Collision
    for (int j = 0; j < 4; j++)
    {
        //hämta startpunkten
			
        sf::Vector2f A;
        //hämta slutpunkten
        sf::Vector2f B;
        if (j==0)
        {
			A = map->m_position;
			B = sf::Vector2f(map->m_position.x, map->m_position.y + map->m_extention.y);
        }
        else if(j == 1)
        {
            A = sf::Vector2f(map->m_position.x, map->m_position.y + map->m_extention.y);
			B = sf::Vector2f(map->m_position.x + map->m_extention.x, map->m_position.y + map->m_extention.y);
        }
		else if(j == 2){
			A = sf::Vector2f(map->m_position.x + map->m_extention.x, map->m_position.y + map->m_extention.y);
			B = sf::Vector2f(map->m_position.x + map->m_extention.x, map->m_position.y);
		}
		else if(j == 3){
			A = sf::Vector2f(map->m_position.x + map->m_extention.x, map->m_position.y);
			B = map->m_position;
		}
        sf::Vector2f C = origo1;
            
        //räkna ut avstånden mellan punkterna
        sf::Vector2f f = A - C;
        sf::Vector2f t = B - C;
        sf::Vector2f l = t - f;
            
            
        float a = l.x * l.x + l.y * l.y ;
        float b = 2*(l.x * f.x + l.y * f.y) ;
        float c = f.x * f.x + f.y * f.y - radius1*radius1 ;
            
        float discriminant = b*b-4*a*c;
        if( discriminant < 0 )
        {
            continue;
        }
        else
        {
            discriminant = sqrt( discriminant );
                
            // cirkeln kan penetreras på två olika punkter, ingångspunkten och utgångspunkten
            float t1 = (-b - discriminant)/(2*a);
            float t2 = (-b + discriminant)/(2*a);
                
            // om t1 och t2 är mellan 0 och 1 har linjen gått igenom cirkeln
            // om t1 eller t2 är mellan 0 och 1 har linjen gått in i men inte igenom cirkeln
            if( t1 >= 0 && t1 <= 1 )
            {
				if(j == 0){
					offset.x -= 1;
				}
				else if(j == 1){
					offset.y += 1;
				}
				else if(j == 2){
					offset.x += 1;
				}
				else if(j == 3){
					offset.y -= 1;
				}
                return true ;
					
            }
            if( t2 >= 0 && t2 <= 1 )
            {
				if(j == 0){
					offset.x -= 1;
				}
				else if(j == 1){
					offset.y += 1;
				}
				else if(j == 2){
					offset.x += 1;
				}
				else if(j == 3){
					offset.y -= 1;
				}
                return true ;
            }
            //om t1 och t2 är större än 1 eller mindre än 0 har linjen missat cirkeln helt
        }
            
    }
    
    //har den gått igenom alla former och kommit till slutet har ingen kollision sket mellan några punkter
    return false;
	
}
bool Collider::Overlap(sf::Vector2f origo1, sf::Vector2f origo2, float radius1, float radius2){//circle vs circle collision without offset to move an object
	if(sqrt(((origo2.y - origo1.y)*(origo2.y - origo1.y)) + ((origo2.x - origo1.x)*(origo2.x - origo1.x))) < radius1 + radius2){
		return true;
	}
	else{
		return false;
	}
}
bool Collider::Overlap(Collider &self, Collider &other, sf::Vector2f &offset){//Box VS Box collision with offset to move one of the boxes
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