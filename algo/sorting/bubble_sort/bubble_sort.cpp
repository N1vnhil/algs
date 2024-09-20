#include<iostream>
#include<vector>
#include"../sort.h"

using namespace std;

int main() {
    vector<int> a = {5, 3, 2, 4, 1};
    show(sort(a));
    return 0;
}

vector<int> sort(vector<int> arr) {
    int n = arr.size();
    int temp;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return arr;
}