#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>
class LinearQueue
{
private:
	int rear;
	int front;

	T Container[SIZE];
public:

	LinearQueue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			Container[i] = NULL;
		}

	}

	void push(T data)
	{
		if (SIZE <= rear)
		{
			cout << "LinearQueue Overflow " << endl;
		}
		else
		{
			Container[rear++] = data;
		}

	}
	void pop()
	{
		if (empty())
		{
			cout << "LinearQueue is Empty " << endl;
		}
		else
		{
			Container[front++] = NULL;
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
		if (empty())
		{
			cout << "Linear Queue is Empty" << endl;
			exit(1);
		}
		else
		{
			return Container[front];
		}
	}
	const int& Size()
	{
		return rear - front;
	}
};


int main()
{
	LinearQueue<int> linearQueue;

	linearQueue.push(10);
	linearQueue.push(20);
	linearQueue.push(30);
	linearQueue.push(40);
	linearQueue.push(50);

	cout << "Linear Queue Size : " << linearQueue.Size() << endl;

	while (linearQueue.empty() == false)
	{
		cout << linearQueue.Front() << " ";
		linearQueue.pop();
	}



	return 0;
}