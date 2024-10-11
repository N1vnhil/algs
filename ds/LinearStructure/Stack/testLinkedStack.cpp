#include<iostream>
#include"LinkedStack.cpp"

using namespace std;

int main() {
    LinkedStack<int> stack;
    for(int i=0; i<3; i++) stack.push(i);
    stack.traverse();

    stack.pop();
    stack.traverse();

    cout << stack.top() << " " << stack.size() << endl;

    LinkedStack<char> ch_stack;
    ch_stack.push('a');
    cout << ch_stack.empty() << endl;
    ch_stack.pop();
    cout << ch_stack.empty() << endl;
    return 0;
}