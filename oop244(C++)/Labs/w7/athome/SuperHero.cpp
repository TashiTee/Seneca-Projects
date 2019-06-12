/**********************************************************
Workshop 7 - Derived Classes at home
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: SuperHero.cpp
**********************************************************/
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

namespace sict {

	SuperHero::SuperHero() : Hero() {

		md_superAttack = 0;
		md_defence = 0;
	}
	SuperHero::SuperHero(const char *name, int health, int damage, int super, int def) : Hero(name, health, damage) {

		if (name[0] != '\0' || health != 0) {

			md_superAttack = super;
			md_defence = def;

		}
		else {
			*this = SuperHero();
		}
	}

	int SuperHero::attackStrength() const {

		if (Hero::attackStrength() != 0) {

			return Hero::attackStrength() + md_superAttack;
		}
		else {
			return 0;
		}
	}

	int SuperHero::defend() const {
		if (md_defence != 0) {

			return md_defence;
		}
		else {
			return 0;
		}
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int count = 0;
		SuperHero one = first;
		SuperHero two = second;

		std::cout << "Super Fight! " << first << " vs " << second;
		for (int i = 0; i < max_round && (one.isAlive() && two.isAlive()); ++i) {

			one.Hero::operator-=(two.attackStrength() - one.defend());
			two.Hero::operator-=(one.attackStrength() - two.defend());
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