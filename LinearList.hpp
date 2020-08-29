#include "Sort.hpp"

namespace bczhc {
template <typename T> class Iterator {
public:
    virtual bool next() = 0;
    virtual T &value() = 0;
};
namespace linearlist {
template <typename T> class SequentialList {
private:
    T *elements = nullptr;
    int len = 0;

public:
    SequentialList(int capacity) {
        elements = new T[capacity];
        elementsLength = capacity;
    }
    SequentialList() {
        elements = elements = new T[1];
        elementsLength = 1;
    }

    ~SequentialList() { delete elements; }

    void clear() { len = 0; }

    bool isEmpty() { return len == 0; }

    int length() { return len; }

    T get(int i) { return elements[i]; }

    void insert(int index, T a) {
        if (len == elementsLength)
            resize(elementsLength * 2 + 2);
        for (int i = len; i > index; --i)
            elements[i] = elements[i - 1];
        elements[index] = a;
        ++len;
    }

    void insert(T a) {
        if (len == elementsLength)
            resize(elementsLength * 2 + 2);
        elements[len++] = a;
    }

    T remove(int index) {
        if (len < elementsLength / 4)
            resize(elementsLength / 2);
        T removed = elements[index];
        --len;
        for (int i = index; i < len; ++i)
            elements[i] = elements[i + 1];
        return removed;
    }

    int indexOf(T t) {
        for (int i = 0; i < len; ++i) {
            if (elements[i] == t)
                return i;
        }
    }

private:
    int elementsLength = 0;
    void resize(int newSize) {
        T *newArr = new T[newSize];
        for (int i = 0; i < len; ++i)
            newArr[i] = elements[i];
        delete elements;
        elements = newArr;
        elementsLength = newSize;
    }
};

template <typename T> class LinkedList {
private:
    class Node {
    public:
        T data;
        Node *next = nullptr;

        Node(T data, Node *next) : data(data), next(next) {}
        Node() {}
    };

    Node *head;
    int len = 0;

public:
    LinkedList() { head = new Node(); }
    void clear() {
        len = 0;
        Node *t = head;
        while (t != nullptr) {
            Node *next = t->next;
            delete t;
            t = next;
        }
    }

    bool isEmpty() { return len == 0; }

    int length() { return len; }

    T get(int index) {
        Node *t = head;
        for (int i = 0; i <= index; ++i) {
            t = t->next;
        }
        return t->data;
    }

    void insert(T a) {
        Node *t = head;
        while (t->next != nullptr)
            t = t->next;
        Node *newNode = new Node(a, nullptr);
        t->next = newNode;
        ++len;
    }

    void insert(int index, T a) {
        Node *t = head;
        for (int i = 0; i < index; ++i) {
            t = t->next;
        }
        Node *newNode = new Node(a, t->next);
        t->next = newNode;
        ++len;
    }

    T remove(int index) {
        Node *t = head;
        for (int i = 0; i < index; ++i) {
            t = t->next;
        }
        Node *removedNode = t->next;
        t->next = removedNode->next;
        T r = removedNode->data;
        delete removedNode;
        --len;
        return r;
    }

    int indexOf(T e) {
        Node *t = head;
        for (int i = 0; i < len; ++i) {
            t = t->next;
            if (t->data == e)
                return i;
        }
        return -1;
    }

    class Iterator : public bczhc::Iterator<T> {
    private:
        Node *t;

    public:
        Iterator(Node *head) : t(head->next) {}
        bool next() override {
            t = t->next;
            return t != nullptr;
        }

        T &value() override { return t->data; }
    };

    Iterator getIterator() {
        Iterator it(head);
        return it;
    }
};

class DoublyLinkedList {};
} // namespace linearlist
} // namespace bczhc
