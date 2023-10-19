
#include <iostream>
#include <ostream>
#include <math.h>
#include <cstring>

class Cstring
{
public:
	char* word_;
	Cstring();
	Cstring(char*& word);
	Cstring(const Cstring& word);
	Cstring(Cstring&& word);
	~Cstring(); 
	Cstring& operator=(const Cstring &c); // assignment operator
};
