#define CRTDBG_MAP_ALLOC
#include<iostream>
#include<crtdbg.h>
#include"LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<int> arr;
    cout << arr.length() << endl;
    for(int i=0; i<5; i++) arr.insert(0, i);
    arr.traverse();
    arr.visit(0);
    cout << arr.search(3) << endl;

    arr.remove(3);
    arr.remove(3);
    cout << arr.length() << endl;
    cout << arr.search(1) << endl;
    arr.traverse();

    arr.clear();
    arr.traverse();
    cout << arr.length() << endl;

    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}