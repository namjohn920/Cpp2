#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
//HyunKyu Nam
//141031161
//hnam7@myseneca.ca

namespace sict {
	
	const int max_name_length = 40;
	const int min_sin= 100000000;
	const int max_sin =999999999;
	const int max_yrs = 4;

	class CRA_Account
	{
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
		//CRA_Account();


	private:
		char fname[max_name_length];
		char gname[max_name_length];
		int sin;
		int taxYear[max_yrs] = { 0 };
		double balance[max_yrs] = {};
		int numYear;


	};

}




#endif


