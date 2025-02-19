#include <iostream>

using namespace std;

template <typename T>
class CircleLinkedList
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

	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	
	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->data = newNode;

			head = newNode;
		}

		size++;
	}

	void show()
	{
		Node* currentNode = head;
		while (currentNode->next != head)
		{
			cout << "CurrentNode Data : " << currentNode->data << endl;

			currentNode = currentNode->next;
		}
	}
};



int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);

	circleLinkedList.show();
	return 0;
}