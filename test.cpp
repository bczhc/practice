#include "LinearList.hpp"
#include <cstdio>

int main() {
    bczhc::linearlist::SequentialList<const char *> list(2);
    list.insert("ym");
    list.insert("kb");
    list.insert("md");
    list.insert(1, "zms");

    int length = list.length();
    for (int i = 0; i < length; ++i) {
        printf("%s\n", list.get(i));
    }
    return 0;
}
