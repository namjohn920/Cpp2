//HyunKyu Nam
//141031161
//hnam7@myseneca.ca

#ifndef _CONTACT_H_
#define _CONTACT_H_

namespace sict {


	class Contact {

		char name[20];
		long long* phone;
		int num;

	public:
		Contact();
		Contact(const char*, const long long *, int);
		~Contact();
		bool isEmpty() const;
		void display() const;

		Contact(const Contact&);  //copy constructor
		Contact& operator=(const Contact&); //copy assignment operator
		Contact& operator+=(long long ); //overloaded operator

		bool valid(const long long);

	};




}

#endif // _CONTACT_H_
