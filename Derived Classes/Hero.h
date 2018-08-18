#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>

namespace sict {
	const int max_rounds = 100;

	class Hero {

		char name[41];
		int health;
		int attack;
		
	public:
		//constructior and destructor
		Hero();
		Hero(const char *_name, int _health, int _attack);
		~Hero();

		//member functions
		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;

		//friend
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);

	
	
	


}




#endif // !_HERO_H_
