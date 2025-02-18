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
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			newNode->next = nullptr;
			newNode->previous = nullptr;
		}
		else
		{
			newNode->next = head;
			newNode->previous = nullptr;
			head->previous = newNode;
			head = newNode;
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