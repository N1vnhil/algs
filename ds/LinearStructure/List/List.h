#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
public:
    virtual int length() = 0;
    virtual void clear() = 0;

    virtual void insert(int i, const T& val) = 0;
    virtual T remove(int i) = 0;
    virtual int search(const T& val) const = 0;
    virtual T visit(int i) const = 0;

    virtual void traverse() const = 0;
    virtual ~List(){};
};

class OutOfBound{};

#endif 