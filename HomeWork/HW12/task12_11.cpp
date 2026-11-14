#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define MAX_NUM_OF_NUM 20


std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

int ProcessNumbers(const std::string& filename, int maxPrecision = 0) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }


    
    size_t size = 0;
    double* numbers = new double[MAX_NUM_OF_NUM];
    std::string number;


    while (std::getline(inFile, number, ';')) {
        number = trim(number);
        if (number.empty()) continue;


        for (size_t i = 0; i < number.length(); ++i) {
            if (number[i] == ',') {
                number[i] = '.';
            }
        }

        size_t dotPos = number.find('.');
        if (dotPos != std::string::npos) {
            int currentPrecision = 0;
            size_t p = dotPos + 1;
            while (p < number.length() && number[p] >= '0' && number[p] <= '9') {
                currentPrecision++;
                p++;
            }
            if (currentPrecision > maxPrecision) {
                maxPrecision = currentPrecision;
            }
        }


        double val = std::stod(number);


        if (size >= MAX_NUM_OF_NUM) {
            std::cerr << "Error: maximum number of numbers exceeded!" << std::endl;
            delete[] numbers;
            return 1;
        }

        numbers[size++] = val;
    }
    inFile.close();

    std::ofstream outFile(filename, std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Error: could not open file for writing!" << std::endl;
        delete[] numbers;
        return 1;
    }


    outFile << std::fixed << std::setprecision(maxPrecision);

    for (size_t i = 0; i < size; ++i) {
        outFile << std::abs(numbers[i]) << "\n";
    }

    outFile.close();
    

    delete[] numbers;

    std::cout << "File successfully rewritten! Maximum precision: " << maxPrecision << std::endl;

    return 0;
}


int main() {
    std::string filename = "numbers.txt";

    return ProcessNumbers(filename, 10);
}


