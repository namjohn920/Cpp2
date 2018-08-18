//HyunKyu Nam
//141031161
//hnam7@myseneca.ca


#include <iostream>
#include <iomanip>
#include "CRA_Account.h"
#include <cstring>

using namespace std;
namespace sict {


	void CRA_Account::set(int a, double b) {
		
		
		
		
		for (int i = 0; i < max_yrs; i++) {

			if (taxYear[i] == 0) {

				taxYear[i] = a;
				balance[i] = b;
				break;
			}
			


		}
		


	}

	void CRA_Account::set(const char* a, const char* b, int c) {

	
		int wsum = 0;
		
		int number[9];
		int j = 0;
		int sinnum = c;

		for (int x = 1; x <= 9; ++x) {


			number[j] = sinnum % 10;
			sinnum = sinnum / 10;

			if (j != 0 && (j % 2) == 0) {
				wsum += number[j];
			}
			else if (j != 0 && (j % 2) != 0) {
				int num = 0;
				number[j] = number[j] * 2;

				for (int y = 0; y < 2;y++) {

					num = number[j] % 10;
					number[j] = number[j] / 10;
					wsum += num;

				}


			}

			j++;
		}

		int high = ((wsum / 10) + 1) * 10;
		int diff = high - wsum;
	

	

		if (diff==number[0] && c <= max_sin && c >= min_sin && strlen(a) > 0 && strlen(b) >0 ) {

			

			numYear = 0;
			strncpy(fname, a, (strlen(a)+1));   //copy Family Name input to fname
			strncpy(gname, b, (strlen(b)+1));	//copy Given Name input to gname
			sin = c;



		}
		else {

			sin = 1;

		}


	}

	bool CRA_Account::isEmpty() const {

		if (sin == 1) {
			return true;
		}
		else
			return false;

	}
	void CRA_Account::display() const {

		if (isEmpty()) {

			cout << "Account object is empty!" << endl;
			
		}
		else {
			
			cout << "Family Name: " << fname << endl;
			cout << "Given Name : " << gname << endl;
			cout << "CRA Account: " << sin << endl;
			
			for (int i = 0; i < max_yrs; i++) {

				if (taxYear[i] != 0) {
					cout << fixed;
					cout << setprecision(2);

					if (balance[i] > 2)
						cout << "Year (" << taxYear[i] << ") balance owing: " << balance[i] << endl;
					else if (balance[i] < -2)
						cout << "Year (" << taxYear[i] << ") refund due: " << -(balance[i]) << endl;
					else
						cout << "Year (" << taxYear[i] << ") No balance owing or refund due!" << endl;

				}
				else
					break;
			}
			

			

		}
			


	}

}