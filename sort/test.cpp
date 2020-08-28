#include "Comparable.hpp"
#include <cstdio>
#include <sys/time.h>
#include <cstdint>
#include "SelectionSort.hpp"
#include "ShellSort.hpp"

int main() {
    int *arr = new int[100000];
    for (int i = 0; i < 100000; ++i)
        arr[i] = i;
    class C : public Comparable<int> {
        public:
        int compare(int &a, int &b) override {
            return a - b;
        }
    } c;
    timeval start, end;
    gettimeofday(&start, nullptr);
    shellSort(arr, 100000, c);
    gettimeofday(&end, nullptr);
    int64_t time = start.tv_sec * 1000 - end.tv_sec * 1000 + start.tv_usec / 1000 - end.tv_usec / 1000;
    printf("%lldms\n", (long long) time);
    return 0;
}
