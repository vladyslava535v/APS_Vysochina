#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;
    int* A = new int[size];
    int* B = new int[size];

    for (int* p = A; p < A + size; p++) {
        *p = rand() % 201 - 100;
    }

    // Виводжу початковий масив
    cout << "Initial array:\n";
    for (int* p = A; p < A + size; p++) {
        cout << *p << " ";
    }

    // Записала нулі, потім від'ємні і додатні числа
    int* q = B;

    for (int* p = A; p < A + size; p++) {
        if (*p == 0) {
            *q = *p;
            q++;
        }
    }
    for (int* p = A; p < A + size; p++) {
        if (*p < 0) {
            *q = *p;
            q++;
        }
    }
    for (int* p = A; p < A + size; p++) {
        if (*p > 0)
        {
            *q = *p;
            q++;
        }
    }
    // Копіюю результат у початковий масив
    for (int* p = A, *r = B; p < A + size; p++, r++) {
        *p = *r;
    }

    cout << "\nResult array:\n";
    for (int* p = A; p < A + size; p++) {
        cout << *p << " ";
    }

    delete[] A;
    delete[] B;
    return 0;
}