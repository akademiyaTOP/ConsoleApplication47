#include <iostream>
#include <list>
#include <initializer_list>

using namespace std;

template <typename T> 
struct node {
    T value;
    node* next;
};

template <class T>
class List {
    node<T>* head = nullptr;
    node<T>* tail = nullptr;
    size_t count = 0;
public:
    List(const initializer_list<T>& list) {
        for (auto& item : list)
            this->add(item);
    }
    List() {}
    T operator[](int index) {
        if (index < 0 || index >= count)
            return NULL;
        int i = 0;
        node<T>* current = head;
        while (i != index) {
            current = current->next;
            i++;
        }
        return current->value;
    }
    int size() {
        return count;
    }
    void add(T value) {
        node<T>* newNode = new node<T>{ value, nullptr };
        if (!head)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        count++;
    }
    void print() {
        if (!head) {
            cout << "[]" << endl;
            return;
        }
        cout << "[ ";
        node<T>* current = head;
        while (current != tail) {
            cout << current->value << ", ";
            current = current->next;
        }
        cout << current->value << " ]" << endl;
    }
    void del(int index) {
        if (index < 0 || index >= count)
            return;
        int i = 0;
        node<T>* current = head;
        node<T>* pred = nullptr;
        while (i != index) {
            pred = current;
            current = current->next;
            i++;
        }
        if (!pred)
            head = head->next;
        else if (index == count - 1) {
            pred->next = nullptr;
            tail = pred;
        }
        else
            pred->next = current->next;
        delete current;
        count--;
    }
};

int main()
{
    List<int> lst;
    lst.print();
    lst.add(1);
    lst.print();
    lst.add(6);
    lst.add(100);
    lst.print();
    cout << lst.size() << endl;
    cout << lst[0] << " " << lst[2] << endl;
    List<int> lst2{ 4,6,8,10,30};
    lst2.print();
    lst2.del(2);
    lst2.print();
    lst2.del(0);
    lst2.del(2);
    lst2.print();
    cout << lst2.size();
    list<int> lst3{ 4,6,8,10,30 };
    for (auto& item : lst3) 
        cout << item << " ";
    cout << endl;
}

