#ifndef SEQLIST_H
#define SEQLIST_H

#include"List.h"

template<typename T>
class SeqList: public List<T>{
    int size; 
    int capacity;
    T* arr;
    void resize();

public:
    SeqList(int initSize=8);
    ~SeqList();

    int length();
    void clear();
    
    void insert(int i, const T& val);
    T remove(int i);
    int search(const T& val) const;
    T visit(int i) const;
    void traverse() const;
};

#endif