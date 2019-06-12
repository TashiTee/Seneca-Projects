/**********************************************************
Workshop 7 - Derived Classes in lab
// Workshop <Workshop #7>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Hero.h
**********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H 

namespace sict
{
	const int max_rounds = 100;

	class Hero
	{
	private:
		char m_name[41];
		int m_health;
		int m_attack;
		int  m_maximumHealth;

	public:
		Hero();
		Hero(const char p_name[], int p_health, int p_attack);
		void operator-=(int p_attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* getName() const;
		int getHealth() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H 
