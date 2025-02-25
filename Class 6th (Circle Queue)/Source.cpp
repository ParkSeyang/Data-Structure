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
		front = SIZE - 1;
		rear = SIZE - 1;
		for (int i = 0; i < SIZE; i++)
		{
			Container[i] = NULL;
		}

	}
	void push(T data)
	{

		if (front == (rear + 1) % SIZE)
		{
			cout << "Circie Queue Overflow " << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;
			Container[rear] = data;
		}
	}
	void pop()
	{
		if (empty())
		{
			cout << "Circie Queue is Empty(Pop) " << endl;
		}
		else
		{
			front = (front + 1) % SIZE;

			Container[front] = NULL;
		}
	}
	bool empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	const T& Front()
	{
		return Container[(front + 1) % SIZE];
	}

};


int main()
{
	CircieQueue<int> circieQueue;

	circieQueue.push(10);

	circieQueue.push(20);

	circieQueue.push(30);


	while (circieQueue.empty() == false)
	{
		cout << circieQueue.Front() << endl;

		circieQueue.pop();
	}

	circieQueue.push(40);
	circieQueue.push(50);
	circieQueue.push(60);

	return 0;
}