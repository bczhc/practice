#ifndef BCZHC_SYMBOL_TABLE_H
#define BCZHC_SYMBOL_TABLE_H

#include "Result.hpp"
#include "Sort.hpp"
#include <cstdio>
#include <sys/types.h>

namespace bczhc {
namespace symboltable {
template <typename K, typename V> class SymbolTable {
public:
    class Node {
    public:
        K key;
        V value;
        Node *next = nullptr;
        Node(K key, V value) : key(key), value(value) {}
        Node() {}
    };
    Node *head = nullptr;
    int len = 0;

public:
    using Result = Result<V>;
    SymbolTable() { head = new Node; }

    ~SymbolTable() { delete head; }
    Result get(K key) {
        Node *t = head;
        Result r;
        r.found = false;
        for (int i = 0; i < len; ++i) {
            t = t->next;
            if (t->key == key) {
                r.val = t->value;
                r.found = true;
            }
        }
        return r;
    }

    void put(K key, V value) {
        Node *t = head;
        for (int i = 0; i < len; ++i) {
            t = t->next;
            if (t->key == key) {
                t->value = value;
                return;
            }
        }
        Node *newNode = new Node(key, value);
        Node *first = head->next;
        newNode->next = first;
        head->next = newNode;
        ++len;
    }

    void remove(K key) {
        Node *t = head;
        for (int i = 1; i < len; ++i) {
            if (t->next->key == key) {
                Node *removedNode = t->next;
                t->next = removedNode->next;
                delete removedNode;
            }
        }
        --len;
    }

    int size() { return len; }
};

template <typename K, typename V>
class OrderedSymbolTable : public SymbolTable<K, V> {
private:
    sort::Comparable<K> &comparable;
    using Node = typename SymbolTable<K, V>::Node;

public:
    OrderedSymbolTable(sort::Comparable<K> &comparable)
        : comparable(comparable) {}
    void put(K key, V value) {
        Node *curr = this->head->next, *prev = this->head;
        while (curr != nullptr && comparable.compare(key, curr->key) < 0) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr && curr->key == key) {
            curr->value = value;
        }
        Node *newNode = new Node(key, value);
        newNode->next = curr;
        prev->next = newNode;
        ++this->len;
    }
};
} // namespace symboltable
} // namespace bczhc

#endif // BCZHC_SYMBOL_TABLE_H
