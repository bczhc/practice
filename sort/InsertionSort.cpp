#include "Comparable.hpp"
#include <stdio.h>
template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void insertionSort(T arr[], int length, Comparable<T> &comparable) {
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0; --j) {
            if (comparable.compare(arr[j], arr[j - 1]) < 0)
                swap<T>(arr[j], arr[j - 1]);
            else
                break;
        }
    }
}

int main() {
    int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};
    class C : public Comparable<int> {
    public:
        int compare(int &a, int &b) override { return a - b; }
    } c;
    insertionSort(arr, 8, c);
    for (int i = 0; i < 8; ++i) {
        printf("%i ", arr[i]);
    }
    putchar('\n');
    return 0;
}
