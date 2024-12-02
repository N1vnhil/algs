#include <iostream>
#include <vector>
#include "../sort.h"
using namespace std;

template<typename K, typename V>
void bubbleSort(vector<SET<K, V>>&);
template<typename K, typename V>
int partition(vector<SET<K, V>>&, int, int);
template<typename K, typename V>
void quickSort(vector<SET<K, V>>&, int, int);
template<typename K, typename V>
void quickSort(vector<SET<K, V>>&);

int main() {
    vector<SET<int, int>> a = {SET<int, int>(5, 5), SET<int, int>(3, 3), SET<int, int>(2, 2), SET<int, int>(4, 4), SET<int, int>(1, 1)};
    vector<SET<int, int>> b = {SET<int, int>(3, 3), SET<int, int>(7, 7), SET<int, int>(-1, -1)};

    bubbleSort(a);
    bubbleSort(b);
    show(a); show(b);


    a = {SET<int, int>(5, 5), SET<int, int>(3, 3), SET<int, int>(2, 2), SET<int, int>(4, 4), SET<int, int>(1, 1)};
    b = {SET<int, int>(3, 3), SET<int, int>(7, 7), SET<int, int>(-1, -1)};
    quickSort(a);
    quickSort(b);
    show(a); show(b);
    
    return 0;
}

template<typename K, typename V>
void bubbleSort(vector<SET<K, V>>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j].key > arr[j+1].key) swap(arr[j], arr[j+1]);
        }
    }
}

template<typename K, typename V>
void quickSort(vector<SET<K, V>>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

template<typename K, typename V>
void quickSort(vector<SET<K, V>>& arr, int l, int r) {
    if(l >= r) return;
    int pos = partition(arr, l, r);
    quickSort(arr, l, pos - 1);
    quickSort(arr, pos + 1, r);   
}

template<typename K, typename V>
int partition(std::vector<SET<K, V>>& arr, int l, int r) {
    SET<K, V> pivot = arr[l];
    while(l < r) {
        while(l < r && arr[r].key >= pivot.key) r--; arr[l] = arr[r];
        while(l < r && arr[l].key <= pivot.key) l++; arr[r] = arr[l];
    }
    arr[l] = pivot;
    return l;
}