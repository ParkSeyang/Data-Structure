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
		if (head == nullptr) // 제거 할 노드가 없을때 작동
		{
			cout << endl << "Linked List is Empty (pop_back)" << endl;
			return;
		}
		else if (head->next == nullptr) // 제거 할 노드가 1개일시 작동
		{
			delete head;
			head = nullptr;
		}
		else // 제거 할 노드가 2개 이상일시 작동
		{
			Node* previousNode = head;

			while (previousNode->next->next != nullptr) // 마지막 "직전" 노드를 찾은후 멈춘다
			{
				previousNode = previousNode->next;
			}
			Node* deleteNode = previousNode->next;
			previousNode->next = nullptr; // 기존에 previousNode->next가 마지막 노드를 가리키고 있었는데, nullptr로 만들어 마지막 노드를 리스트에서 제거
			delete deleteNode; // 마지막 노드를 가리키는 "deleteNode" 메모리해제
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

	cout << endl;

	singleLinkedList.Show();

	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();
	singleLinkedList.pop_back();

	return 0;
}

