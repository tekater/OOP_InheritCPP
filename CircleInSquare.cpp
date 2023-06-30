#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class Square {
protected:
    int a;
public:
    Square(int a) :a{ a } {}
    void print() {
        cout << "a: " << a << endl;
    }
};

class Circle {
protected:
    double r;
    double L;
public:
    Circle(double r) :r{ r }, L{ (2 * 3.141592653589793238463) * r } {};
    void print() {
        cout << "r: " << r << endl;
        cout << "L: " << L << endl;
    }
};

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(int a):Square{ a }, Circle{ (double)a / 2 } {};
    void print() {
        cout << "В квадрат со стороной: " << a << "\nможно вписать окружность длины " << L << endl;
    }
};


int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    Square s{ 10 };
    s.print();

    Circle c{ 15 };
    c.print();

    CircleInSquare CIN{ 9 };
    CIN.print();

    cout << (2 * 0, 14) * 2;
}
