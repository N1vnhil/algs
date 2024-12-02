#include <vector>
#include <iostream>
#include "../sort.h"
using namespace std;

template<typename K, typename V>
void simpleSort(vector<SET<K, V>>&);

template<typename K, typename V>
void shellSort(vector<SET<K, V>>&);

int main() {
    vector<SET<int, int>> a = {SET<int, int>(5, 5), SET<int, int>(3, 3), SET<int, int>(2, 2), SET<int, int>(4, 4), SET<int, int>(1, 1)};
    vector<SET<int, int>> b = {SET<int, int>(3, 3), SET<int, int>(7, 7), SET<int, int>(-1, -1)};

    simpleSort(a);
    simpleSort(b);
    show(a); show(b);

    shellSort(a);
    shellSort(b);
    show(a); show(b);
    
    return 0;
}

template<typename K, typename V>
void simpleSort(vector<SET<K, V>>& arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        int j = i;
        SET<K, V> tmp = arr[i];
        while(j > 0 && arr[j-1].key > tmp.key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = tmp;
    }
}

template<typename K, typename V>
void shellSort(vector<SET<K, V>>& arr) {
    int n = arr.size();
    for(int i = n / 2; i > 0; i /= 2) {
        for(int j = i; j < n; j++) {
            auto tmp = arr[j];
            for(int k = j; k > 0 && arr[k].key < arr[k-i].key; k -= i) {
                arr[k] = arr[k - i];
            }
            arr[j] = tmp;
        }
    }
}


