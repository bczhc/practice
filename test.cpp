#include "LinearList.hpp"
#include <cstdint>
#include <cstdio>
#include <stdlib.h>

int main(int argc, char **argv) {
    using Queue = bczhc::linearlist::Queue<int>;
    Queue q;
    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
    }
    Queue::Iterator it = q.getIterator();
    if (it.moveToFirst()) {
        do {
            printf("%i\n", it.get());
        } while (it.next());
    }
    return 0;
}
