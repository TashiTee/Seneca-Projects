/**********************************************************
Workshop 7 - Derived Classes at home
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: SuperHero.h
**********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

namespace sict {
	class SuperHero :public Hero {

		int md_superAttack;
		int md_defence;

	public:
		SuperHero();
		SuperHero(const char *name, int health, int damage, int super, int def);
		int attackStrength() const;
		int defend() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}

#endif // !SICT_SUPERHERO_H