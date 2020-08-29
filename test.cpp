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
    printf("-----------------\n");
    printf("%s\n", list.get(1));
    printf("%s\n", list.remove(0));
    list.clear();
    printf("%i\n", list.length());
    return 0;
}
