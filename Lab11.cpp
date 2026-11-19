
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Базовий клас точки
class Point {
protected:
    int x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    // Конструктор з параметрами, конструктор копіювання та деструктор
    Point(int a, int b) {
        x = a;
        y = b;
    }

    Point(const Point& p) {
        x = p.x;
        y = p.y;
    }

    ~Point() {
    }

    // Введення координат
    void input()
    {
        cout << "Enter x: ";
        cin >> x;

        cout << "Enter y: ";
        cin >> y;
    }

    // Виведення координат
    void output() {
        cout << "(" << x << ", " << y << ")\n";
    }

    // Обчислення відстані між точками, додавання координат двух точок та перевірка збігу
    float distance(Point p) {
        return sqrt((x - p.x) * (x - p.x) +
            (y - p.y) * (y - p.y));
    }

    Point add(Point p) {
        return Point(x + p.x, y + p.y);
    }

    bool isEqual(Point p) {
        return x == p.x && y == p.y;
    }
};

// Похідний клас пікселя
class Pixel : public Point {
private:
    string color;

public:
    // Конструктор за замовчуванням, з параметрами та копіювання
    Pixel() : Point() {
        color = "black";
    }

    // Конструктор з параметрами
    Pixel(int a, int b, string c) : Point(a, b) {
        color = c;
    }

    Pixel(const Pixel& p) : Point(p) {
        color = p.color;
    }

    // Виведення інформації про піксель
    void outputPixel() {
        cout << "Coordinates: ";
        output();

        cout << "Color: " << color << "\n";
    }
};

int main() {
    Point p1;
    Point p2(3, 4);
    Point p3(p2);

    // Введення координат першої точки
    cout << "Enter first point:\n";
    p1.input();

    cout << "\nFirst point: ";
    p1.output();
    cout << "Second point: ";
    p2.output();
    cout << "Copied point: ";
    p3.output();

    // Обчислення відстані, додавання координат та перевірка збігу точок
    cout << "\nDistance: " << p1.distance(p2) << "\n";

    Point sum = p1.add(p2);

    cout << "Sum of coordinates: ";
    sum.output();

    if (p1.isEqual(p2)) {
        cout << "Points are equal\n";
    }
    else {
        cout << "Points are not equal\n";
    }

    // Створення пікселя
    Pixel pixel(5, 7, "red");
    cout << "\nPixel information:\n";
    pixel.outputPixel();

    return 0;
}