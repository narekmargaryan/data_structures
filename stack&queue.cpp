#include <iostream>

using namespace std;

template <class T> class node {
public:
    node() {};
    node(T t) { e = t; }
    T e;
    node *next;
    void set(T t) {
        e = t;
    }
    T get() {
        return e;
    }
};

template <class T> class stack {
public:
    stack() { head = NULL; }
    node <T> *head, *temp1, *temp2;

    void push(T t) {
        if ( head == NULL )
        {
            head = new node <T>;
            head->set(t);
            head->next = NULL;
        }
        else {
            temp1 = head;
            while ( temp1->next != NULL ) {
                temp1 = temp1->next;
            }
            temp1->next = new node <T>;
            temp1->next->set(t);
        }
    }

    void pop() {
        if ( head == NULL ) {;}
        else if ( head->next == NULL) {
            delete head;
            head = NULL;
        }
        else {
            temp1 = head;
            while ( temp1->next->next != NULL )
                temp1 = temp1->next;
            delete temp1->next;
            temp1->next = NULL;
            }
    }

    T gettop() {
      temp1 = head;
      if (temp1 == NULL) {;}
      else {
        while ( temp1->next != NULL )
              temp1 = temp1->next;
        return temp1->get();
      }
    }

    bool is_empty() {
        return head==NULL? true:false;
    }

    void print() {
        temp1 = head;
        while ( temp1 != NULL )
        {
            cout<<temp1->get()<<endl;
            temp1 = temp1->next;
        }
        cout<<endl;
    }

    ~stack() {
        temp1 = head;
        temp2 = head;
        while (temp1 != NULL) {
        temp2 = temp1;
        delete temp1;
        temp1 = temp2->next;
        }
    }
};

template <class T> class queue {
public:
    queue() { head = NULL; }
    node <T> *head, *temp1, *temp2;

    void enqueue(T t) {
        if ( head == NULL ) {
            head = new node <T>;
            head->set(t);
            head->next = NULL;
        }
        else {
            temp1 = head;
            while ( temp1->next != NULL )
                temp1 = temp1->next;
            temp1->next = new node<T>;
            temp1->next->set(t);
        }
    }

    void dequeue() {
        if (head == NULL) {;}
        else if (head->next == NULL) {
            delete head;
            head = NULL;
        }
        else {
            temp1 = head;
            head = head->next;
            delete temp1;
        }
    }

    T get_front() {
        if ( head == NULL ) {;}
        else
            return head->get();

    }

    bool is_empty() {
        return head == NULL ? true : false;
    }

    void print() {
        temp1 = head;
        while ( temp1 != NULL )
        {
            cout<<temp1->get()<<endl;
            temp1 = temp1->next;
        }
        cout<<endl;
    }

};

int main() {
    queue<char> s;
    for (int i = 97; i < 100; i++)
        s.enqueue((char)i);
    s.print();
cout<<    s.get_front();
s.dequeue();
cout<<s.get_front();
cout<<s.is_empty();

    return 0;
}
