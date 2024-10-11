#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
public:
    virtual T top() const = 0;
    virtual T pop() = 0;
    virtual void push(const T& val) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual void traverse() const = 0;
};

class OutOfBound{};
class InvalidIndex{};

#endif