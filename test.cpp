#include "Sort.hpp"
#include <cstdio>

int main() {
    class C : public bczhc::sort::Comparable<int> {
    public:
        int compare(int &a, int &b) { return a - b; }
    } c;
    int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%i \n", size);
    bczhc::sort::QuickSort<int>::sort(arr, size, c);
    for (int i = 0; i < size; ++i)
        printf("%i ", arr[i]);
    putchar('\n');
    return 0;
}
