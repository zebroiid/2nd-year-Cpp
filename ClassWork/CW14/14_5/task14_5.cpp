#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


struct Student {
    std::string surname;
    int course;             
    std::string group;      
};


std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}



std::string findStudentWithWorstAverage(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return "";
    }

    std::string line;
    std::string worstSurname = "";
    double lowestAverage = 1e9;

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        Student student;
        std::string token;


        if (!std::getline(ss, student.surname, ',')) continue;
        student.surname = trim(student.surname);

        if (std::getline(ss, token, ',')) {
            student.course = std::stoi(trim(token));
        }

        if (std::getline(ss, token, ',')) {
            student.group = trim(token);
        }

        double sum = 0;
        int count = 0;
        while (std::getline(ss, token, ',')) {
            token = trim(token);
            if (!token.empty()) {
                sum += std::stoi(token);
                count++;
            }
        }

        if (count > 0) {
            double average = sum / count;

            if (average < lowestAverage) {
                lowestAverage = average;
                worstSurname = student.surname;
            }
        }
    }

    inFile.close();
    return worstSurname;
}

int main() {
    const std::string filename = "students.txt";

    std::string worstStudent = findStudentWithWorstAverage(filename);

    if (!worstStudent.empty()) {
        std::cout << "Student with the lowest average grade: " << worstStudent << std::endl;
    } else {
        std::cout << "Failed to find students or file is empty." << std::endl;
    }

    return 0;
}