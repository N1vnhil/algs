#include"LinkedList.h"
#include<iostream>
using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = new node;
    head->next = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    node* temp = head->next;
    while(temp) {
        head->next = temp->next;
        delete temp;
        temp = head->next;
    }
    delete head;
}

template<typename T>
int LinkedList<T>::length() {
    return size;
}

template<typename T>
void LinkedList<T>::clear() {
    node* temp = head->next;
    while(temp) {
        head->next = temp->next;
        delete temp;
        temp = head->next;
    }
    size = 0;
}

template<typename T>
void LinkedList<T>::insert(int i, const T& val) {
    if(i>size) throw OutOfBound();
    node* temp = head;
    while(i>0) {temp = temp->next; i--;};
    
    node* p = temp->next;
    temp->next = new node(val);
    temp->next->next = p;

    size++;
}

template<typename T>
int LinkedList<T>::search(const T& val) const {
    node* temp = head->next;
    int i = 0;
    while(temp) {
        if(temp->val == val) return i;
        i++;
        temp = temp->next;
    }
    return -1;
} 

template<typename T>
T LinkedList<T>::remove(int i){
    if(i>=size) throw OutOfBound();

    T val;
    node* temp = head;
    while(i>0) {
        temp = temp->next;
        i--;
    }

    node* p = temp->next;
    temp->next = temp->next->next;
    delete p;

    size--;
    return val;
}

template<typename T>
T LinkedList<T>::visit(int i) const {
    if(i>=size) throw OutOfBound();
    node* temp = head->next;
    while(i>0) {
        i--;
        temp = temp->next;
    }
    return temp->val;
} 

template<typename T>
void LinkedList<T>::traverse() const {
    node* temp = head->next;
    while(temp) {
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << endl;
}
