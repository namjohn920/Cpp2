#include <cstring>
#include <iostream>

#include "Account.h"
#include "iAccount.h"

namespace sict {
		
	Account::Account(double currentBalance2) {
		
		//If currentBalance2 received is positive, it initialize the currentBalance of the account to that value 
		//if currentBalance2 received is not positive, it initialize the currentBalance of the account to zero
		if (currentBalance2 > 0)
			currentBalance = currentBalance2;
		else
			currentBalance = 0;

	}

	
	bool Account::credit(double credit) {

		bool success;
		//If the credit value is postive, the success will be true and add the credit value to current balance
		if (credit > 0) {
			success = true;
			currentBalance += credit;
		}
		//If the credit value is not postive, the success will be false and does not add the credit value to current balance
		else 
		{
			success = false;			
		}

		return success;

	}


	bool Account::debit(double debit) {

		bool success;
		//If the debit value is postive, the success will be true and subtract the debit value to current balance
		if (debit > 0) {
			success = true;
			currentBalance -= debit;
		}
		//If the debit value is not postive, the success will be false and does notsubtract the debit value to current balance
		else
		{
			success = false;			
		}

		//then return the value of success, either true or false
		return success;

	}

	//protected member function
	double Account::balance() const {
		//it simply returns the current balance of the account
		return currentBalance;
	
	}




}
