#include <iostream>

using namespace std;

template <typename T>

class SingleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;


public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		if (head == nullptr)
		{
			head = newNode;

			newNode->data = data;
			newNode->next = nullptr;

		}
		else
		{
			newNode->data = data;
			newNode->next = head;
			head = newNode;
		}

		size++;
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		if (head == nullptr)
		{
			head = newNode;
			newNode->data = data;
			newNode->next = nullptr;
		}
		else
		{
			Node* currentNode = head;

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}
	}
	
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			head = deleteNode->next;

			delete deleteNode;
			
			size--;
		}
	}
	void Show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << "Node Data : " << currentNode->data << endl;

			currentNode = currentNode->next;
		}
	}

	void pop_back()
	{
		

		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* deleteNode = new Node;

			Node* previousNode = new Node;

			previousNode = head;

			while (previousNode->next != nullptr && previousNode->next->next != nullptr)
			{
				previousNode = previousNode->next;

			}
			deleteNode = previousNode->next;
			
			previousNode->next = nullptr;

		}

		size--;
	}

};



int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.push_front(10);
	singleLinkedList.push_front(20);
	singleLinkedList.push_back(5);
	singleLinkedList.push_back(10);
	
	singleLinkedList.Show();

	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
    return 0;
}

