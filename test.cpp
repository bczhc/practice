#include "Sort.hpp"
#include <cstdio>

int main() {
    struct A {
        const char *s;
        int b;
    };
    class C : public bczhc::sort::Comparable<A> {
    public:
        int compare(A &a, A &b) { return a.b - b.b; }
    } c;
    A arr[3];
    arr[0].b = 3, arr[0].s = "a";
    arr[1].b = 2, arr[1].s = "b";
    arr[2].b = 1, arr[2].s = "c";
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%i \n", size);
    bczhc::sort::SelectionSort<A>::sort(arr, size, c);
    for (int i = 0; i < size; ++i)
        printf("%s ", arr[i].s);
    putchar('\n');
    return 0;
}
