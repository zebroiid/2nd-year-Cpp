//
// Created by markp on 23/11/2026.
//
#include <iostream>
#include <cmath>

using namespace std;

double taylorSin(double x, double eps) {
    double term = x;
    double result = term;
    int n = 1;

    while (fabs(term) >= eps) {
        term = -term * (x * x) / ((2 * n)*(2*n + 1));
        result = result + term;
        n++;

    }
    return result;
}

int main() {
    double x, eps;
    cout << "input x: " << endl;
    while (!(cin >> x)){
        cin.clear();
        cin.ignore();
    }
    cout << "input eps: " << endl;
    while (!(cin >> eps) || eps <= 0.0 || eps >= 1.0) {
        cin.clear();
        cin.ignore();
    }
    cout << "taylor sum for sin(x)" << endl;
    cout << taylorSin(x, eps) << endl;
}

