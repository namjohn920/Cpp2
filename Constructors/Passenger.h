// TODO: add file header comments here
/* Workshop 4
   HyunKyu Nam
   141031161
   hnam7@myseneca.ca*/

// TODO: add header file guard here
#ifndef _SICT_PASSENGER_H_
#define _SICT_PASSENGER_H_

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char pname[32];
		char dest[32];
		int year;
		int month;
		int day;

	public:
		Passenger();
		Passenger(const char* a, const char* b, int y, int m, int d);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};


}

#endif 
