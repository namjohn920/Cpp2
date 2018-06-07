//John HyunKyu Nam
//namjohn920@gmail.com


#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


namespace sict {
	
	struct Kingdom {
		char m_name[32];
		int m_population;

	};

	void display(const Kingdom &a);

	void display(const Kingdom *b, int c);
}
#endif