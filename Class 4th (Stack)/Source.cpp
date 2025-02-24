#include <iostream>

#define SIZE 5

using namespace std;

template<typename T>

class Stack
{
private:
	int top;
	int size;
	T Container[SIZE];
public:
	Stack()
	{
		top = -1;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			Container[i] = NULL;
		}
	}
	void push(T data)
	{
		if (top >= SIZE - 1)
		{
			cout << "Stack Over flow " << endl;
		}
		else
		{
			Container[++top] = data;
		}

	}

	void pop()
	{
		if (Empty())
		{
			cout << "Stack is empty " << endl;
		}
		else
		{
			top--;
		}
	}
	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	const int& Size()
	{
		size = top + 1;
		return size;
	}

	const T& Top()
	{
		return Container[top];
	}

};


int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	cout << "Stack Size : " << stack.Size() << endl;

	while (stack.Empty() == false)
	{
		cout << stack.Top() << endl;
		stack.pop();
	}



	return 0;
}