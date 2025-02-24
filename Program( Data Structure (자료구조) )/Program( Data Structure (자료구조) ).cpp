#include <iostream>

#define SIZE 4

using namespace std;

template<typename T>
class CircieQueue
{
private:

	int front;
	int rear;
	T Container[SIZE];

public:
	CircieQueue()
	{
		front = SIZE-1;
		rear = SIZE-1;
		for (int i = 0; i < SIZE; i++)
		{
			Container[i] = NULL
		}

	}

};


int main()
{

	return 0; 
}