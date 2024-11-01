#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

// Макроси для основних операцій
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define POWER(a, b) (pow((a), (b)))
#define SQUARE(a) ((a) * (a))

// Функції для обчислення w з різними формулами
double calculateWFormula1(double x, double y, double z) {
    return MIN(SQUARE(x - z), x - y);
}

double calculateWFormula2(double x, double y, double z) {
    return MAX(x * y, y * z) + MIN(z * x, y * z);
}

// Функція для вибору формули на основі значення z
double calculateW(double x, double y, double z) {
#ifdef USE_FORMULA1
    return calculateWFormula1(x, y, z);
#else
    return calculateWFormula2(x, y, z);
#endif
}

int main() {
    double x, y, z;

    // Введення значень змінних від користувача
    cout << "Enter values for x, y, and z: ";
    cin >> x >> y >> z;

    // Використання умови для вибору потрібної формули
    if (z > 3) {
#define USE_FORMULA1
    }
    else {
#undef USE_FORMULA1
    }

    // Обчислення w
    double w = calculateW(x, y, z);

    // Виведення результату
    cout << "The result of w is: " << w << endl;

    return 0;
}
