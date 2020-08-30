#include "Sort.hpp"

namespace bczhc {
template <typename T> class Iterator {
public:
    virtual bool moveToFirst() = 0;
    virtual bool next() = 0;
    virtual T &get() = 0;
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
public:
    class Node {
    public:
        T data;
        Node *next = nullptr;

        Node(T data, Node *next) : data(data), next(next) {}
        Node() {}
    };

private:
    Node *head;
    int len = 0;

public:
    LinkedList() { head = new Node(); }
    ~LinkedList() { delete head; }
    void clear() {
        len = 0;
        Node *t = head;
        while (t->next != nullptr) {
            t = t->next;
            delete t;
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
        Iterator(Node *head) : t(head) {}

        bool moveToFirst() override {
            if (t->next == nullptr)
                return false;
            else {
                t = t->next;
                return true;
            }
        }

        bool next() override {
            t = t->next;
            return t != nullptr;
        }

        T &get() override { return t->data; }
    };

    Iterator getIterator() {
        Iterator it(head);
        return it;
    }

private:
    Node *reverse(Node *node) {
        if (node->next == nullptr) {
            head->next = node;
            return node;
        }
        Node *prev = reverse(node->next);
        prev->next = node;
        return node;
    }

public:
    void reverse() {
        if (isEmpty())
            return;
        reverse(head->next)->next = nullptr;
    }

    T getMid() {
        Node *slow = head->next, *fast = slow;
        while (fast != nullptr && fast->next != nullptr)
            slow = slow->next, fast = fast->next->next;
        return slow->data;
    }
};

template <typename T> class DoublyLinkedList {
private:
    class Node {
    public:
        T data;
        Node *prev = nullptr;
        Node *next = nullptr;
        Node() {}
    };

    Node *head, *last;
    int len = 0;

public:
    DoublyLinkedList() {
        head = new Node();
        last = head;
    }
    ~DoublyLinkedList() { delete head; }

    void clear() {
        len = 0;
        Node *t = head;
        while (t->next != nullptr) {
            t = t->next;
            delete t;
        }
        head->next = nullptr;
        last = head;
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
        Node *newNode = new Node();
        newNode->prev = last, newNode->data = a;
        last->next = newNode;
        last = last->next;
        ++len;
    }

    void insert(int index, T a) {
        Node *prev = head;
        for (int i = 0; i < index; ++i)
            prev = prev->next;
        Node *curr = prev->next;
        Node *newNode = new Node;
        newNode->prev = prev, newNode->data = a, newNode->next = curr;
        curr->prev = newNode;
        prev->next = newNode;
        ++len;
    }

    T remove(int index) {
        Node *prev = head;
        for (int i = 0; i < index; ++i)
            prev = prev->next;
        Node *removedNode = prev->next;
        T r = removedNode->data;
        prev->next = removedNode->next;
        removedNode->next->prev = prev;
        delete removedNode;
        --len;
        return r;
    }

    int indexOf(T e) {
        Node *t = head;
        for (int i = 0; i < len; ++i) {
            t = t->next;
            if (e == t->data)
                return i;
        }
    }

    T getFirst() { return head->next->data; }

    T getLast() { return last->data; }

    class Iterator : public bczhc::Iterator<T> {
    private:
        Node *t;

    public:
        Iterator(Node *head) : t(head) {}

        bool moveToFirst() override {
            if (t->next == nullptr)
                return false;
            else {
                t = t->next;
                return true;
            }
        }

        bool next() override {
            t = t->next;
            return t != nullptr;
        }

        T &get() override { return t->data; }
    };

    Iterator getIterator() {
        Iterator it(head);
        return it;
    }
};

template <typename T> class Stack {
private:
    using Node = typename LinkedList<T>::Node;
    Node *head = nullptr;
    int len = 0;

public:
    Stack() { head = new Node(); }

    ~Stack() { delete head; }

    void clear() {
        len = 0;
        Node *t = head;
        while (t->next != nullptr) {
            t = t->next;
            delete t;
        }
        head->next = nullptr;
    }
    bool isEmpty() { return len == 0; }

    int size() { return len; }

    T pop() {
        Node *first = head->next;
        T r = first->data;
        head->next = first->next;
        delete first;
        --len;
        return r;
    }

    void push(T a) {
        Node *newNode = new Node(a, head->next);
        head->next = newNode;
        ++len;
    }

    class Iterator : public bczhc::Iterator<T> {
    private:
        Node *t;

    public:
        Iterator(Node *head) : t(head) {}

        bool moveToFirst() override {
            if (t->next == nullptr)
                return false;
            else {
                t = t->next;
                return true;
            }
        }

        bool next() override {
            t = t->next;
            return t != nullptr;
        }

        T &get() override { return t->data; }
    };

    Iterator getIterator() {
        Iterator it(head);
        return it;
    }
};

template <typename T> class Queue {
private:
    using Node = typename LinkedList<T>::Node;
    Node *head = nullptr, *last = nullptr;
    int len = 0;

public:
    Queue() {
        head = new Node;
        last = head;
    }

    ~Queue() { delete head; }
    bool isEmpty() { return len == 0; }

    int size() { return len; }

    T dequeue() {
        Node *first = head->next;
        head->next = first->next;
        T r = first->data;
        delete first;
        --len;
        return r;
    }

    void enqueue(T a) {
        last->next = new Node(a, nullptr);
        last = last->next;
        ++len;
    }

    class Iterator : public bczhc::Iterator<T> {
    private:
        Node *t = nullptr;

    public:
        Iterator(Node *head) : t(head) {}

        bool moveToFirst() override {
            if (t->next == nullptr)
                return false;
            else {
                t = t->next;
                return true;
            }
        }

        bool next() override {
            t = t->next;
            return t != nullptr;
        }

        T &get() override { return t->data; }
    };

    Iterator getIterator() {
        Iterator it(head);
        return it;
    }
};

} // namespace linearlist
} // namespace bczhc
