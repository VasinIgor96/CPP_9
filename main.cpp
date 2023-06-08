#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void findNegativeBounds(const vector<int>& arr, int& leftIndex, int& rightIndex) {
    int size = arr.size();
    leftIndex = -1;
    rightIndex = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            leftIndex = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            rightIndex = i;
            break;
        }
    }
}

void sortBetweenBounds(vector<int>& arr, int leftIndex, int rightIndex) {
    sort(arr.begin() + leftIndex + 1, arr.begin() + rightIndex);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    vector<int> arr(SIZE);

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 41 - 20;
    }

    cout << "Початковий масив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int leftIndex, rightIndex;
    findNegativeBounds(arr, leftIndex, rightIndex);

    if (leftIndex != -1 && rightIndex != -1) {
        sortBetweenBounds(arr, leftIndex, rightIndex);

        cout << "Відсортований масив: ";
        for (int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Позиція найлівішого від'ємного елемента: " << leftIndex << endl;
        cout << "Позиція найправішого від'ємного елемента: " << rightIndex << endl;
    }
    else {
        cout << "В масиві немає від'ємних елементів." << endl;
    }

    return 0;
}
