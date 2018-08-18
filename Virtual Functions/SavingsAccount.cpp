#include <iostream>
#include <cstring>

#include "Account.h"
#include "SavingsAccount.h"

namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interest): Account(balance) {
		//if interest received is postive, it initialize the interest rate of savings account to that value
		//otherwise, it will initialize the interest rate to zero
		if (interest > 0)
			interestRate = interest;
		else
			interestRate = 0.0;

	}


	// TODO: perform month end transactions
	void SavingsAccount::monthEnd() {

		//it is a temporary variable to store the interest charge
		double interestCharge;

		//this will acccess to the protected member function to get the current balance of the account
		double balance = Account::balance();

		//interest charge is simply current blance multiplied by interest rate
		interestCharge = balance * interestRate;

		//this will add credit interest charge to the current balance
		Account::credit(interestCharge);

	}


	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os) const {

		double balance = Account::balance();
		os << "Account type: Savings";
		//sets the decimal point to two places
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "\nBalance: $" << balance;
		//to make the interest rate to %, 100 is multiplied
		os << "\nInterest Rate (%): " << interestRate *100 <<  std::endl;


	}




}

