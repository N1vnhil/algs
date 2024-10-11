#ifndef SEQSTACK_H
#define SEQSTACK_H
#include"Stack.h"

template<typename T>
class SeqStack: public Stack<T> {
    int capacity, _size;
    T* arr;
    void resize();
public:
    SeqStack(int initSize=8);
    ~SeqStack();
    int size() const;
    T top() const;
    T pop();
    void push(const T& val);
    bool empty() const;
    void traverse() const;
};

#endif