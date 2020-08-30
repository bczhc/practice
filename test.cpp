#include "LinearList.hpp"
#include <cstdio>
#include <stdint.h>

using namespace bczhc::linearlist;
using Node = LinkedList<int>::Node;

int main() {
    Node *first = new Node(1, nullptr);
    Node *tail = first;
    for (int i = 2; i <= 41; ++i) {
        tail->next = new Node(i, nullptr);
        tail = tail->next;
    }
    tail->next = first;
    int16_t count = 0;
    Node *prev = nullptr;
    tail = first;
    while (tail->next != tail) {
        ++count;
        if (count == 3) {
            printf("%i ", tail->data);
            delete prev->next;
            prev->next = tail->next;
            count = 0;
        } else {
            prev = tail;
        }
        tail = tail->next;
    }
    printf("%i\n", tail->data);
    return 0;
}
