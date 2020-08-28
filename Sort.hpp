#include <stdc-predef.h>
namespace bczhc {
template <typename T> static void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
namespace sort {
template <typename T> class Comparable {
public:
    virtual int compare(T &a, T &b) = 0;
};

class BubbleSort {
public:
    template <typename T>
    static void sort(T *arr, int length, Comparable<T> &comparable) {
        int temp;
        for (int j = length - 1; j > 0; --j) {
            for (int i = 0; i < j; ++i) {
                if (comparable.compare(arr[i], arr[i + 1]) > 0) {
                    temp = arr[i + 1];
                    arr[i + 1] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
};

class InsertionSort {
private:
public:
    template <typename T>
    static void sort(T arr[], int length, Comparable<T> &comparable) {
        for (int i = 1; i < length; ++i) {
            for (int j = i; j > 0; --j) {
                if (comparable.compare(arr[j], arr[j - 1]) < 0)
                    swap<T>(arr[j], arr[j - 1]);
                else
                    break;
            }
        }
    }
};

class SelectionSort {
public:
    template <typename T>
    static void sort(T *arr, int length, Comparable<T> &comparable) {
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
};
class ShellSort {
public:
    template <typename T>
    static void sort(T *arr, int length, Comparable<T> &comparable) {
        int h = 1;
        while (h < length / 2)
            h = 2 * h + 1;
        while (h > 0) {
            for (int i = h; i < length; ++i) {
                for (int j = i; j >= h; j -= h) {
                    if (comparable.compare(arr[j], arr[j - h]) < 0) {
                        swap(arr[j], arr[j - h]);
                    } else
                        break;
                }
            }
            h /= 2;
        }
    }
};

template <typename T> class MergeSort {
public:
    static T *assist;
    static Comparable<T> *comparable;
    static void sort(T *arr, int length, Comparable<T> &comparable) {
        assist = (T *)new T[length];
        MergeSort<T>::comparable = &comparable;
        sort(arr, 0, length - 1);
        delete[] assist;
    }

private:
    static void sort(T *arr, int left, int right) {
        if (left >= right)
            return;
        int mid = (left + right) / 2;
        sort(arr, left, mid), sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    static void merge(T *&arr, int left, int mid, int right) {
        int i = 0, p = left, q = mid + 1;
        for (;;) {
            if (comparable->compare(arr[p], arr[q]) < 0)
                assist[i] = arr[p], ++p;
            else
                assist[i] = arr[q], ++q;
            ++i;
            if (p == mid + 1) {
                while (q <= right)
                    assist[i++] = arr[q++];
                break;
            }
            if (q == right + 1) {
                while (p <= mid) {
                    assist[i++] = arr[p++];
                }
                break;
            }
        }
        for (int i = left; i <= right; ++i)
            arr[i] = assist[i - left];
    }
};

template <typename T> T *MergeSort<T>::assist = nullptr;
template <typename T> Comparable<T> *MergeSort<T>::comparable = nullptr;

} // namespace sort
} // namespace bczhc
