#include <iostream>

#define SIZE 8

using namespace std;
template<typename T>
class PriorityQueue
{
private:
	int index;
	T container[SIZE];
public:
	PriorityQueue()
	{
		index = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}


};


int main()
{

	return 0;
}