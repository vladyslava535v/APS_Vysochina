#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	char name1[50]{}, name2[50]{}, name3[50]{};
	char group1, group2, group3;
	char place1[10]{}, place2[10]{}, place3[10]{};
	unsigned short  count1, count2, count3;

	// Ведення даних
	cout << "1.Enter name, group, location, population count: " << endl;
	cin >> name1 >> group1 >> place1 >> count1;
	cout << "2. Enter name, group, location, population count: " << endl;
	cin >> name2 >> group2 >> place2 >> count2;
	cout << "3. Enter name, group, location, population count: " << endl;
	cin >> name3 >> group3 >> place3 >> count3;

	// Виведення таблиці
	cout << "_________________________________________________" << endl;
	cout << "| Some spesies of antelopes                     |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "| Name    | Group | Location | Population       |" << endl;
	cout << "|_________|_______|__________|__________________|" << endl;


	// Виведення рядків фактичних даних
	cout << "| " << setw(7) << left << name1 << " |  " << setw(3) << group1 << "  | " << setw(8) << left << place1 << " | " << setw(16) << right << count1 << " | " << endl;
	cout << "| " << setw(7) << left << name2 << " |  " << setw(3) << group2 << "  | " << setw(8) << left << place2 << " | " << setw(16) << right << count2 << " | " << endl;
	cout << "| " << setw(7) << left << name3 << " |  " << setw(3) << group3 << "  | " << setw(8) << left << place3 << " | " << setw(16) << right << count3 << " | " << endl;

	cout << "|_________|_______|__________|__________________|" << endl;

	// Примітка
	cout << "|    Groups: A - true antelopes,                |" << endl;
	cout << "| B - hartebeests, H - horse antelopes          |" << endl;
	cout << "|_______________________________________________|" << endl;

	return 0;
}