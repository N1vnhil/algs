#include"LinkedStack.h"
#include<iostream>

template<typename T>
LinkedStack<T>::LinkedStack() {
    head = nullptr; size_ = 0;
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    node* temp = new node();
    temp->next = head;
    head = temp;

    while(temp->next) {
        head = head->next;
        delete temp;
        temp = head;
    }
    delete temp;
}

template<typename T>
T LinkedStack<T>::top() const {
    return head->val;
}

template<typename T>
T LinkedStack<T>::pop() {
    if(size_ == 0) throw OutOfBound();
    T temp = head->val;
    head = head->next;
    size_--;
    return temp;
}

template<typename T>
int LinkedStack<T>::size() const{return size_;}

template<typename T>
void LinkedStack<T>::push(const T& val) {
    node* temp = new node(val, head); size_++;
    head = temp;
}

template<typename T>
void LinkedStack<T>::traverse() const {
    node* temp = head;
    while(temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
bool LinkedStack<T>::empty() const {
    return size_ == 0;
}