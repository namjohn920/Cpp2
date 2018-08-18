
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#pragma once

#include "iAccount.h"

namespace sict {
   
	class Account : public virtual iAccount {

		double currentBalance;

	protected:
		double balance() const;


	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};

	
}
#endif
