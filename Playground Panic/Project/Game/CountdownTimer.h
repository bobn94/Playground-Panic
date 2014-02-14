#pragma once
#include "stdafx.h"

class CountdownTimer{
public:
	CountdownTimer();
	void SetTime(int hours, int minutes, int seconds);
	void Update();
	void Reset();
	void Start();
	void Stop();
	bool Done();
	int Seconds;
	int Minutes;
	int Hours;
private:
	sf::Clock clocks;
	sf::Time time;
	bool ticking;
	int defaultSeconds;
	int defaultMinutes;
	int defaultHours;
};