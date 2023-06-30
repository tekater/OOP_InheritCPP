#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class Horns {
protected:
    int length;
    double weight;
public:
    Horns(int length, double weight) : length{ length }, weight{ weight } {  };
    void print() {
        cout << "Horns:\nLength: " << length << "\nWeight: " << weight << endl;
    }
};

class Fur {
protected:
    string color;
    int length;
public:
    Fur(string color, int length) : color{ color }, length{ length } {  };
    void print() {
        cout << "Fur:\nColor: " << color << "\nLength: " << length << endl;
    }
};

class Elk : public Horns, public Fur {
    string name;
    int age;
public:
    Elk(string name,int age, string color, int lengthH, int lengthF, double weight) : name{ name },age{age},
        Horns{ lengthH,weight }, Fur{ color,lengthF } {}
    void print() {
        cout << "Elk:\n";
        cout << "Name: " << name << "\nAge: " << age << endl;
        /*Horns::print();
        Fur::print();*/
        cout << "\nHorns:\nLength: " << Horns::length << "\nWeight: " << weight << endl;
        cout << "\nFur:\nColor: " << color << "\nLength: " << Fur::length << endl;
        
    }
};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));
    Elk elk{ "Ella",15,"brown",30,190,40 };
    elk.print();

}
