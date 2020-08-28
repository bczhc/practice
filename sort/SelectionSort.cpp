#include "Comparable.hpp"
#include <stdio.h>

template <typename T>
void SelectionSort(T *arr, int length, Comparable<T> &comparable) {
    for (int i = 0; i < length - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (comparable.compare(arr[j], arr[minIndex]) < 0)
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {4, 6, 8, 7, 9, 2, 10, 1};
    class C : public Comparable<int> {
    public:
        int compare(int &a, int &b) override { return a - b; }
    } c;
    SelectionSort(arr, 8, c);
    for (int i = 0; i < 8; ++i) {
        printf("%i ", arr[i]);
    }
    putchar('\n');
    return 0;
}
