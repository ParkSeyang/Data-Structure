#include <iostream>

#define SIZE 6
using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};
	Bucket bucket[SIZE];


public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}
	template<typename T>
	const int& HashFunction(T key)
	{
		unsigned int hashIndex = (int)key % SIZE;

		return hashIndex;
	}
	template<>
	const int& HashFunction(const char* key)
	{
		int hash = 0;

		for (int i = 0; i < strlen(key); i++)
		{
			hash += key[i];
		}
		int hashIndex = hash % SIZE;

		return hashIndex;

	}
	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}
	void Insert(KEY key, VALUE value)
	{
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 새로운 노드를 생성합니다.
		Node* newNode = CreateNode(key, value);

		// 노드가 1개라도 존재 하지 않는다면

		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]의 head 포인터가 newNode 를 가리키게 합니다.
			bucket[hashIndex].head = newNode;

		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex] 의 count 를 증가시킵니다.
		bucket[hashIndex].count++;
	}

	void Remove(KEY key)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 2. Node를 탐색할 수 있는 포인터 변수 선언
		Node* currentNode = bucket[hashIndex].head;

		// 3. 이전 Node 를 저장할수있는 포인터 변수 선언
		Node* previousNode = nullptr;

		// 4. currentNode 가 nullptr 과 같다면 함수를 종료합니다.
		currentNode = bucket[hashIndex].head;

		if (currentNode == nullptr) // current Node가 nullptr을 가리키고있다면 아무것도없다고 출력한다.
		{
			cout << "Not Key Found" << endl;

			return;
		}
		else // bucket[hashIndex].head안의 key 값이 1개이상이라도 있을경우
		{
			// 5. currentNode를 이용해서 내가 찾고자 하는 Key 값을 찾습니다.
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)  // 노드의 key와 주어진 key를 비교
				{

					if (currentNode == bucket[hashIndex].head) // 첫 번째 노드를 삭제하려는 경우
					{
						bucket[hashIndex].head = currentNode->next; // 현재 노드가 헤드인 경우
					}
					else
					{
						previousNode->next = currentNode->next; // 중간이나 마지막 노드를 삭제하려는 경우
					}

					// 메모리 해제

					bucket[hashIndex].count--;

					delete currentNode;

					return;
				}
				else  // 원하는 key를 못찾았을경우 노드를 계속 탐색
				{
					previousNode = currentNode;

					currentNode = currentNode->next;
				}

			}
			cout << "Not Key Found" << endl;
		}

	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}

			}


		}


	}
};



int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.Insert("Sword", 10000);
	hashtable.Insert("Armor", 5000);

	hashtable.Remove("Sword");
	hashtable.Remove("Armor");
	hashtable.Remove("Zero");


	return 0;
}