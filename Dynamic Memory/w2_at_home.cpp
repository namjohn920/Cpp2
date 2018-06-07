//John HyunKyu Nam
//namjohn920@gmail.com


#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	sict::Kingdom* pkingdom = nullptr;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pkingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		
		read(pkingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pkingdom[0]);
	cout << "------------------------------" << endl << endl;

	
	sict::Kingdom* pkingdom2 = nullptr;
	pkingdom2 = new Kingdom[count + 1];
	
	for (int i = 0; i < count; i++) {
		pkingdom2[i] = pkingdom[i];
	}

	
	delete[] pkingdom;
	pkingdom = nullptr;
	
	pkingdom= pkingdom2;


	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	
	read(pkingdom[count]);
	count++;
	cout << "==========\n" << endl;

	
	display(pkingdom, count); 
	cout << endl;

	delete[] pkingdom2;
	pkingdom2 = nullptr;

	return 0;
}


void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
