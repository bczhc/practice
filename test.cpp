#include "LinearList.hpp"
#include <cstdio>
#include <stdint.h>

using Stack = bczhc::linearlist::Stack<char>;

bool isValid(const char *s) {
    Stack stack;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(')
            stack.push(s[i]);
        else if (s[i] == ')') {
            if (stack.size() == 0)
                return false;
            if (stack.pop() != '(')
                return false;
        }
    }
    return stack.size() == 0;
}

int main(int argc, char **argv) {
    const char *s = argv[1];
    printf("%i\n", isValid(s));
    return 0;
}
