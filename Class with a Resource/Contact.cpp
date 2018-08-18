//HyunKyu Nam
//141031161
//hnam7@myseneca.ca

#include <iostream>
#include <cstring>
#include "Contact.h"


using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		num = 0;
		phone = nullptr;
	}

	Contact::Contact(const char* name2, const long long * phone2, int num2) {
		
		if (name2 == nullptr) {
			*this = Contact();
		}
		else {
			strncpy(name, name2, 20);
			name[19] = '\0';
			bool legit;
			int count = 0;
			
			if (phone2 != nullptr) {

				for (int i = 0; i < num2; i++) {
					legit = valid(phone2[i]);
					if (legit) count++;
				}
				num = count;
				phone = new long long[num];

				for (int i = 0, j = 0; i < num2; i++) {
					legit = valid(phone2[i]);
					if (legit) {
						phone[j] = phone2[i];
						j++;
					}
				}


			}
			else
			{
				phone = nullptr;
				num = 0;
			}
			

		}


	}



	Contact::~Contact() {
		delete[] phone;
	}

	bool Contact::isEmpty() const {
		if (name[0] == '\0')
			return true;
		else return false;
			
	}

	void Contact::display() const {


		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {


			cout << name << endl;
			for (int i = 0; i < num; i++) {

				long long a = phone[i] / 10000000000LL;
				long long b = (phone[i] % 10000000000LL) / 10000000LL;
				long long c = ((phone[i] % 10000000000LL) % 10000000LL) / 10000LL;
				long long d = ((phone[i] % 10000000000LL) % 10000000LL) % 10000LL;


				cout << "(+" << a << ") " << b << " " << c << "-";

				if (d < 1000) {
					cout.fill('0');
					cout.width(4);
					cout << d << endl;
				}
				else
					cout << d << endl;
			}

		}
	}

	bool Contact::valid(const long long phone2) {

		bool a = phone2 < 999999999999LL && phone2 >= 10000000000LL &&
			(phone2 % 10000000000LL) >= 1000000000LL && (phone2 % 10000000LL) >= 1000000LL;

		return a;

	}

	Contact::Contact(const Contact& source) {//Copy Constructor

	
		strncpy(name, source.name, 20);
		name[19] = '\0';
		num = source.num;


		if (source.phone != nullptr) {
			bool legit;
			int count=0;

			for (int i = 0; i < source.num; i++) {
				legit = valid(source.phone[i]);
				if (legit) count++;
			}
			num = count;
			phone = new long long[num];

			for (int i = 0, j = 0; i < source.num; i++) {
				legit = valid(source.phone[i]);
				if (legit) {
					phone[j] = source.phone[i];
					j++;
				}
			}

		}else {
			phone = nullptr;
		}


	}

	Contact& Contact::operator=(const Contact& source) {
		if (this != &source) {
			strncpy(name, source.name, 20);
			name[19] = '\0';
			num = source.num;
			
			delete[] phone;
			if (source.phone != nullptr) {
				phone = new long long[num];
				for (int i = 0; i < num; i++) {
					phone[i] = source.phone[i];

				}
			}
			else
			{
				phone = nullptr;
			}
				
		}
		return *this;
	}

	Contact& Contact::operator+=(long long source) {
		bool legit;
		legit = valid(source);

		if (legit) {
			num++;
			long long* temp = nullptr;
			temp = new long long[num];

			for (int i = 0; i < (num - 1); i++) {
				temp[i] = phone[i];
			}

			delete[] phone;
			phone = nullptr;
			phone = temp;

			phone[num - 1] = source;
					
		}
		
			
			return *this;
		


	}


}