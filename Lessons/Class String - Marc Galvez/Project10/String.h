#ifndef _CUSTOM_STRING
#define _CUSTOM_STRING


/*String class stores the characters as a sequence of bytes
with a functionality of allowing access to single byte character.*/

using namespace std;
typedef unsigned int uint;

class String {
public:
	char* string ;   //ASCII Characters
	uint length;   //Number of chars allocated in data

	String()  //Empty String
	{
		length = 0u;
		string = nullptr;
	}
	
	String(const char* my_char) //Character array String
	{
		uint n = 0;
		while (my_char[n] != '\0') { //strlen() without library 
			n++;
		}

		length = n;
		string = new char[length];
		
		for (uint i = 0; i < n; i++) {
			string[i] = my_char[i];
		}
	}

	String(const String &my_string) { //Copy String 
		length = my_string.length;
		string = new char[length];

		for (uint i = 0; i < length; i++) {
			string[i] = my_string.string[i];
		}
	}

	~String() //Destructor 
	{
		if (string != nullptr)
		{
			delete[] string;
			string = nullptr;
		}
	} 

	

	String operator=(const String &my_string) 
	{
		if (this == &my_string) return *this; //Optimize the process

		if (string != nullptr) {
			delete[] string;
			string = nullptr;
		}
		

		this->length = my_string.length;
		string = new char[length];

		for (uint i = 0; i < length; i++) {
			string[i] = my_string.string[i];
		}
		return *this;

	}

	String operator+= (const String &my_string) 
	{
		uint len = length + my_string.length;
		char* str = new char[len];

		for (unsigned i = 0; i < length; i++)
			str[i] = string[i];

		for (unsigned i = 0; i < my_string.length; i++)
			str[length + i] = my_string.string[i];

		delete string;
		length = len;
		string = str;
		return *this;
	}

	String operator+(const String &my_string) {
		return (*this+ my_string);
	}
	bool operator ==(const String &my_string) const {
		
		if (length != my_string.length) return false;
		uint n = 0;
		while (length < n && string[n] == my_string.string[n]) //This while increment n only if data[n] == my_string[n]
		{
			n++;
		}
		return (n == length); //Then, return true if n has incremented so far to equal lenght of my_string
	}

	String operator+(const char* my_char) {
		String c(my_char);
		return (*this + c);
	}
	bool operator ==(const char *my_char) const {
		String c(my_char);
		return (*this == c);
	}
};

#endif // !_CUSTOM_STRING

