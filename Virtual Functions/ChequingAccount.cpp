// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double initialBalance, double transactionFee, double monthEndFee):Account(initialBalance) {
		if (transactionFee < 0) {
			transaction = 0.0;
		}
		else
		{
			transaction = transactionFee;
		}

		if (monthEndFee < 0) {
			monthFee = 0.0;
		}
		else
		{
			monthFee = monthEndFee;
		}
	}

	

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double credit) {

		bool sucess = Account::credit(credit);

		if (sucess == true) {
			Account::debit(transaction);			
		}

		return sucess;

	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double debit) {

		bool sucess = Account::debit(debit);

		if (sucess == true) {
			Account::debit(transaction);
		}

		return sucess;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {

		Account::debit(monthFee + transaction);

	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {

		double balance = Account::balance();
		os << "Account type: Chequing";
		//sets the decimal point to two places
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "\nBalance: $" << balance;		
		os << "\nPer Transaction Fee: " << transaction;
		os << "\nMonthly Fee: " << monthFee << std::endl;
	}



}