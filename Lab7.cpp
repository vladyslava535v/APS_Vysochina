#include <iostream>
#include <string>
using namespace std;

struct Antelope {
    string name;
    char group;
    string place;
    int population;
};

int main() {
    Antelope a[10];
    int n;
    cout << "Enter number of antelopes (7-10): ";
    cin >> n;

    if (n < 7 || n > 10) {
        cout << "Incorrect number\n";
        return 0;
    }

    // Вносим дані
    for (int i = 0; i < n; i++) {
        cout << "\nAntelope " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> a[i].name;

        cout << "Group: ";
        cin >> a[i].group;

        cout << "Place: ";
        cin >> a[i].place;

        cout << "Population: ";
        cin >> a[i].population;
    }

    cout << "\nOriginal table:\n";
    cout << "Name\tGroup\tPlace\tPopulation\n";

    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << "\t"
            << a[i].group << "\t"
            << a[i].place << "\t"
            << a[i].population << "\n";
    }

    // Сортуєм за назвою
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j].name < a[i].name) {
                Antelope temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Інший варіант сортування за назвою через стандарт бібліотеку
    cout << "\nSorted table:\n";
    cout << "Name\tGroup\tPlace\tPopulation\n";

    for (int i = 0; i < n; i++) {
        cout << a[i].name << "\t"
            << a[i].group << "\t"
            << a[i].place << "\t"
            << a[i].population << "\n";
    }
    return 0;
}