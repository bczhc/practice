#include "Sort.hpp"
#include <cstdio>
class C : public bczhc::sort::Comparable<int> {
public:
    int compare(int &a, int &b) { return a - b; }
};
int main() {
    int arr[] = {1,      4,   5,      2,   1,   5,    6,   4,   4,   4,
                 4,      4,   4,      4,   4,   4,    42,  243, 234, 324,
                 324324, 342, 342,    342, 342, 432,  432, 432, 342, 432,
                 432,    243, 243423, 423, 423, 432,  423, 324, 432, 432,
                 432,    432, 432,    43,  34,  2324, 324, 234, 324};
    C c;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%i \n", size);
    bczhc::sort::ShellSort::shellSort(arr, size, c);
    for (int i = 0; i < size; ++i)
        printf("%i ", arr[i]);
    putchar('\n');
    return 0;
}
