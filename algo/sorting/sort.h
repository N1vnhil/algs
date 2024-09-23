#ifndef SORT_H
#define SORT_H

#include<vector>
using namespace std;

void sort(vector<int>&);

void show(vector<int> arr) {
    for(int i: arr) std::cout << i << " ";
    cout << endl;
}

#endif