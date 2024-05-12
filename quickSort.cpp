#include<iostream>
#include<vector>
using namespace std;

void quickSort(int* arr, int n){    // n = size of arr
    if(n<2) return;
    int l = 0, r = n-1, p = n/2, temp;
    temp = *(arr+r);
    *(arr+r) = *(arr+p);
    *(arr+p) = temp;
    r--;

    while(l<r){
        while(*(arr+l)<*(arr+n-1)){
            l++;
        }
        while(*(arr+r)>*(arr+n-1)){
            r--;
        }

        temp = *(arr+l);
        *(arr+l) = *(arr+r);
        *(arr+r) = temp;
    }

    temp = *(arr+p);
    *(arr+p) = *(arr+r);
    *(arr+r) = temp;

    quickSort(arr, p);
    quickSort(arr+p, n-p-1);
}



int main(){
    int arr[9] = {3,9,2,8,5,4,7,1,6};
    quickSort(arr,9);
    for(int i=0; i<9; i++) cout << i << " ";
}