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
	void push_front(T data) // 강사님이 만든 예제
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	// void push_front(T data) // 내가만든 예제
	// {
	// 	Node* newNode = new Node;
	// 	newNode->data = data;
	// 	if (head == nullptr) // 노드가 1개일시
	// 	{
	// 		head = newNode;
	// 		tail = newNode;
	// 		newNode->next = nullptr;
	// 		newNode->previous = nullptr;
	// 	}
	// 	else // 노드가 두개 일시
	// 	{
	// 		newNode->next = head;
	// 		newNode->previous = nullptr;
	// 		head->previous = newNode;
	// 		head = newNode;
	// 	}
	// 	size++;
	// }
	void pop_front()
	{

		if (tail == nullptr) // 노드가 없는데 기능을 작동할시
		{
			cout << "Linked List is Empty(Pop_front) " << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail) // 노드가 1개일시 작동
			{
				head = nullptr;
				tail = nullptr;
			}
			else // 노드가 2개이상일시 작동
			{
				deleteNode->next->previous = nullptr;

				head = head->next;
			}

			delete deleteNode;
		}

		size--;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is Empty(Pop_back) " << endl;
		}
		else
		{
			Node* deleteNode = tail;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				tail->previous->next = nullptr;

				tail = tail->previous;
			}
			delete deleteNode;

			size--;
		}

	}

	const int& Size()
	{
		return size;
	}

	void show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << "CurrentNode Data : " << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

};


int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.push_front(30);
	doubleLinkedList.push_front(20);
	doubleLinkedList.push_front(10);

	doubleLinkedList.show();

	doubleLinkedList.pop_front();
	doubleLinkedList.pop_front();
	doubleLinkedList.pop_front();

	cout << endl;

	doubleLinkedList.push_back(10);
	doubleLinkedList.push_back(20);
	doubleLinkedList.push_back(30);

	doubleLinkedList.show();

	cout << endl;

	doubleLinkedList.pop_back();
	doubleLinkedList.pop_back();
	doubleLinkedList.pop_back();
	doubleLinkedList.pop_back();

	cout << "Linked List is Size : " << doubleLinkedList.Size() << endl;

	doubleLinkedList.show();




	return 0;
}