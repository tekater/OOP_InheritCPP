#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point() : x{ 0 }, y{ 0 } {};
    Point(int x, int y) : x{ x }, y{ y } {  };

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void print() const {
        cout << "(" << x << ";" << y << ")\n";
    }



};

class Figure {
    Point* points;
    int count;
public:
    Figure(int count) {
        points = new Point[count];
        this->count = count;
    }

    Figure() :Figure(5) {  };

    void print() {
        cout << "Points:\n";
        for (int i = 0; i < count; i++) {
            points[i].print();
        }
        cout << endl;
    }

    void setFigure() {
        for (int i = 0; i < count; i++) {
            points[i].setPoint(rand() % 10 + 1,rand() % 10 + 1);
        }
    }

    ~Figure() {
        delete[] points;
    }
};

class Picture {
    Figure* figure;
    int count;
public:
    Picture(int c) {
        count = c;
        figure = new Figure[count];
    }

    void setPicture() {
        for (int i = 0; i < count; i++) {
            figure[i].setFigure();
        }
    }

    void print() {
        cout << "Картина:\n";
        for (int i = 0; i < count; i++) {
            cout << "Фигура " << i+1 << ":\n";
            figure[i].print();
            //cout << endl;
        }
    }

    ~Picture() {
        delete[] figure;
    }
};

class Window:public Point {
    int height;
    int width;
public:
    Window(int x, int y, int h, int w) :Point{ x,y }, height{ h }, width{ w } {};

    void print() {
        cout << x << " " << y << " " << height << " " << width << "\n";
    }

    void MoveX(int dx) {
        x += dx;
    }
    void MoveY(int dy) {
        y += dy;
    }

    int& setgetX() {
        return height;
    }
};

class Student {
protected:
    string name;
    int group;
public:
    Student() {
        name = "None";
        group = 0;
    }
    Student(string n, int g) {
        name = n;
        group = g;
    }
    void setName(string n) {
        name = n;
    }
    void setGroup(int g) {
        group = g;
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Group: " << group << endl;
    }
};

class Aspirant : public Student {
    string dip;
    bool def;
public:
    Aspirant(string name, int g, string d, bool df) :Student(name, g) {
        def = df;
        dip = d;
    }

    string& setgetDip() {
        return dip;
    }

    bool& setgeyDef() {
        return def;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Group: " << group << endl;
        cout << "Def: " << def << endl;
        cout << "Diplom: " << dip << endl;
    }
};

class Animals {
protected:
    string name;
    int year;
public:
    Animals(string n, int y) {
        name = n;
        year = y;
    }
    Animals() {
        Animals("None", 0);
    }
    void print() {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
    }
};

class Dog : public Animals {
    int commands;
public:
    Dog(string n, int y, int com) :Animals(n, y),commands { com } {}
    void print() {
        Animals::print();
        cout << "Commands: " << commands << endl;
    }
};

class Cat : public Animals {
    int sleeptime;
public:
    Cat(string n, int y, int st) :Animals(n, y), sleeptime{ st } {}
    void print() {
        Animals::print();
        cout << "SleepTime: " << sleeptime << endl;
    }
};

class Parrot : public Animals {
    string words;
public:
    Parrot(string n, int y, string w) :Animals(n, y),words{w}{}
    void print() {
        Animals::print();
        cout << "Words: " << words << endl;
    }

};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    Picture p(5);
    p.setPicture();
    p.print();

    Window w{ 2,5,10,20 };
    w.print(); 
    cout << w.setgetX() << endl; // get
    w.setgetX() = 50; // set
    w.print();
    
    w.MoveX(5);
    w.MoveY(-7);
    w.print();
}
