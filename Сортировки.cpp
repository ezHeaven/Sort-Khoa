#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long counter = 0;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            counter++;
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int sorted = i - 1;
        while (sorted > -1 && (counter++, arr[sorted] > arr[sorted + 1])) {
            int temp = arr[sorted];
            arr[sorted] = arr[sorted + 1];
            arr[sorted + 1] = temp;
            sorted--;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[low + (high - low) / 2];
    int i = low;
    int j = high;

    while (i <= j) {
        while (counter++, arr[i] < pivot) {
            i++;
        }
        while (counter++, arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(arr, low, j);
    }
    if (i < high) {
        quickSort(arr, i, high);
    }
}

int main() {
    const int n = 10000;
    int a[n], b[n], c[n];
    srand(time(0));
    for (int i = 0; i < 10000; ++i) {
        a[i] = rand() % 201 - 100;
        b[i] = a[i];
        c[i] = a[i];
    }

    clock_t start = clock();
    counter = 0;
    bubbleSort(a, n);
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Пузьрьковая сортировка: " << counter << ", время = " << time << " сек" << endl;

    start = clock();
    counter = 0;
    insertionSort(b, n);
    end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Сортировка вставками: " << counter << ", время = " << time << " сек" << endl;

    start = clock();
    counter = 0;
    quickSort(c, 0, n - 1);
    end = clock();
    time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Сортировка Хоара: " << counter << ", время = " << time << " сек" << endl;

    return 0;
}
