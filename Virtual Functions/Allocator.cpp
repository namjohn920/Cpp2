#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	const double rate = 0.05;	
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;
		
	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* accountType, double initialBalance) {

		iAccount* account = nullptr;
		//if the type of account statrs with uppercase s, the function creates a savings account in dynamic memory
		if (accountType[0] == 'S') {

			account = new SavingsAccount(initialBalance, rate);

		}
		else if (accountType[0] == 'C') {

			account = new ChequingAccount(initialBalance, transactionFee, monthlyFee);

		}
		//return the address of accont created
		return account;

	}








}
