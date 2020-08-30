#include "LinearList.hpp"
#include <cstdio>

int main() {
    bczhc::linearlist::LinkedList<int> list;
    for (int i = 0; i < 530000; ++i) {
        list.insert(i);
    }
    list.reverse();
    bczhc::linearlist::LinkedList<int>::Iterator it = list.getIterator();
    do {
        printf("%i\n", it.value());
    } while (it.next());
}
