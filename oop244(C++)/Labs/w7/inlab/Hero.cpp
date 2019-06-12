/**********************************************************
Workshop 7 - Derived Classes in lab
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Hero.cpp
**********************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"

using namespace std;

namespace sict
{
	Hero::Hero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
		m_maximumHealth = 0;
	}

	Hero::Hero(const char p_name[], int p_health, int p_attack)
	{
		if (*p_name != '\0' && p_health != 0 && p_attack != 0)
		{
			m_name[0] = '\0';
			strncpy(m_name, p_name, strlen(p_name));
			m_name[strlen(p_name)] = '\0';

			m_attack = p_attack;
			m_maximumHealth = p_health;
			m_health = p_health;
		}
		else {
			*this = Hero();
		}
	}
	// Receives an attack strength
	// if p_attack > 0
	// m_health -= p_attack
	// else, do nothing
	// If m_attack is 0 or -, set m_health to 0
	void Hero::operator-=(int p_attack)
	{
		if (p_attack > 0 && m_health > 0) {

			m_health -= p_attack;

			if (m_health < 0) {

				m_health = 0;
			}
		}
	}

	// Returns true if the object is health
	bool Hero::isAlive() const
	{
		return (m_health > 0) ? true : false;
	}

	// return the attack strength of current object
	int Hero::attackStrength() const
	{
		if (m_attack > 0)
			return m_attack;
		else
			return 0;
	}

	const char* Hero::getName() const
	{
		return m_name;
	}

	int Hero::getHealth() const
	{
		return m_health;
	}

	// inserts the hero.m_name into os
	// Return a reference to the stream
	// if hero.m_name[0] = '\0'
	// display "No hero"
	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		if (hero.m_name[0] != '\n' && hero.m_health != -1 && hero.m_attack != -1)
			os << hero.m_name;
		else
			os << "No hero";
		return os;
	}

	// Returns a reference to the winner of the battle between the heroes
	// Display the names of the battle participants
	// Makes local copies of the participants
	// Determine the damage that each inflicts on the other in a single attack
	// Battle until one of them dies
	// Display the name of the winner
	// if draw, the first is the winner
	const Hero& operator*(const Hero& first, const Hero& second)
	{
		Hero left = first, right = second, winner;
		int round = 0;

		for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
		{
			left -= right.attackStrength();
			right -= left.attackStrength();
			round = i;
		}
		round++;

		if (!left.isAlive() && !right.isAlive())
		{
			winner = left;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}
		else if (!left.isAlive())
		{
			winner = right;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return second;
		}

		else if (!right.isAlive())
		{
			winner = left;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}
		else
		{
			return first;
		}
	}
}
