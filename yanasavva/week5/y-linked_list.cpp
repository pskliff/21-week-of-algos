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
    Node<T> *head = nullptr;
    typedef Node<T>* tNode;


    int getLength()
    {
        tNode curr = head;
        int len = 0;
        while (curr)
            ++len, curr = curr->next;

        return len;
    }

    void addNode(T value)
    {
        if (head == nullptr)
            head = new Node<T>(value);
        else
        {
            Node<T> *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = new Node<T>(value);
        }

    }


//    void print()
//    {
//        Node<T> *curr = head;
//        while (curr)
//            cout << curr->value << " ", curr = curr->next;
//
//        cout << endl;
//    }
};

template <typename T>
class Y_LinkedList
{
public:

    typedef Node<T>* tNode;

    LinkedList<T> ll1;
    LinkedList<T> ll2;
    void merge(int ind)
    {
        if (ind >= ll1.getLength() || !ll1.head || !ll2.head)
            return;

        tNode curr1 = ll1.head;
        while(--ind > 0)
            curr1 = curr1->next;

        tNode curr2 = ll2.head;
        while(curr2->next)
            curr2 = curr2->next;
        curr2->next = curr1;

    }

    tNode find_merge_point()
    {
        if (!ll1.head || !ll2.head)
            return nullptr;

        int len1 = ll1.getLength();
        int len2 = ll2.getLength();

        tNode curr1 = ll1.head;
        tNode curr2 = ll2.head;
        for (int i = 0; i < len1 - len2; ++i)
            curr1 = curr1->next;

        for (int i = 0; i < len2 - len1; ++i)
            curr2 = curr2->next;

        while (curr1 != curr2)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr1;
    }
};


int main() {
    ifstream fin;
    fin.open("in.txt");

    Y_LinkedList<int> y_linkedList;
    int n1, n2, initial_ind;
    fin >> n1 >> n2 >> initial_ind;
    int numb;
    for (int i = 0; i < n1; ++i) {
        fin >> numb;
        y_linkedList.ll1.addNode(numb);
    }

    for (int i = 0; i < n2; ++i) {
        fin >> numb;
        y_linkedList.ll2.addNode(numb);
    }

    y_linkedList.merge(initial_ind);

    LinkedList<int>::tNode point = y_linkedList.find_merge_point();
    printf("pointer = %p; value = %d", point, point->value);

    return 0;
}

