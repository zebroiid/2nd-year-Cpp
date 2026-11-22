//
// Created by markp on 22/11/2026.
//
#include <iostream>

void customStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

class Auto {
private:
    char brand[50];
    char model[50];
    char number[20];
    int ownerID;
    double repairCost;

public:

    Auto() : ownerID(0), repairCost(0.0) {
        brand[0] = '\0';
        model[0] = '\0';
        number[0] = '\0';
    }


    Auto(const char* b, const char* m, const char* n, int id) {
        customStrcpy(brand, b);
        customStrcpy(model, m);
        customStrcpy(number, n);
        ownerID = id;
        repairCost = 0.0;
    }

    void input() {
        std::cout << "Enter brand: ";
        std::cin >> brand;
        std::cout << "Enter model: ";
        std::cin >> model;
        std::cout << "Enter number: ";
        std::cin >> number;
        std::cout << "Enter owner ID: ";
        std::cin >> ownerID;
    }


    void print() const {
        std::cout << brand << " " << model << " / Num: " << number
                  << " / Owner: " << ownerID;
        if (repairCost > 0) {
            std::cout << " / Repair Cost: $" << repairCost;
        }

    }


    void setRepairCost(double cost) {
        repairCost = cost;
    }

    double getRepairCost() const {
        return repairCost;
    }


    bool operator<(const Auto& other) const {
        return this->repairCost < other.repairCost;
    }
};

template <typename T>
class CustomStack {
private:
    T* data;
    int topIndex;
    int capacity;

public:
    CustomStack(int cap = 10) : capacity(cap), topIndex(-1) {
        data = new T[capacity];
    }
    ~CustomStack() { delete[] data; }

    void push(const T& item) {
        if (topIndex < capacity - 1) {
            data[++topIndex] = item;
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }

    T top() const { return data[topIndex]; }
    bool isEmpty() const { return topIndex == -1; }


    void printState() const {
        std::cout << "Warehouse State:\n";
        if (isEmpty()) {
            std::cout << "  (Empty)\n";
            return;
        }
        for (int i = topIndex; i >= 0; --i) {
            std::cout << "  - ";
            data[i].print();
            std::cout << "\n";
        }
    }
};

template <typename T>
class CustomQueue {
private:
    T* data;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    CustomQueue(int cap = 10) : capacity(cap), frontIndex(0), rearIndex(-1), count(0) {
        data = new T[capacity];
    }
    ~CustomQueue() { delete[] data; }

    void push(const T& item) {
        if (count < capacity) {
            rearIndex = (rearIndex + 1) % capacity;
            data[rearIndex] = item;
            count++;
        }
    }

    void pop() {
        if (count > 0) {
            frontIndex = (frontIndex + 1) % capacity;
            count--;
        }
    }

    T front() const { return data[frontIndex]; }
    bool isEmpty() const { return count == 0; }
};


template <typename T>
class CustomPriorityQueue {
private:
    T* data;
    int count;
    int capacity;

public:
    CustomPriorityQueue(int cap = 10) : capacity(cap), count(0) {
        data = new T[capacity];
    }
    ~CustomPriorityQueue() { delete[] data; }


    void push(const T& item) {
        if (count < capacity) {
            int i = count - 1;

            while (i >= 0 && data[i] < item) {
                data[i + 1] = data[i];
                i--;
            }
            data[i + 1] = item;
            count++;
        }
    }

    void pop() {
        if (count > 0) count--;
    }

    T top() const { return data[count - 1]; }
    bool isEmpty() const { return count == 0; }
};


int main() {

    Auto car1("Toyota", "Camry", "AA1234", 101);
    Auto car2("Ford", "Focus", "BB5678", 102);
    Auto car3("Honda", "Civic", "CC9012", 103);


    std::cout << "task G: Stack\n";
    CustomStack<Auto> warehouse;

    std::cout << "[Adding to Warehouse]\n";
    warehouse.push(car1);
    warehouse.push(car2);
    warehouse.printState();

    std::cout << "\n[Removing from Warehouse]\n";
    warehouse.pop();
    warehouse.printState();
    std::cout << "\n";


    std::cout << "task D: Queue\n";
    CustomQueue<Auto> carWash;

    carWash.push(car1);
    carWash.push(car2);
    carWash.push(car3);

    while (!carWash.isEmpty()) {
        std::cout << "Washing car: ";
        carWash.front().print();
        std::cout << "\n";
        carWash.pop();
    }
    std::cout << "Car wash is now empty.\n\n";

    std::cout << "task E: Priority Queue\n";


    car1.setRepairCost(500.0);
    car2.setRepairCost(2500.0);
    car3.setRepairCost(1200.0);

    CustomPriorityQueue<Auto> repairShop;
    repairShop.push(car1);
    repairShop.push(car2);
    repairShop.push(car3);

    std::cout << "Processing repairs:\n";
    while (!repairShop.isEmpty()) {
        std::cout << "Repairing: ";
        repairShop.top().print();
        std::cout << "\n";
        repairShop.pop();
    }

    return 0;
}