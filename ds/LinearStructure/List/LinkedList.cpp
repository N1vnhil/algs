#include"LinkedList.h"

template<typename T>
LinkedList::LinkedList() {
    size = 0;
    head->next = nullptr;
}

template<typename T>
LinkedList::~LinkedList() {

}

template<typename T>
int LinkedList::length() {
    return size;
}
