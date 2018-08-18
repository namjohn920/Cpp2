// TODO: add file header comments here
/* Workshop 4
HyunKyu Nam
141031161
hnam7@myseneca.ca*/

#define _CRT_SECURE_NO_WARNINGS

// TODO: add your headers here
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		pname[0] = '\0';
		dest[0] =  '\0' ;
		year = 0;
		month = 0;
		day = 0;


	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* a, const char* b, int y, int m, int d) {
	

		if (a=='\0' || b=='\0' || y > 2020 || y<2017 || m > 31 || m < 1 || d >31 || d < 1) {

			pname[0] = '\0';
			dest[0] = '\0';

		}
		else {
		
			strcpy(pname, a);
			pname[strlen(a)] = '\0';
			strncpy(dest, b, strlen(b));
			dest[strlen(b)] = '\0';
			year = y;
			month = m;
			day = d;

		}


	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		
		if (strlen(pname) == 0 || strlen(dest) == 0) {
			return true;
		}
		else return false;

	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << pname << " " << "-" << " " << dest << " on " << year << "/";
			cout.fill('0');
			cout.width(2);
			cout << month << "/" << day << endl;
				}
		

	}

	//Implement name query
	//a query that returns the address of the name of the passenger; 
	//the address of an empty string if the Passenger object is in a safe empty state.
	const char* Passenger::name() const {

		return this->pname;


	}

	//Implement canTravelWith query
	bool Passenger::canTravelWith(const Passenger& a) const {
	
		if (!strcmp(this->dest,a.dest) && this->year == a.year && this->month == a.month && this->day == a.day)
			return true;
		else return false;
	}
}

