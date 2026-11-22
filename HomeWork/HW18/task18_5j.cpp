//
// Created by markp on 22/11/2026.
//
#include <iostream>


template <typename T>
class Array {
private:
    T* data;
    int size;

public:

    Array(int s) {
        size = s;
        data = new T[size];
    }


    ~Array() {
        delete[] data;
    }


    void setElement(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }


    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }


    void shellSort() {
        shellSortStatic(data, size);
    }


    static void shellSortStatic(T* arr, int n) {

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                T temp = arr[i];
                int j;

                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
};

int main() {

    std::cout << "Testing Instance Method\n";

    Array<int> myArray(5);
    myArray.setElement(0, 45);
    myArray.setElement(1, 12);
    myArray.setElement(2, 85);
    myArray.setElement(3, 32);
    myArray.setElement(4, 8);

    std::cout << "Original array inside class: ";
    myArray.print();

    myArray.shellSort();

    std::cout << "Sorted array inside class:   ";
    myArray.print();
    std::cout << "\n";

    std::cout << "Testing Static Method\n";


    double staticArr[] = {9.8, 2.3, 4.5, 1.1, 7.6, 3.4};
    int staticSize = 6;

    std::cout << "Original external array:     ";
    for (int i = 0; i < staticSize; ++i) {
        std::cout << staticArr[i] << " ";
    }
    std::cout << "\n";

    Array<double>::shellSortStatic(staticArr, staticSize);

    std::cout << "Sorted external array:       ";
    for (int i = 0; i < staticSize; ++i) {
        std::cout << staticArr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}