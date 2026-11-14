#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    ifstream inFile("input.txt");
    if ( !inFile ) {
        cerr << "Error could not open file" << endl;
        return -1;
    }

    string line;
    int count_closed = 0;
    int count_opened = 0;

    while (getline(inFile, line)) {
        for ( int i = 0; i < line.length(); i++ ) {
            if (  line.substr(i, 4) == "<td>" ) {
                count_opened++;
            }
            else if ( line.substr(i, 5) == "</td>" ) {
                count_closed++;
            }
        }
        if ( count_closed > count_opened || count_opened - count_closed > 1 ) {
            cout << "file with wrong amount or order of opened and closed tags" << endl;
            inFile.close();
            return 0;
        }
    }
    if ( count_opened != count_closed ) {
        cout << "file with inappropriate amounts of opened and closed tags";
        cout << " opened tags: " << count_opened << " closed tags: " << count_closed << endl;
    }
    else cout << "file with appropriate amounts of closed tags, the file is correct" << endl;

    inFile.close();
    return 0;
}