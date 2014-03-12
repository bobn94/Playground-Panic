#pragma once
#include "stdafx.h"


class Level
{
public:
	Level();
	void NextDay();
	int GetDay();
	int GetWeek();
	int GetKidsToSpawn();
	int GetSpecialToSpawn();
private:
	int m_day;
	int m_week;
	int m_kid_amount;
	int m_special_amount;
};