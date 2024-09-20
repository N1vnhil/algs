#include<iostream>
void swap(int&, int&);

void quickSort(int* arr, int n){
	if(n<2) return;
	int l=0, r=n-1, pivot = arr[l];
	while(l<r){
		while(l<r && arr[r]>pivot) r--;
		if(l<r) swap(arr[l++],arr[r]);
		while(l<r && arr[l]<pivot) l++;
		if(l<r) swap(arr[l],arr[r--]);
	}

	quickSort(arr, l);
	quickSort(arr+l+1, n-l-1);
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

using namespace std;

int main(){
	cout << "input array size" << endl;
	int n; cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++) cin >> *(arr+i);
	quickSort(arr, n);
	cout << endl << "sorted array: ";
	for(int i=0; i<n; i++) cout << *(arr+i) << " ";
	delete arr;

	int i;
	cout << endl << "type 0 to exit" << endl;
	while(i){
		cin >> i;
	}
}