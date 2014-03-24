#pragma once
#include "stdafx.h"
#include "Level.h"

Level::Level(){
	m_day = 1;
	m_week = 1;
	m_score = 0;
}
void Level::NextDay()
{
	if (m_day >= 5){
		m_day = 1;
		++m_week;
	}
	else{
		++m_day;
	}
}
int Level::GetDay()
{
	return m_day;
}
int Level::GetWeek()
{
	return m_week;
}
int Level::GetKidsToSpawn()
{
	if (m_week > 1){
		m_kid_amount = (2 + ((m_day - 1) * 3) - 5) + 5 + (12 * (m_week - 1));
	}
	else
	{
		m_kid_amount = (2 + ((m_day - 1) * 3) - 4);
	}
	return m_kid_amount;
}
int Level::GetSpecialToSpawn()
{
	if (m_week > 1){
		m_kid_amount = (2 + (m_day * 3) - 5) + 5 + (12 * (m_week - 1));
	}
	else
	{
		m_kid_amount = (2 + (m_day * 3) - 4);
	}
	m_special_amount = m_kid_amount / 3 + 1;
	return m_special_amount;
}