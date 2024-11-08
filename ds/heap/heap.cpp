#include "heap.h"
#include <iostream>
using namespace std;

template<typename T>
Heap<T>::Heap() {
    _size = 0;
}

template<typename T>
Heap<T>::~Heap() {

}

template<typename T>
void Heap<T>::create(vector<T>& items) {
    this->clear();
    for(int i=0; i<items.size(); i++) {
        this->insert(items[i]);
    }
}

template<typename T>
void Heap<T>::insert(T val) {
    if(_size < arr.size()) arr[_size] = val;
    else arr.push_back(val);

    if(_size == 0) {
        _size++;
        return;
    }
    int temp = _size;

    while(temp != parent(temp) && val > arr[parent(temp)]) {
        temp = parent(temp);
    }
    swap(arr[temp], arr[_size]);
    _size++;
}

template<typename T>
T Heap<T>::getMax() {
    return arr[0];
}

template<typename T>
void Heap<T>::pop() {
    if(_size == 0) return;
    swap(arr[0], arr[_size-1]);
    _size--;
    int x = 0;
    while(x * 2 < _size) {
        int t = x * 2;
        if(t + 1 < _size && arr[t] <= arr[t+1]) t++;
        if(arr[t] <= arr[x]) break;
        swap(arr[t], arr[x]);
        x = t;
    }   
}

template<typename T>
int Heap<T>::size() {return _size;}

template<typename T>
bool Heap<T>::empty() {
    return _size == 0;
}

template<typename T>
void Heap<T>::traverse() {
    for(int i=0; i<_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Heap<T>::clear() {
    _size = 0;
}

int main() {
    Heap<int> h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.traverse(); 

    cout << h.getMax() << " " << h.size() << endl;

    h.pop();
    h.pop();

    cout << endl << "After Pop: ";

    cout << h.getMax() << " " << h.size() << endl;
    h.traverse();

    h.insert(4);
    cout << h.getMax() << " " << h.size() << endl;
    h.traverse();

    h.clear();
    vector<int> items = {1, 23, 3};
    h.create(items);
    h.traverse();
}