#include "Comparable.hpp"
#include <cstdio>
template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void shellSort(T *arr, int length, Comparable<T> &comparable) {
    int h = 1;
    while (h < length / 2)
        h = 2 * h + 1;
    while (h > 0) {
        for (int i = h; i < length; ++i) {
            for (int j = i; j > 0; j -= h) {
                if (comparable.compare(arr[j], arr[j - h]) < 0)
                    swap(arr[j], arr[j - h]);
                else
                    break;
            }
        }
        h /= 2;
    }
}

int main() {
    int arr[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
    class C : public Comparable<int> {
    public:
        int compare(int &a, int &b) override { return a - b; }
    } c;
    shellSort(arr, 10, c);
    for (int i = 0; i < 10; ++i) {
        printf("%i ", arr[i]);
    }
    putchar('\n');
    return 0;
}
