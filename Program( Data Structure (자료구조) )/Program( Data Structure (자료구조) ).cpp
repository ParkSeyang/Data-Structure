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

			head->next = newNode;

			head = newNode;
		}

		size++;
	}

	void push_front(T data)
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
	
			head->next = newNode;
			
		}
		size++;
	}
	
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty(Pop_back) " << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* currentNode = head;
			if (true)
			{
				
			}
			else
			{
				currentNode->next->next =
			}
			size--;

			delete deleteNode;
		}
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty(Pop_front) " << endl;
		}
		else
		{
			Node* deleteNode = head->next; // delete노드가 헤드를 가리킴
			if (head == head->next)
			{
				head = nullptr;
			}
			// if (size == 1) // 노드가 한개일때 head를 nullptr로 해줌
			// {
			// 	head = nullptr;
			// }
			else // 노드가 두개이상일때 
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;

			size--;
		}

	}
	~CircleLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
	const int& Size()
	{
		return size;
	}

	 void show()
	 {
	 	if (head != nullptr)
	 	{
	 		Node* currentNode = head->next;
	 
	 		for (int i = 0; i < size; i++)
	 		{
	 			cout << currentNode->data << " ";
	 
	 			currentNode = currentNode->next;
	 		}
	 
	 	}
	 }
	 
	// void show()
	// {
	// 	 Node* currentNode = head->next;
	// 	do
	// 	{
	// 		cout << "CurrentNode Data : " << currentNode->data << endl;
	// 
	// 		currentNode = currentNode->next;
	// 
	// 	} while (currentNode != head->next);
	// 
	// }
};



int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.push_back(10);
	circleLinkedList.push_back(20);
	circleLinkedList.push_back(30);

	cout << endl;

	circleLinkedList.pop_front();
	circleLinkedList.pop_front();
	circleLinkedList.pop_front();
	circleLinkedList.pop_front();

	cout << endl;

	circleLinkedList.show();


	circleLinkedList.push_front(5);
	
	circleLinkedList.push_front(10);
	
	circleLinkedList.push_front(15);
	
	circleLinkedList.show();


	return 0;
}