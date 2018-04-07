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
    typedef Node<T>* tNode;


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


    void create_cycle(int ind)
    {
        tNode curr = head;
        tNode point = nullptr;
        while (curr->next)
        {
            if (--ind == 0)
                point = curr;
            curr = curr->next;
        }
        if (!point)
            point = head;
        curr->next = point;
    }


    tNode find_cycle(int &ind)
    {
        ind = -1;
        if (!head)
            return nullptr;
        tNode fast = head;
        tNode slow = head;
        while (fast->next && fast->next->next && slow->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast != slow)
            return nullptr;

        slow = head;
        ind = 1;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
            ++ind;
        }

        return fast;
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

int main() {
    ifstream fin;
    fin.open("in.txt");

    LinkedList<int> linkedList;
    int n, initial_ind;
    fin >> n >> initial_ind;
    int numb;
    for (int i = 0; i < n; ++i) {
        fin >> numb;
        linkedList.addNode(numb);
    }
    linkedList.create_cycle(initial_ind);

    int ind;
    LinkedList<int>::tNode point = linkedList.find_cycle(ind);
    printf("pointer = %p; ind = %d; value = %d", point, ind, point->value);

    return 0;
}

