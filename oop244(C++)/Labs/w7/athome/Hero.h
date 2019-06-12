/**********************************************************
Workshop 7 - Derived Classes at home
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Hero.h
**********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {

	const int max_round = 100;
	const int max_length = 40;

	class Hero {
		char m_name[max_length];
		int m_healthPoint;
		int m_attackDamage;
	public:
		Hero();
		Hero(const char * name, int health, int damage);
		void operator -=(int attack);
		int attackStrength() const;
		bool isAlive() const;
		friend std::ostream& operator << (std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !SICT_HERO_H
