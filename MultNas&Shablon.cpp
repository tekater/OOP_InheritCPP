#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

template<class T,class T2>
class base {
protected:
    T value1;
    T2 value2;
public:
    base(T value1, T2 value2) : value1{ value1 }, value2{ value2 } {};

    void print() const {
        cout << value1 << " " << value2 << endl;
    }
};

template <class T,class T2,class T3,class T4>
class child : public base<T, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    child(T value1, T2 value2, T3 value3, T4 value4) : base<T, T2>{ value1,value2 }, value3{ value3 }, value4{ value4 } {};
    void print() const {
        cout << base<T, T2>::value1 << " " << base<T, T2>::value2 << " " << value3 << " " << value4 << endl;
    }
};

template <class T, class T2, class T3, class T4, class T5, class T6>
class child2 : public child< T,  T2,  T3,  T4> {
    T5 value5;
    T6 value6;
public:
    child2(T value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) :
        child< T, T2, T3, T4>{value1, value2, value3, value4},
        value5{ value5 }, value6{ value6 } {};

    void print() const {
        cout << base<T, T2>::value1 << " " << base<T, T2>::value2 << " ";
        cout << child< T, T2, T3, T4>::value3 << " ";
        cout << child< T, T2, T3, T4>::value4 << " ";
        cout << value5 << " " << value6 << endl;
    }
};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    base<int, double> b{ 5, 10.5 };
    cout << "B:\n"; b.print();

    child<int, double, char, int> c1{ 5, 10.5, '*', 100 };
    cout << "\nC1:\n"; c1.print();

    child2<int, double, char, int, char, string> c2{ 5, 10.5, '*', 100 ,'!',"Hello"};
    cout << "\nC2:\n"; c2.print();
}
