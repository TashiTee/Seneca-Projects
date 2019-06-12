/**********************************************************
Workshop 7 - Derived Classes at home
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Hero.cpp
**********************************************************/
#include <fstream>
#include <cstring>
#include <iostream>
#include "Hero.h"

namespace sict {

	Hero::Hero() {
		m_name[0] = '\0';
		m_healthPoint = 0;
		m_attackDamage = 0;
	}
	Hero::Hero(const char * name, int health, int damage) {
		if (name[0] != '\0' || health != 0) {

			strncpy(m_name, name, max_length);
			m_name[max_length - 1] = '\0';
			m_healthPoint = health;
			m_attackDamage = damage;

		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator -=(int attack) {
		if (attack > 0) {
			m_healthPoint -= attack;
		}
		if (m_healthPoint < 0) {
			m_healthPoint = 0;
		}
	}
	int Hero::attackStrength() const {

		return m_attackDamage;
	}

	bool Hero::isAlive() const {

		return m_healthPoint > 0;
	}

	std::ostream& operator << (std::ostream& os, const Hero& hero) {
		if (hero.m_name) {
			os << hero.m_name;
			return os;
		}
		else {
			os << "No hero";
			return os;
		}
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero one = first;
		Hero two = second;
		int count = 0;

		std::cout << "Ancient Battle! " << first << " vs " << second;

		for (int i = 0; i < max_round && (one.isAlive() && two.isAlive()); ++i) {

			one.operator-=(two.attackStrength());
			two.operator-=(one.attackStrength());
			count++;

		}

		if (two.isAlive()) {
			std::cout << " : " << "Winner is " << two << " in " << count << " rounds." << std::endl;

			return second;
		}
		else {
			std::cout << " : " << "Winner is " << one << " in " << count << " rounds." << std::endl;

			return first;
		}
	}

}