#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *next;
    Node<T>(T value) : value(value), next (nullptr){}
};

template <typename T>
class LinkedList
{
public:
   Node<T> *head;

    void addNode(T value)
    {
        if (head == nullptr)
            head = new Node<T>(value);
        else
        {
            Node<T> *curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = new Node<T>(value);
        }

    }

    void reverseNode(Node<T> *first, Node<T> *second)
    {

        if (!second->next)
        {
            head = second;
            second->next = first;
            return;
        }
        else reverseNode(second, second->next);
        second->next = first;
        first->next = nullptr;

    }

    void reverseList()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        reverseNode(head, head->next);
    }

    void print()
    {
        Node<T> *curr = head;
        while (curr)
            cout << curr->value << " ", curr = curr->next;

        cout << endl;
    }
};

int main() {
    ifstream fin;
    fin.open("in.txt");

    LinkedList<int> linkedList;
    int n;
    fin >> n;
    int numb;
    for (int i = 0; i < n; ++i) {
        fin >> numb;
        linkedList.addNode(numb);
    }
    linkedList.print();

    linkedList.reverseList();

    linkedList.print();
    return 0;
}

