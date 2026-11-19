#include <iostream>
#include <string>
using namespace std;

class Antelope {
private:
    string name;
    char group;
    string place;
    int population;

public:
    // Функція для запису даних
    void set(string n, char g, string p, int pop) {
        name = n;
        group = g;
        place = p;
        population = pop;
    }

    // Функція для отримання даних
    void get(string& n, char& g, string& p, int& pop) {
        n = name;
        g = group;
        p = place;
        pop = population;
    }

    // Функція для виведення даних
    void show() {
        cout << "Name: " << name << "\n";
        cout << "Group: " << group << "\n";
        cout << "Place: " << place << "\n";
        cout << "Population: " << population << "\n";
    }
};

int main() {
    Antelope a1, a2, a3;

    // Дані про антилоп
    a1.set("Dzheyran", 'A', "Asia", 30000);
    a2.set("Gnu", 'B', "Africa", 560000);
    a3.set("Beiza", 'H', "Africa", 2500);

    cout << "ANTelope 1:\n";
    a1.show();
    cout << "\nANTelope 2:\n";
    a2.show();
    cout << "\nANTelope 3:\n";
    a3.show();

    string name, place;
    char group;
    int population;

    a1.get(name, group, place, population);

    cout << "\nData received using get():\n";
    cout << name << " " << group << " "
        << place << " " << population << "\n";

    return 0;
}