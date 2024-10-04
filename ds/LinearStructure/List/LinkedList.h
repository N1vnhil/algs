#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "List.h"

template<typename T>
class LinkedList: public List<T> {
    struct node {
        T val;
        node* next;
        node(const T& x, node* n=nullptr){
            val = x; next = n;
        }
        node(){next=nullptr;}
        ~node(){};
    };

    int size;
    node* head;
    
public:
    LinkedList();
    ~LinkedList();

    int length();
    void clear();

    void insert(int i, const T& val);
    T remove(int i);
    int search(const T& val) const;
    T visit(int i) const;

    void traverse() const;    
};

#endif