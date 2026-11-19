#include <iostream>
using namespace std;

// Функція заповнення нулями
void init(int* A, int n) {
    for (int i = 0; i < n * n; i++) {
        A[i] = 0;
    }
}

// Функція заповнення матриці
void process(int* A, int n) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((j < i && j < n - 1 - i) ||
                (j > i && j > n - 1 - i)) {
                A[i * n + j] = k;
                k++;
            }
        }
    }
}

// Функція виведення матриці
void print(int* A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i * n + j] << "\t";
        }
        cout << "\n";
    }
}
int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;
    if (n < 1 || n > 24) {
        cout << "Incorrect size.\n";
        return 0;
    }
    int* A = new int[n * n];
    init(A, n);
    process(A, n);
    cout << "Result:\n";
    print(A, n);

    delete[] A;

    return 0;
}