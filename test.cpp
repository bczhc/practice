#include "LinearList.hpp"
#include <cstdio>

int main() {
    bczhc::linearlist::DoublyLinkedList<const char *> list;
    list.insert("ym");
    list.insert("kb");
    list.insert("md");
    list.insert(1, "zms");
    bczhc::linearlist::DoublyLinkedList<const char *>::Iterator it =
        list.getIterator();
    do {
        printf("%s\n", it.value());
    } while (it.next());
    printf("-----------------\n");
    printf("%s\n", list.getFirst());
    printf("%s\n", list.getLast());
    printf("-----------------\n");
    printf("%s\n", list.get(1));
    printf("%s\n", list.remove(0));
    printf("%i\n", list.length());
    return 0;
}
