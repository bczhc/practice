#include "Tree.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include "LinearList.hpp"

using namespace bczhc::linearlist;

int main(int argc, char **argv) {
    Queue<int> q;
    q.enqueue(0);
    printf("%i\n", q.dequeue());
    q.enqueue(1);
    printf("%i\n", q.dequeue());
    return 0;
}
