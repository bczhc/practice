#include "LinearList.hpp"
#include <cstdio>

int main() {
    bczhc::linearlist::LinkedList<int> list;
    for (int i = 0; i < 10; ++i) {
        list.insert(i);
    }
    int mid = list.getMid();
    printf("%i\n", mid);
    bczhc::linearlist::LinkedList<int>::Iterator it = list.getIterator();
    do {
        printf("%i\n", it.value());
    } while (it.next());
}
