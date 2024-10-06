#include<iostream>
#include<vector>
#include<cassert>
#include"../sort.h"

using namespace std;

vector<int> merge_sort(vector<int>&, int, int);
vector<int> merge(vector<int>&, vector<int>&);


vector<int> merge_sort(vector<int>& arr, int l, int r) {
    if(l >= r) return vector<int>{arr[l]};

    vector<int> arr1 = merge_sort(arr, l, (l + r) / 2);
    vector<int> arr2 = merge_sort(arr, (l + r) / 2 + 1, r);
    return merge(arr1, arr2);
}

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {

    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2, l1 = 0, l2 = 0, l = 0;
    vector<int> arr(n);

    while(l1 < n1 || l2 < n2) {

        if(l1 >= n1){
            arr[l++] = arr2[l2++];
            continue;
        }

        if(l2 >= n2) {
            arr[l++] = arr1[l1++];
            continue;
        }

        if(arr1[l1] < arr2[l2]) arr[l++] = arr1[l1++];
        else arr[l++] = arr2[l2++];

    }

    return arr;
}

void sort(vector<int>& arr) {
    arr = merge_sort(arr, 0, arr.size()-1);
}

int main() {
    vector<int> a = {5, 3, 2, 4, 1};
    sort(a);
    assert(a == vector<int>({1, 2, 3, 4, 5}));
    show(a);

    vector<int> b = {3, 1, 7, 8, 5, 9, 2, -1, 5};
    sort(b);
    assert(b == vector<int>({-1, 1, 2, 3, 5, 5, 7, 8, 9}));
    show(b);
    return 0;
}