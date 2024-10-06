#include<iostream>
#include<vector>
#include<cassert>
#include"../sort.h"

using namespace std;

void sort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[i]) swap(arr[i], arr[j]);
        }
    }
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