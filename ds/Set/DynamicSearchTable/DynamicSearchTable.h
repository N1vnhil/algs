#ifndef DYNAMIC_SEARCH_TABLE_H
#define DYNAMIC_SEARCH_TABLE_H

template<typename KEY, typename VAL>
struct Set {
    KEY key;
    VAL val;
    Set(KEY k, VAL v): key(k), val(v) {}
};

template<typename KEY, typename VAL>
class DynamicSearchTable {
public:
    virtual Set<KEY, VAL>* find(const KEY& x) = 0;
    virtual void insert(const Set<KEY, VAL>& x) = 0;
    virtual void remove(const KEY& x) = 0;
    virtual ~DynamicSearchTable() {}
};

#endif