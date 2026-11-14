#include <iostream>
#include <fstream>

using namespace std;

void reverse_words_in_file(const string& input_filename, const string& output_filename) {
    ifstream inFile(input_filename);
    if (!inFile) {
        cerr << "Unable to open file " << input_filename << endl;
        return;
    }

    ofstream outFile(output_filename);
    if (!outFile) {
        cerr << "Unable to open file " << output_filename << endl;
        return;
    }

    char c;
    while (inFile.get(c)) {
        cout << c;
        if (isalpha(c)) {
            string word;
            word += c;
            while (inFile.get(c) && isalpha(c)) {
                word += c;
            }
            for (int i = word.length() - 1; i >= 0; --i) {
                outFile << word[i];
            }
            if (!inFile.eof()) {
                outFile << c;
            }

        } else if (c == ' ' || c == '\n' || c == '!' || c == '?' || c == '.' || c == ',') {
            outFile << c;
        } else {
            cerr << "Invalid character in input: " << c << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    string input_filename = "input.txt";
    string output_filename = "output.txt";

    reverse_words_in_file(input_filename, output_filename);

    return 0;
}