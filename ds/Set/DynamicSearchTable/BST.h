#ifndef BST_H
#define BST_H

#include "DynamicSearchTable.h"

template<typename KEY, typename VAL>
class BST: public DynamicSearchTable<KEY, VAL> {
    struct node {
        node *left, *right;
        KEY key; VAL val;
        node(): left(nullptr), right(nullptr) {}
        node(KEY k, VAL v, node* l=nullptr, node* r=nullptr): left(l), right(r), key(k), val(v) {};
    };

    node *root;

public:
    BST();
    ~BST();

    Set<KEY, VAL> *find(const KEY& x);
    void insert(const Set<KEY, VAL>& x);
    void remove(const KEY& x);
    void traverse() const;
    
};

#endif