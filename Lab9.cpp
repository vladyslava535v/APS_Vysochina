#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Antelope {
    char name[30];
    char group;
    char place[30];
    int population;
};

// Створюєм файлік з даними
void initf() {
    ofstream file("antelopes.dat", ios::binary);
    file.close();
}

// Додаєм запис у нього
void f_add(Antelope* a) {
    ofstream file("antelopes.dat", ios::binary | ios::app);
    file.write((char*)a, sizeof(Antelope));
    file.close();
}

// Читаєм запис з файлу
void readRecord(int number, Antelope* a) {
    ifstream file("antelopes.dat", ios::binary);

    file.seekg(number * sizeof(Antelope));
    file.read((char*)a, sizeof(Antelope));

    file.close();
}

// Додаєм запис у файлі на позицію
void writeRecord(int number, Antelope* a) {
    fstream file("antelopes.dat", ios::binary | ios::in | ios::out);

    file.seekp(number * sizeof(Antelope));
    file.write((char*)a, sizeof(Antelope));

    file.close();
}

// Показуєм всі записи з файлу
void fshow_all()
{
    ifstream file("antelopes.dat", ios::binary);
    Antelope a;

    cout << "\nName\tGroup\tPlace\tPopulation\n";

    while (file.read((char*)&a, sizeof(Antelope)))
    {
        cout << a.name << "\t"
            << a.group << "\t"
            << a.place << "\t"
            << a.population << "\n";
    }

    file.close();
}

void sortFile(int n) {
    Antelope a;
    char minName[30];
    int minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        readRecord(i, &a);
        strcpy(minName, a.name);

        for (int j = i + 1; j < n; j++) {
            readRecord(j, &a);

            if (strcmp(a.name, minName) < 0) {
                strcpy(minName, a.name);
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Зберігаєм запис з мін ім'ям у тимчасовий файл
            readRecord(i, &a);

            ofstream temp("temp.dat", ios::binary);
            temp.write((char*)&a, sizeof(Antelope));
            temp.close();
            readRecord(minIndex, &a);
            writeRecord(i, &a);

            // Повертаєм запис з тимчасового файлу на місце мін ім'я
            ifstream tempIn("temp.dat", ios::binary);
            tempIn.read((char*)&a, sizeof(Antelope));
            tempIn.close();
            writeRecord(minIndex, &a);
        }
    }
}

int main() {
    Antelope a;
    int n;

    cout << "Enter number of records (7-10): ";
    cin >> n;
    if (n < 7 || n > 10) {
        cout << "Incorrect number!\n";
        return 0;
    }
    initf();
    // Запонюєм файл
    for (int i = 0; i < n; i++) {
        cout << "\nAntelope " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> a.name;
        cout << "Group: ";
        cin >> a.group;
        cout << "Place: ";
        cin >> a.place;
        cout << "Population: ";
        cin >> a.population;
        f_add(&a);
    }

    cout << "\nOriginal table:";
    fshow_all();
    sortFile(n);
    cout << "\nSorted table:";
    fshow_all();
    return 0;
}