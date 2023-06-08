#include <iostream>
#include <Windows.h>

using namespace std;

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void insertionSort(int arr[], int start, int end, bool ascending) {
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;

        if (ascending) {
            while (j >= start && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else {
            while (j >= start && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }
}

void sortHalfArray(int arr[], int size) {
    int middle = size / 2;

    insertionSort(arr, 0, middle - 1, false);
    insertionSort(arr, middle, size - 1, true);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 7, 3, 9, 2, 5, 1, 8, 4, 6, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortHalfArray(arr, size);

    cout << "Відсортований масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
