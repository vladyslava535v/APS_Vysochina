#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int A[9][9];
    int B[9][9];

    // Заповнення першої матриці
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
        {
            A[i][j] = rand() % 100;
        }
    }

    // Виведення першої матриці
    cout << "Initial matrix:" << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Поворот матриці на 90 градусів
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            B[j][8 - i] = A[i][j];
        }
    }

    // Виведення повернутої матриці
    cout << "\nRotated matrix:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    //Використовувала endl бо через \n не захотіло відступи робити в цій лабі
    return 0;
} 