#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        return 1;
    }
    int x = 0;
    int sum = 0;
    char c;
    if (inFile >> x) {
        sum = x;
    }
    while (inFile >> c) {
        if (c == '=') {
            break;
        }
        inFile >> x;
        if (c == '+') {
            sum += x;
        } else if (c == '-') {
            sum -= x;
        }
    }
    cout << sum << endl;
    inFile.close();
    return 0;
}