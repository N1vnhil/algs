#include<iostream>
#include"SeqList.cpp"
#include<string>
using namespace std;


int main() {
    SeqList<char> arr;
    string str = "apples in";
    for(int i=0; i<str.size(); i++) {arr.insert(i, str[i]);}
    arr.traverse();

    arr.remove(2);
    arr.traverse();

    cout << endl;
    cout << arr.length() << '\n';
    cout << arr.search('a') << ' ' << arr.search('e');

    for(int i=10; i>=0; i--) arr.insert(0, i+'a');
    arr.insert(0, 'x');
    arr.traverse();

    for(int i=0; i<5; i++) arr.remove(10);
    arr.traverse();

    cout << "line 27" << endl;

    arr.clear();
    cout << arr.length() << endl;
    arr.insert(0, 'a');
    for(char ch: str) {
        arr.insert(arr.length(), ch);
        cout << arr.length() << ' ';
    }
    arr.traverse();

}

// length passed
// insert passed
// remove passed
// search passed
// visit passed
// traverse passed
// clear passed

