#include <iostream>
#include <string>
using namespace std;

struct Antelope {
    string name;
    char group;
    string place;
    int population;
};

struct Node {
    Antelope data;
    Node* next;
};

int main() {
    Node* first = NULL;
    Node* last = NULL;
    int n;
    cout << "Enter number of antelopes (7-10): ";
    cin >> n;

    if (n < 7 || n > 10) {
        cout << "Incorrect number.\n";
        return 0;
    }

    // Input data and create queue
    for (int i = 0; i < n; i++) {
        Node* element = new Node;

        cout << "\nAntelope " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> element->data.name;
        cout << "Group: ";
        cin >> element->data.group;
        cout << "Place: ";
        cin >> element->data.place;
        cout << "Population: ";
        cin >> element->data.population;

        element->next = NULL;
        if (first == NULL) {
            first = element;
            last = element;
        }
        else {
            last->next = element;
            last = element;
        }
    }

    cout << "\nOriginal table:\n";
    cout << "Name\tGroup\tPlace\tPopulation\n";

    Node* current = first;

    while (current != NULL) {
        cout << current->data.name << "\t"
            << current->data.group << "\t"
            << current->data.place << "\t"
            << current->data.population << "\n";

        current = current->next;
    }

    // Сортуєм за зростанням за назвою
    for (Node* i = first; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data.name < i->data.name) {
                Antelope temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    cout << "\nSorted table:\n";
    cout << "Name\tGroup\tPlace\tPopulation\n";

    current = first;

    while (current != NULL) {
        cout << current->data.name << "\t"
            << current->data.group << "\t"
            << current->data.place << "\t"
            << current->data.population << "\n";

        current = current->next;
    }

    // Видаляєм елементи з черги
    while (first != NULL) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    return 0;
}