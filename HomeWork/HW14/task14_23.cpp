#include <iostream>
#include <string>
#include <fstream>

using namespace std;


string readFile(const string& inputfile) {
    ifstream infile(inputfile);
    if (!infile) {
        cerr << "Error opening file: " << inputfile << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
    infile.close();
    return content;
}

void writeFile(const string& outputfile, const string& content) {
    ofstream outfile(outputfile);
    if (!outfile) {
        cerr << "Error opening file: " << outputfile << endl;
        return;
    }

    outfile << content;

    outfile.close();
}

int countEmptyLines(const string& filename) {
    string content = readFile(filename);
    int count = 0;
    size_t pos = 0;
    while ((pos = content.find('\n', pos)) != string::npos) {
        if (pos == 0 || content[pos - 1] == '\n') {
            count++;
        }
        pos++;
    }

    if (!content.empty() && content.back() == '\n') {
        count++;
    }
    return count;
}

int maxLineLength(const string& filename) {
    string content = readFile(filename);
    int maxLength = 0;
    size_t pos = 0;
    size_t lineStart = 0;

    while ((pos = content.find('\n', lineStart)) != string::npos) {
        int lineLength = pos - lineStart;
        if (lineLength > maxLength) {
            maxLength = lineLength;
        }
        lineStart = pos + 1;
    }


    if (lineStart < content.size()) {
        int lineLength = content.size() - lineStart;
        if (lineLength > maxLength) {
            maxLength = lineLength;
        }
    }

    return maxLength;
}

int main() {
    string inputfile = "input.txt";
    string outputfile = "output.txt";
    cout << "Number of empty lines: " << countEmptyLines(inputfile) << endl;
    cout << "Maximum line length: " << maxLineLength(inputfile) << endl;
    return 0;
}