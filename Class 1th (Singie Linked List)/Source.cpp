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
		Node* next;
	};

	Node* head;


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
		size++;
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
			cout << endl << "Linked List is Empty (pop_back)" << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* previousNode = nullptr;

			if (size == 1)
			{
				head = deleteNode->next;

				delete deleteNode;
			}

			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}

				previousNode->next = deleteNode->next;

				delete deleteNode;
			}

			size--;
		}

	}
	// void pop_back()
	// {
	// 	if (head == nullptr)
	// 	{
	// 		cout << endl << "Linked List is Empty (pop_back)" << endl;
	// 		return;
	// 	}
	// 	else if (head->next == nullptr)
	// 	{
	// 		Node* deleteNode = head;
	// 		head = nullptr;
	// 		delete deleteNode;
	// 	}
	// 	else
	// 	{
	// 		Node* previousNode = head;
	// 		Node* deleteNode = previousNode->next;
	// 
	// 		while (deleteNode->next != nullptr)
	// 		{
	// 			deleteNode = deleteNode->next;
	// 			previousNode = previousNode->next;
	// 		}
	// 		previousNode->next = nullptr;
	// 		delete deleteNode;
	// 	}
	// 
	// 	size--;
	// 
	// }

	const int& Size()
	{
		return size;
	}

	~SingleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
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

	cout << endl;

	singleLinkedList.Show();

	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();

	cout << "Linked List is Size : " << singleLinkedList.Size() << endl;


	return 0;
}

