#include <vector>
#include <iostream>
#include <cassert>
#include "../sort.h"

using namespace std;

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

void sort(vector<int>& arr) {
    for(int i=1; i<arr.size(); i++) {
        int j = i, temp;
        while(j > 0 && arr[j-1]>arr[j]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

}

