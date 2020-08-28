#include "Comparable.hpp"
#include <stdio.h>

template <typename T>
void bubbleSort(T arr[], int length, Comparable<T> &comparable) {
    int temp;
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < length - 1 - j; ++i) {
            if (comparable.compare(arr[i], arr[i + 1]) > 0) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {4, 5, 6, 3, 2, 1};
    class C : public Comparable<int> {
    public:
        int compare(int &a, int &b) override { return a - b; }
    } c;
    bubbleSort<int>(arr, 6, c);
    for (int i = 0; i < 6; ++i) {
        printf("%i ", arr[i]), putchar('\n');
    }
    return 0;
}
