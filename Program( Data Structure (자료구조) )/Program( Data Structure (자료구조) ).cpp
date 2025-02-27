#include <iostream>

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

	cout << "String Size : " << string.Size() << endl;

	return 0;
}