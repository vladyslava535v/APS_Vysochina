#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int A[50];
    int min = 101;
    // Заповнення масиву
    for (int i = 0; i < 50; i++) {
        A[i] = rand() % 201 - 100;
        cout << A[i] << " ";
    }

    // Пошук найменшого додатного числа
    for (int i = 0; i < 50; i++) {
        if (A[i] > 0 && A[i] < min) {
            min = A[i];
        }
    }
    // Заміна від'ємних чисел
    if (min != 101) {
        for (int i = 0; i < 50; i++) {
            if (A[i] < 0) {
                A[i] = min;
            }
        }

        cout << "\nResult:" << endl;
        for (int i = 0; i < 50; i++) {
            cout << A[i] << " ";
        }
    }
    else {
        cout << "\nNo positive numbers";
    }
    return 0;
} 