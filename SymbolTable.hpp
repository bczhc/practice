#ifndef BCZHC_SYMBOL_TABLE_H
#define BCZHC_SYMBOL_TABLE_H

#include "Sort.hpp"
#include <cstdio>
#include "LinearList.hpp"

namespace bczhc {
    template<typename K, typename V>
    class SymbolTable {
    public:
        class Node {
        public:
            K key;
            V value;
            Node *next = nullptr;

            Node(K key, V value) : key(key), value(value) {}

            Node() = default;
        };

        Node *head = nullptr;
        int len = 0;

    public:

        class Result {
        public:
            V val;
            bool found = true;

            explicit Result(V v) : val(v) {}

            Result() = default;
        };

        SymbolTable() { head = new Node; }

        ~SymbolTable() {
            clear();
            delete head;
        }

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

        virtual void put(K key, V value) {
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

        void clear() {
            len = 0;
            Node *t = head->next, *prev;
            while (t != nullptr) {
                prev = t;
                t = t->next;
                delete prev;
            }
        }

        int size() { return len; }

        struct Bean {
            K key;
            V val;

            Bean(K key, V val) : key(key), val(val) {}
        };

        class Iterator : bczhc::Iterator<Bean> {
        private:
            Node *t;
        public:
            explicit Iterator(Node *head) : t(head) {}

            bool hasNext() override {
                return t->next != nullptr;
            }

            Bean next() override {
                t = t->next;
                return Bean(t->key, t->value);
            }
        };

        Iterator getIterator() {
            return Iterator(head);
        }
    };

    template<typename K, typename V>
    class OrderedSymbolTable : public SymbolTable<K, V> {
    private:
        Comparable<K> &comparable;
        using Node = typename SymbolTable<K, V>::Node;

    public:
        explicit OrderedSymbolTable(Comparable<K> &comparable)
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
} // namespace bczhc

#endif // BCZHC_SYMBOL_TABLE_H
