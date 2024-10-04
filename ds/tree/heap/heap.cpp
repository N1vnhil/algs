#include<iostream>
#include"heap.h"

using namespace std;

int main() {
    Heap<int> h;
    cout << h.size();
    h.show();
    
    return 0;
}
