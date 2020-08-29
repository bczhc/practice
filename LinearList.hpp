#include "Sort.hpp"

namespace bczhc {
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
} // namespace linearlist
} // namespace bczhc
