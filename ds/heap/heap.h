#ifndef HEAP_H
#define HEAP_H
#include<vector>
using namespace std;

template<typename T>
class Heap {

    vector<T> arr;
    int _size;

    int parent(int i) {return (i - 1) / 2;}
    int left(int i) {return i * 2 + 1;}
    int right(int i) {return i * 2 + 2;}

public:
    Heap();
    ~Heap();
    void insert(T val);
    void create(vector<T>& items);
    bool empty();
    T getMax();
    void pop();
    int size();
    void traverse();
    void clear();
};

#endif