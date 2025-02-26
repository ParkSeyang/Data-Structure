#include <iostream>

using namespace std;

template<typename T>

class Vector
{
private:
	int size;
	int capacity;
	T* container;
public:
	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;

	}
	void push_back(T data)
	{
		if (size == capacity)
		{
			resize(capacity * 2);
		}
		container[size] = data;
		size++;
	}
	void resize(int NewSize)
	{
		T* newContainer = new T[NewSize];

		if (size <= capacity)
		{
			container = NULL;
		}
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = container[i];
		}

		delete container;
		container = newContainer;

		size = NewSize;
	}
	
};


int main()
{
	Vector<int> vector;
	vector.resize(4);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);


	return 0;
}