#include <iostream>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    if (x >= -1 && y <= 1 && y >= x) {
        cout << "The point belongs to the area";
    }
    else {
        cout << "The point does not belong to the area";
    }
    return 0;
}