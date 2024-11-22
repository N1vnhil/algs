#include "BST.h"
#include <stack>
#include <iostream>
using namespace std;

template<typename K, typename V>
BST<K, V>::BST(): root(nullptr) {
    
}

template<typename K, typename V>
BST<K, V>::~BST() {
    stack<node*> s;
    if(root) s.push(root);
    while(!s.empty()) {
        node* tmp = s.top(); s.pop();
        if(tmp->left) s.push(tmp->left);
        if(tmp->right) s.push(tmp->right);
        delete tmp;
    }
}

template<typename K, typename V>
Set<K, V>* BST<K, V>::find(const K& x) {
    Set<K, V>* ans = nullptr;
    node* tmp = root;
    while(tmp) {
        if(tmp->key == x) {
            ans = new Set<K, V>(tmp->key, tmp->val);
            return ans;
        }
        else if(tmp->key < x) tmp = tmp->right;
        else tmp = tmp->left;
    }
    return ans;
}

template<typename K, typename V>
void BST<K, V>::insert(const Set<K, V>& x) {
    node* tmp = root;

    if(!root) {
        root = new node(x.key, x.val);
        return;
    }

    while(tmp) {
        if(tmp->key == x.key) return;
        if(tmp->key < x.key) {
            if(!tmp->right) {
                tmp->right = new node(x.key, x.val);
                return;
            } else {
                tmp = tmp->right;
            }
        }

        else {
            if(!tmp->left) {
                tmp->left = new node(x.key, x.val);
                return;
            } else {
                tmp = tmp->left;
            }
        }
    }
}

template<typename K, typename V>
void BST<K, V>::remove(const K& x) {
    node* tmp = root, *parent = nullptr;
    while(tmp != nullptr && tmp->key != x) {
        parent = tmp;
        if(tmp->key < x) tmp = tmp->right;
        else tmp = tmp->left;
    }

    node* tgt;
    if(tmp) {
        if(tmp->left && tmp->right) {
            node *tgtParent = tmp; 
            tgt = tmp->right;

            while(tgt->left) {
                tgtParent = tgt;
                tgt = tgt->left;
            }
            tmp->val = tgt->val;
            tgtParent->left = tgt->right;
            delete tgt;
            return;
        }

        else {
            if(tmp->left) tgt = tmp->left;
            else tgt = tmp->right;

            if(!parent) {
                delete root;
                root = tgt;
                return;
            }

            else if(parent->left && parent->left == tmp) {
                parent->left = tgt;
            } else parent->right = tgt;

            delete tmp;
        }
    }
}

template<typename K, typename V>
void BST<K, V>::traverse() const {
    stack<node*> s;
    if(root) s.push(root);
    while(!s.empty()) {
        node* tmp = s.top(); s.pop();
        if(tmp->right) s.push(tmp->right);
        if(tmp->left) s.push(tmp->left);
        cout << tmp->val << " ";
    }
    cout << endl;
}

int main() {
    BST<int, char> bst;
    Set<int, char> s1 = Set<int, char>(1, 'a');
    Set<int, char> s2 = Set<int, char>(5, 'b');
    Set<int, char> s3 = Set<int, char>(-1, 'c');
    Set<int, char> s4 = Set<int, char>(8, 'd');
    Set<int, char> s5 = Set<int, char>(6, 'e');
    Set<int, char> s6 = Set<int, char>(4, 'f');
    Set<int, char> s7 = Set<int, char>(-10, 'g');

    bst.insert(s1); bst.insert(s2); bst.insert(s3); bst.insert(s4); bst.insert(s5); bst.insert(s6); bst.insert(s7);

    bst.remove(-10); 
    bst.remove(-1);
    bst.remove(1);
    bst.traverse();
}