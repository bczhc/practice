#ifndef BCZHC_LINEAR_LIST_HPP
#define BCZHC_LINEAR_LIST_HPP

namespace bczhc {
    template<typename T>
    class Iterator {
    public:
        virtual bool hasNext() = 0;

        virtual T next() = 0;
    };

    template<typename T>
    class SequentialList {
    private:
        int len = 0;

    public:
        T *data = nullptr;

        explicit SequentialList(int capacity) {
            data = new T[capacity];
            dataSize = capacity;
        }

        SequentialList() {
            data = new T[1];
            dataSize = 1;
        }

        ~SequentialList() { delete[] data; }

        void clear() { len = 0; }

        bool isEmpty() { return len == 0; }

        int length() { return len; }

        T get(int i) { return data[i]; }

        void insert(int index, T a) {
            if (len == dataSize)
                resize(dataSize * 2 + 2);
            for (int i = len; i > index; --i)
                data[i] = data[i - 1];
            data[index] = a;
            ++len;
        }

        void insert(int index, const T *a, int size) {
            if (index < 0 || index > len) return;
            int t;
            if (len + size >= dataSize)
                resize(dataSize * 2 + len + size);
            for (int i = len - 1 + size; i > index; --i) {
                t = i - size;
                if (t >= 0) data[i] = data[t];
            }
            for (int i = index; i < index + size; ++i) {
                data[i] = a[i - index];
            }
            len += size;
        }

        SequentialList<T> &insert(T a) {
            if (len == dataSize)
                resize(dataSize * 2 + 2);
            data[len++] = a;
            return *this;
        }

        T remove(int index) {
            if (len < dataSize / 4)
                resize(dataSize / 2);
            T removed = data[index];
            --len;
            for (int i = index; i < len; ++i)
                data[i] = data[i + 1];
            return removed;
        }

        /**
         * Remove range: [start, end)
         * @param start
         * @param end
         */
        void remove(int start, int end) {
            if (start < 0 || start >= len || end > len || end < start) return;
            int removedSize = end - start;
            int t = len - removedSize;
            for (int i = start; i < t; ++i) {
                data[i] = data[i + removedSize];
            }
            if (len < dataSize / 4) resize(dataSize / 2);
            len -= removedSize;
        }

        int indexOf(T t) {
            for (int i = 0; i < len; ++i) {
                if (data[i] == t)
                    return i;
            }
        }

        T &operator[](int i) {
            return data[i];
        }

    private:
        int dataSize = 0;

        void resize(int newSize) {
            T *newArr = new T[newSize];
            for (int i = 0; i < len; ++i)
                newArr[i] = data[i];
            delete[] data;
            data = newArr;
            dataSize = newSize;
        }
    };

    template<typename T>
    class LinkedList {
    public:
        class Node {
        public:
            T data;
            Node *next = nullptr;

            Node(T data, Node *next) : data(data), next(next) {}

            Node() = default;
        };

    private:
        Node *head;
        int len = 0;

    public:
        LinkedList() { head = new Node(); }

        ~LinkedList() {
            clear();
            delete head;
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
            explicit Iterator(Node *head) : t(head) {}

            bool hasNext() override {
                return t->next != nullptr;
            }

            T next() override {
                t = t->next;
                return t->data;
            }
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

    template<typename T>
    class DoublyLinkedList {
    private:
        class Node {
        public:
            T data;
            Node *prev = nullptr;
            Node *next = nullptr;

            Node() = default;
        };

        Node *head, *last;
        int len = 0;

    public:
        DoublyLinkedList() {
            head = new Node();
            last = head;
        }

        ~DoublyLinkedList() {
            clear();
            delete head;
        }

        void clear() {
            len = 0;
            Node *t = head->next, *prev;
            while (t != nullptr) {
                prev = t;
                t = t->next;
                delete prev;
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
            Node *curr = prev->next;
            T r = curr->data;
            Node *next = curr->next;
            if (next == nullptr) {
                last = curr;
            } else {
                prev->next = next;
                next->prev = prev;
            }
            delete curr;
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
            explicit Iterator(Node *head) : t(head) {}

            bool hasNext() override {
                return t->next != nullptr;
            }

            T next() override {
                t = t->next;
                return t->data;
            }
        };

        Iterator getIterator() {
            Iterator it(head);
            return it;
        }
    };

    template<typename T>
    class Stack {
    private:
        using Node = typename LinkedList<T>::Node;
        Node *head = nullptr;
        int len = 0;

    public:
        Stack() { head = new Node(); }

        ~Stack() {
            clear();
            delete head;
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
            explicit Iterator(Node *head) : t(head) {}

            bool hasNext() override {
                return t->next != nullptr;
            }

            T next() override {
                t = t->next;
                return t->data;
            }
        };

        Iterator getIterator() {
            Iterator it(head);
            return it;
        }
    };

    template<typename T>
    class Queue {
    private:
        using Node = typename LinkedList<T>::Node;
        Node *head = nullptr, *last = nullptr;
        int len = 0;

    public:
        Queue() {
            head = new Node;
            last = head;
        }

        ~Queue() {
            clear();
            delete head;
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

        bool isEmpty() { return len == 0; }

        int size() { return len; }

        T dequeue() {
            Node *first = head->next;
            if (first->next == nullptr) {
                last = head;
            }
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
            explicit Iterator(Node *head) : t(head) {}

            bool hasNext() override {
                return t->next != nullptr;
            }

            T next() override {
                t = t->next;
                return t->data;
            }
        };

        Iterator getIterator() {
            Iterator it(head);
            return it;
        }
    };
}// namespace bczhc

#endif// BCZHC_LINEAR_LIST_HPP
