#include "LinearList.hpp"
#include <cstdio>
#include <stdint.h>

int main() {
    using Stack = bczhc::linearlist::Stack<const char *>;
    Stack stack;
    stack.push("a");
    stack.push("b");
    stack.push("c");
    stack.push("d");
    Stack::Iterator it = stack.getIterator();
    if (it.moveToFirst()) {
        do {
            printf("%s\n", it.get());
        } while (it.next());
    }
    if (stack.size() == 0)
        return 0;
    printf("--------------\n");
    printf("%s\n", stack.pop());
    printf("%i\n", stack.size());
    return 0;
}
