#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

void sortArray(int arr[], int size, bool ascending = false) {
    if (ascending) {
        sort(arr, arr + size);
    }
    else {
        sort(arr, arr + size, greater<int>());
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 5, 3, 8, 2, 9, 1, 7, 6, 4, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Початковий масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArray(arr, size, true);

    cout << "Відсортований масив (за зростанням): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArray(arr, size, false);

    cout << "Відсортований масив (за спаданням): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
