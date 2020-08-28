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
    static void bubbleSort(T *arr, int length, Comparable<T> &comparable) {
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
    static void insertionSort(T arr[], int length, Comparable<T> &comparable) {
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
    static void selectionSort(T *arr, int length, Comparable<T> &comparable) {
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
    static void shellSort(T *arr, int length, Comparable<T> &comparable) {
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
} // namespace sort
} // namespace bczhc
