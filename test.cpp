#include "LinearList.hpp"
#include "Tree.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

using namespace bczhc::linearlist;

int main(int argc, char **argv) {
    DoublyLinkedList<int> l;
    l.insert(0);
    l.insert(1);
    printf("%i\n", l.remove(l.length() - 1));
    return 0;
}
