#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	int size;
	
	struct Node
	{
		T data;	
		Node* next;
		Node* previous;
	};
	
	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		if (head == nullptr)
		{
			head = newNode->data;
			tail = newNode->data;
		}
		else
		{
			newNode->previous = newNode->next;
			newNode->next = previous;
			newNode->next = nullptr;
		}
		size++;
	}

};


int main()
{
	DoubleLinkedList<int> doubleLinkedList;
	doubleLinkedList.push_front(5);
	return 0;
}