#include "LinearList.hpp"
#include <cstdio>

int main() {
    bczhc::linearlist::LinkedList<const char *> list;
    list.insert("ym");
    list.insert("kb");
    list.insert("md");
    list.insert(1, "zms");
    bczhc::linearlist::LinkedList<const char *>::Iterator it =
        list.getIterator();
    do {
        printf("%s\n", it.value());
    } while (it.next());
    list.reverse();
    putchar('\n');
    bczhc::linearlist::LinkedList<const char *>::Iterator it2 =
        list.getIterator();
    do {
        printf("%s\n", it2.value());
    } while (it2.next());

    return 0;
    printf("-----------------\n");
    printf("%s\n", list.get(1));
    printf("%s\n", list.remove(0));
    printf("%i\n", list.length());
    return 0;
}
