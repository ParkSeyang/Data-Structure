#include <iostream>

using namespace std;

template <typename T>
class SingleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}  // ✅ 생성자 추가 (가독성 ↑)
    };

    Node* head;
    int size;

public:
    SingleLinkedList() : head(nullptr), size(0) {}  // ✅ 멤버 초기화 리스트 사용

    void push_front(T data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(T data)
    {
        Node* newNode = new Node(data);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (!head)
        {
            cout << "Linked List is Empty (pop_front)" << endl;
            return;
        }

        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        size--;
    }

    void pop_back()
    {
        if (!head)
        {
            cout << "Linked List is Empty (pop_back)" << endl;
            return;
        }

        if (!head->next)  // 리스트에 노드가 하나만 있을 때
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next)  // 마지막 이전 노드를 찾음
            {
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }

        size--;
    }

    void Show() const
    {
        for (Node* current = head; current; current = current->next)
        {
            cout << "Node Data : " << current->data << endl;
        }
    }

    ~SingleLinkedList()  // ✅ 메모리 해제하는 소멸자 추가
    {
        while (head)
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

    cout << "\nAfter pop_back():\n";
    singleLinkedList.pop_back();
    singleLinkedList.Show();

    singleLinkedList.pop_back();
    singleLinkedList.pop_back();
    singleLinkedList.pop_back();
    singleLinkedList.pop_back();

    return 0;
}