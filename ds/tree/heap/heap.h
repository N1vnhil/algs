#ifndef HEAP_H
#define HEAP_H

#include<iostream>

template<typename T>

class Heap {
private:
    T* arr;
    int n;
    int capacity;
    void resize();
    void max_heapify(int);

public:
    Heap();
    ~Heap();
    int size();
    void add(T n);
    T get_top();
    T pop_top();
    bool empty();
    void show();    
};

template<typename T>
Heap<T>::Heap() {
    capacity = 8;
    arr = new T[capacity];
    n = 0;
}

template<typename T>
Heap<T>::~Heap() {
    delete[] arr;
}

template<typename T>
int Heap<T>::size() {
    return n;
}

template<typename T>
bool Heap<T>::empty() {
    return n == 0;
}

template<typename T>
void Heap<T>::add(T item) {
    resize();
    arr[size++] = arr[0];
    arr[0] = item;
    max_heapify();
}


template<typename T>
T Heap<T>::get_top() {
    if(this->empty()) throw "Null Heap.";
    return arr[0];
}

template<typename T>
T Heap<T>::pop_top() {
    if(this->empty()) throw "Null Heap.";
    return arr[0];
}

template<typename T>
void Heap<T>::resize() {
    if(size==capacity) {
        capacity *= 2;
        int arr2 = new arr[capacity];
        for(int i=0; i<size; i++) arr2[i] = arr[i];
        delete[] arr;
        arr = arr2;
    }
}

template<typename T>
void Heap<T>::max_heapify(int i) {
    int left = i * 2 + 1, right = i * 2 + 2;
    int largest;
    if(left < n && arr[left] > arr[i]) largest = left;
    else largest = i;

    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        max_heapify(largest);
    }
}

template<typename T>
void show() {
    for(int i=0; i<n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << endl;
}

#endif