#include<vector>
#include<iostream>
#include"../sort.h"

using namespace std;

int main() {
    vector<int> a = {5, 3, 2, 4, 1};
    show(sort(a));

    vector<int> b = {3, 1, 7, 8, 5, 9, 2, -1, 5};
    show(sort(b));
    return 0;
}

vector<int> sort(vector<int> arr) {
    for(int i=1; i<arr.size(); i++) {
        int j = i, temp;
        while(j > 0 && arr[j-1]>arr[j]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    return arr;
}

