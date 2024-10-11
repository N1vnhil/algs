#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include"Stack.h"

template<typename T>
class LinkedStack: public Stack<T> {
    struct node {
        T val;
        node* next;
        node() {next = nullptr;}
        ~node() {}
        node(const T& t, node* n=nullptr) {val = t; next = n;}
    };

    int size_;
    node* head;

public:
    LinkedStack();
    ~LinkedStack();
    T top() const;
    T pop();
    void push(const T& val);
    int size() const;
    void traverse() const;
    bool empty() const;
};

#endif