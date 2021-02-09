#ifndef BCZHC_TREE_H
#define BCZHC_TREE_H

#include "Result.hpp"
#include "Sort.hpp"

namespace bczhc {
    template<typename K, typename V>
    class BinarySearchTree {
    private:
        Comparable<K> *comparable = nullptr;

        class Node {
        public:
            Node *left = nullptr, *right = nullptr;
            K key;
            V value;

            Node(K key, V value) : key(key), value(value) {}
        };

        Node *root = nullptr;
        int len = 0;

    public:
        class Result {
        public:
            V val;
            bool found = true;

            explicit Result(V v) : val(v) {}

            Result() = default;
        };

        explicit BinarySearchTree(Comparable<K> &comparable)
                : comparable(&comparable) {}

        int size() { return len; }

        void put(K key, V value) { put(root, key, value); }

        void get(Result &result, K key) {
            get(result, root, key);
        }

    private:
        Node *put(Node *x, K key, V value) {
            if (x == nullptr) {
                ++len;
                return new Node(key, value);
            }
            int cmp = comparable->compare(key, x);
            if (cmp < 0) {
                x->left = put(x->left, key, value);
            } else if (cmp > 0) {
                x->right = put(x->right, key, value);
            } else {
                x->value = value;
            }
            return x;
        }

        void get(Result &result, Node *x, K key) {

        }
    };
} // namespace bczhc

#endif // BCZHC_TREE_H
