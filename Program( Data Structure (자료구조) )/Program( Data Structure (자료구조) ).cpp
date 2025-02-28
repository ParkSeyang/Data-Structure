﻿#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* pointer;
	int size;

public:
	String()
	{
		size = 0;
		pointer = nullptr;
	}
	void operator=(const char * word)
	{
		size = strlen(word) + 1;
		if (pointer == nullptr)
		{
			pointer = new char[size];

			for (int i = 0; i < size; i++)
			{
				pointer[i] = word[i];
			}
		}
		else
		{
			char * newPointer = new char[size];

			for (int i = 0; i < size; i++)
			{
				newPointer[i] = word[i];
			}

			delete [ ] pointer;

			pointer = newPointer;
		
		}
	}

	const char& operator [ ] (const char & index)
	{
		return pointer[index];
	}

	void Append(const char * word)
	{
		int resize = size;

		// strlen(pointer) + strlen(word) +1;
		
		size = size + strlen(word) + 1;

		char* newPointer = new char[size];
		
		// strcpy(newPointer, pointer);

		// strcpy(newPointer, word);

		 for (int i = 0; i < resize; i++)
		 {
		 	newPointer[i] = pointer[i];
		 }
		 
		 for (int i = 0; i < strlen(word) + 1; i++)
		 {
		 	newPointer[resize + i] = word[i];
		 }

		if (pointer != nullptr)
		{
			delete[] pointer;
		}
		pointer = newPointer;

		// size = newSize;
	}

	long long Find(const char* word)
	{
		
		for (int i = 0; i < strlen(word); i++)
		{
			if (pointer != word)
			{
				for (int i = 0; i < size; i++)
				{

				}
			}
			else if ()
			{
				for ()
				{

				}
			}
		}
	}

	const int& Size()
	{
		return size - 1;
	}

	~String()
	{
		if (pointer != nullptr)
		{
			delete [ ] pointer;
		}
		
	}

};

int main()
{
	 String string;
	 
	 string = "Key";
	 
	 for (int i = 0; i<string.Size(); i++)
	 {
	 	cout << string[i];
	 }
	 
	 cout << endl;
	 
	 string = "Apple";
	 
	 for (int i = 0; i < string.Size(); i++)
	 {
	 	cout << string[i];
	 }
	 
	 cout << endl;
	 
	 string.Append(" Four");
	 string.Append(" x");


	 for (int i = 0; i < string.Size(); i++)
	 {
		 cout << string[i];
	 }

	 cout << "String Size : " << string.Size() << endl;

	 cout << endl;

	 

	// std::string str;
	// str.append("HEllo");
	// 
	// for (int i = 0; i < str.size(); i++)
	// {
	// 	cout << str[i] << endl;
	// }
	
	return 0;
}