#include "LinearList.hpp"
#include <cstdint>
#include <cstdio>
#include <stdlib.h>

using Stack = bczhc::linearlist::Stack<int>;

int evaluate(char **ss, int length) {
    Stack stack;
    char *s;
    int o1, o2;
    for (int i = 0; i < length; ++i) {
        s = ss[i];
        switch (s[0]) {
        case '+':
            o1 = stack.pop();
            o2 = stack.pop();
            stack.push(o1 + o2);
            break;
        case '-':
            o1 = stack.pop();
            o2 = stack.pop();
            stack.push(o2 - o1);
            break;
        case '*':
            o1 = stack.pop();
            o2 = stack.pop();
            stack.push(o1 * o2);
            break;
        case '/':
            o1 = stack.pop();
            o2 = stack.pop();
            stack.push(o2 / o1);
            break;
        default:
            stack.push(atoi(s));
            break;
        }
    }
    return stack.pop();
}

int main(int argc, char **argv) {
    const char *s = argv[1];
    int r = evaluate(argv + 1, argc - 1);
    printf("%i\n", r);
    return 0;
}
