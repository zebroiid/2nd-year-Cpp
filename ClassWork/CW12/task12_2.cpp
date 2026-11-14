#include <iostream>
#include <cstdio>

typedef unsigned long long ULL;
using namespace std;

int main() {

    ULL sum=0, tmp;
    ULL *a;
    int n;

    cout << "enter the number of elements: ";
    cin >> n;

    a = new ULL[n];

    for (int i = 0; i < n; i++) {
        a[i] = 0;

        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;

            if (c < '0' || c > '9') {
                delete[] a;
                return 0;
            }

            a[i] = a[i] * 10 + (c - '0');
        }

        sum += a[i];
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << endl;

    cout << "Sum = " << sum << endl;

    delete[] a;

    return 0;
}