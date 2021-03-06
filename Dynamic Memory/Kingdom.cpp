
#include <iostream>
#include "Kingdom.h"
using namespace std;


namespace sict {
	//John HyunKyu Nam
	//namjohn920@gmail.com
	
	void display(const Kingdom &a) {
		
		cout << a.m_name << ", " << "population " << a.m_population << endl;
		
	}

	void display(const Kingdom *b, int c) {
		int total = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < c; i++) {
			
			cout << (i + 1) << ". " << b[i].m_name << ", population " << b[i].m_population  << endl;
			
			total += b[i].m_population;

		}
			cout << "------------------------------" << endl;
			cout << "Total population of SICT: " << total << "" << endl;
			cout << "------------------------------" << endl;
	}

}