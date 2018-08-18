#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

namespace sict {
	//DEFINTIONS FOR SUPERHEROES
	SuperHero::SuperHero() :Hero() {

		bonus = 0;
		defence = 0;


	}

	SuperHero::SuperHero(const char *_name, int _health, int _attack, int _bonus, int _defence) :Hero(_name, _health, _attack) {
		//first three parameters are initialized using Hero constructor and 
		//last two values are used for initialization using Superhero constructor
		bonus = _bonus;
		defence = _defence;

	}
	SuperHero::~SuperHero() {

	}
	int SuperHero::attackStrength() const {
		//call attackstrength() function of Hero class to get the attack strength for superhero
		int a = Hero::attackStrength();

		if (a != 0) {
			a += bonus;
		}

		return a;

	}

	int SuperHero::defend() const {
		//if superheroe's defence value is 0, return 0. otherwise just return defence
		if (defence == 0) {
			return 0;
		}
		else {
			return defence;
		}


	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

		//outputs the names of first and second heroes
		std::cout << "Super Fight! ";
		std::cout << first;
		std::cout << " vs ";
		std::cout << second;
		std::cout << " : ";



		//creating temporary variables
		SuperHero temp1 = first;
		SuperHero temp2 = second;

		int attack1 = temp1.attackStrength() - temp2.defend();
		int attack2 = temp2.attackStrength() - temp1.defend();


		for (int i = 0; i < max_rounds; i++) {

			temp1 -= attack2;
			temp2 -= attack1;
			//if both dies, first gets to win
			if (!temp1.isAlive() && !temp2.isAlive()) {
				std::cout << "Winner is ";
				std::cout << first;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return first;
				break;
			}
			//if first dies, second wins
			else if (!temp1.isAlive()) {
				std::cout << "Winner is ";
				std::cout << second;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return second;

				break;

			}//if second dies, first wins
			else if (!temp2.isAlive()) {
				std::cout << "Winner is ";
				std::cout << first;
				std::cout << " in ";
				std::cout << i + 1;
				std::cout << " rounds." << std::endl;
				return first;

				break;
			}


		}

		//if no one dies until the max rounds, first gets to win
		std::cout << "Winner is ";
		std::cout << first;
		std::cout << " in ";
		std::cout << max_rounds;
		std::cout << " rounds." << std::endl;
		return first;


	}

}