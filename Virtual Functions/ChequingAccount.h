
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount:public Account                     {


		double transaction;
		double monthFee;



		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double initialBalance, double transactionFee, double monthEndFee);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double credit);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double debit);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
