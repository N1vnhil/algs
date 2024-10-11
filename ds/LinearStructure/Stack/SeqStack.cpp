#include"SeqStack.h"
#include<iostream>

template<typename T>
SeqStack<T>::SeqStack(int initSize) {
    capacity = initSize;
    _size = 0;
    arr = new T[initSize];
}

template<typename T>
SeqStack<T>::~SeqStack() {
    delete[] arr;
}

template<typename T>
int SeqStack<T>::size() const {return _size;}

template<typename T>
T SeqStack<T>::top() const {return arr[_size-1];}

template<typename T>
T SeqStack<T>::pop() {
    T temp = arr[_size-1];
    _size--;
    resize();
    return temp;
}

template<typename T>
void SeqStack<T>::push(const T& val) {
    resize();
    arr[_size++] = val;
}

template<typename T>
bool SeqStack<T>::empty() const {return _size == 0;}

template<typename T>
void SeqStack<T>::resize() {
    double ratio = _size / capacity;
    if(ratio >= 1.0) {
        capacity *= 2;
    } else if (capacity > 8 && ratio < 0.3) {
        capacity /= 2;
    } else return;

    T* new_arr = new T[capacity];
    for(int i=0; i<_size; i++) new_arr[i] = arr[i];
    delete arr;
    arr = new_arr;
}

template<typename T>
void SeqStack<T>::traverse() const {
    for(int i=0; i<_size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}