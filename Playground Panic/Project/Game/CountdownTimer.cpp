#include "stdafx.h"
#include <iostream>
#include "CountdownTimer.h"

	CountdownTimer::CountdownTimer(){
		ticking = false;
		Seconds = 0;
		Minutes = 0;
		Hours = 0;
}
	void CountdownTimer::SetTime(int hours, int minutes, int seconds){
		defaultHours = hours;
		defaultMinutes = minutes;
		defaultSeconds = seconds;
	}
	void CountdownTimer::Update(){
		if(ticking){
			time = clocks.getElapsedTime();
			Seconds = time.asSeconds();
			if(Seconds == 60){
				Minutes += 1;
				clocks.restart();
				Seconds = 0;
			}
			if(Minutes == 60){
				Hours += 1;
				Minutes = 0;
			}
			if(Hours == 24){
				Hours = 0;
			}
		}
	}
	void CountdownTimer::Reset(){
		Stop();
		
		Hours = 0;
		Minutes = 0;
		Seconds = 0;
		
	}
	void CountdownTimer::Start(){
		clocks.restart();
		ticking = true;
	}
	void CountdownTimer::Stop(){
		
		ticking = false;
	}
	bool CountdownTimer::Done(){
		if(Minutes >= defaultMinutes && Seconds >= defaultSeconds && Hours >= defaultHours){
			return true;
		}
		else{
			return false;
		}
	}