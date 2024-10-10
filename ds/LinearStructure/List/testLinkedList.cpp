#define CRTDBG_MAP_ALLOC
#include<iostream>
#include<crtdbg.h>
#include<string>
#include"LinkedList.cpp"

using namespace std;

int main() {
    LinkedList<char> arr;
    string str = "apple";
    for(char ch: str) arr.insert(arr.length(), ch);
    arr.traverse();

    arr.insert(arr.length(), 'x');
    arr.remove(arr.length()-2);
    cout << arr.visit(arr.length()-1) << endl;
    arr.clear();
    cout << arr.length() << endl;
    arr.traverse();

    _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}