#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter a natural number n: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Please enter a valid positive integer." << endl;
        return 0;
    }

    int line_length = n * 8;

    for (int i = 0; i < line_length; ++i) {
        cout << "+";
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << setw(7) << i << " ";
    }
    cout << "\n";

    for (int i = 0; i < line_length; ++i) {
        cout << "+";
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        double root = sqrt(i);
        if (root == floor(root)) {
            cout << setw(7) << fixed << setprecision(0) << root << " ";
        } else {
            cout << setw(7) << fixed << setprecision(2) << root << " ";
        }
    }
    cout << "\n";

    for (int i = 0; i < line_length; ++i) {
        cout << "+";
    }
    cout << "\n";

    return 0;
}