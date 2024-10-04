#include"SeqList.h"
#include<iostream>

template<typename T>
SeqList<T>::SeqList(int initSize) {
    capacity = initSize;
    size = 0;
    arr = new T[capacity];
}

template<typename T>
SeqList<T>::~SeqList() {
    delete[] arr;
}

template<typename T>
void SeqList<T>::resize() {

    int last = capacity;

    if(capacity < 8) capacity = 8;
    else {
        double r = (double)size / (double)capacity;
        if(r==1.) capacity *= 2;
        else if(r < 0.2) capacity /= 2;
    }
        
    if(last != capacity) {
        T* temp = new T[capacity];

        for(int i=0; i<size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

}

template<typename T>
int SeqList<T>::length() {return size;}

template<typename T>
void SeqList<T>::insert(int i, const T& val) {
    this->resize();
    for(int j=size; j>i; j--) {
        arr[j] = arr[j-1];
    }
    size++;
    arr[i] = val;
}

template<typename T>
T SeqList<T>::remove(int i) {
    if(i>=size) throw "Out of Bound.";
    this->resize();
    T temp = arr[i];
    for(int j=i+1; j<size; j++) {
        arr[j-1] = arr[j];
    }
    size--;
    return temp;
}

template<typename T>
T SeqList<T>::visit(int i) const {
    return arr[i];
}

template<typename T>
int SeqList<T>::search(const T& val) const {
    for(int i=0; i<size; i++) {
        if(arr[i]==val) return i;
    }
    return -1;
}

template<typename T>
void SeqList<T>::traverse() const {
    std::cout << std::endl;
    for(int i=0; i<size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
void SeqList<T>::clear() {
    size = 0;
}