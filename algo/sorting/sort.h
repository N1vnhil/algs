#ifndef SORT_H
#define SORT_H

#include<vector>
using namespace std;

template<typename K, typename V>
struct SET {
    K key; V val;
    SET() {}
    SET(K k, V v): key(k), val(v) {}
};

template<typename K, typename V>
void show(vector<SET<K, V>>& arr) {
    for(auto item: arr) std::cout << "(" << item.key << "," << item.val << ") ";
    cout << endl;
}

void show(vector<int> arr) {
    for(int i: arr) std::cout << i << " ";
    cout << endl;
}

#endif