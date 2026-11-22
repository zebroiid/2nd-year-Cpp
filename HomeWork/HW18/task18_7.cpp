//
// Created by markp on 22/11/2026.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>


template <typename T>
class CustomString {
private:
    T* data;
    int size;
    int capacity;
    T separator;


    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    CustomString(T sep) : size(0), capacity(10), separator(sep) {
        data = new T[capacity];
    }

    ~CustomString() {
        delete[] data;
    }


    CustomString(const CustomString& other) : size(other.size), capacity(other.capacity), separator(other.separator) {
        data = new T[capacity];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }


    void addSymbol(T symbol) {
        if (size >= capacity) resize(capacity * 2);
        data[size++] = symbol;
    }


    void clear() {
        size = 0;
    }


    friend std::ostream& operator<<(std::ostream& os, const CustomString& cs) {
        for (int i = 0; i < cs.size; ++i) {
            os << cs.data[i];
            if (i < cs.size - 1) os << cs.separator;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, CustomString& cs) {
        cs.clear();
        T val;

        while (is >> val) {
            cs.addSymbol(val);
        }
        return is;
    }


    void setSeparator(T newSep) {
        separator = newSep;
    }

    T getSeparator() const {
        return separator;
    }


    CustomString operator+(const CustomString& other) const {
        CustomString result(this->separator);
        for (int i = 0; i < this->size; ++i) result.addSymbol(this->data[i]);
        for (int i = 0; i < other.size; ++i) result.addSymbol(other.data[i]);
        return result;
    }


    int getLength() const {
        return size;
    }

    std::string mergeToString() const {
        std::ostringstream oss;
        for (int i = 0; i < size; ++i) {
            oss << data[i];
            if (i < size - 1) oss << separator;
        }
        return oss.str();
    }


    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Error: Index out of bounds!");
        }
        return data[index];
    }

    void removeSymbol(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Error: Cannot remove, index out of bounds!");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
};


template <>
class CustomString<char> {
private:
    std::string data;

public:
    CustomString(char /*sep*/ = '\0') {}

    void addSymbol(char c) { data += c; }
    void clear() { data.clear(); }
    void setSeparator(char /*newSep*/) {}
    int getLength() const { return data.length(); }

    std::string mergeToString() const { return data; }

    CustomString operator+(const CustomString& other) const {
        CustomString result;
        result.data = this->data + other.data;
        return result;
    }

    char& operator[](int index) {
        if (index < 0 || index >= data.length()) {
            throw std::out_of_range("Error: Char index out of bounds!");
        }
        return data[index];
    }

    void removeSymbol(int index) {
        if (index < 0 || index >= data.length()) {
            throw std::out_of_range("Error: Cannot remove, char index out of bounds!");
        }
        data.erase(index, 1);
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomString& cs) {
        os << cs.data;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, CustomString& cs) {
        is >> cs.data;
        return is;
    }
};

int main() {
    try {
        std::cout << "Generic Template (Int) Testing\n";

        // Create custom string for integers, separated by zero
        CustomString<int> intStr(0);
        intStr.addSymbol(15);
        intStr.addSymbol(42);
        intStr.addSymbol(88);

        std::cout << "Original intStr: " << intStr << "\n";

        intStr.setSeparator(999);
        std::cout << "After changing separator to 999: " << intStr << "\n";

        std::cout << "Length: " << intStr.getLength() << "\n";

        intStr.removeSymbol(1); // Remove '42'
        std::cout << "After removing index 1: " << intStr << "\n";

        std::string mergedStr = intStr.mergeToString();
        std::cout << "Merged to std::string: " << mergedStr << "\n\n";

        std::cout << "Char Specialization Testing\n";
        CustomString<char> charStr;
        charStr.addSymbol('H');
        charStr.addSymbol('e');
        charStr.addSymbol('l');
        charStr.addSymbol('l');
        charStr.addSymbol('o');

        std::cout << "Char string: " << charStr << "\n";
        charStr.removeSymbol(4); // Remove 'o'
        std::cout << "After removal: " << charStr << "\n\n";

        std::cout << "Error Handling Testing\n";
        std::cout << "Attempting to access out of bounds: ";
        std::cout << charStr[10] << "\n";

    } catch (const std::exception& e) {

        std::cerr << "\nException caught: " << e.what() << "\n";
    }

    std::cout << "\nFile I/O Testing\n";
    try {
        CustomString<std::string> fileStr("-");
        fileStr.addSymbol("apple");
        fileStr.addSymbol("banana");


        std::ofstream outFile("test.txt");
        if (!outFile) throw std::runtime_error("Cannot open file for writing!");
        outFile << fileStr;
        outFile.close();
        std::cout << "Successfully wrote to test.txt\n";

    } catch (const std::exception& e) {
        std::cerr << "File Error: " << e.what() << "\n";
    }

    return 0;
}