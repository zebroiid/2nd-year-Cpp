//
// Created by markp on 24/11/2026.
//

#ifndef INC_2ND_YEAR_CPP_OPERATINGSYSTEM_H
#define INC_2ND_YEAR_CPP_OPERATINGSYSTEM_H

#include <string>

class OperatingSystem {
private:
    std::string name;
    int year;
    std::string version;
    std::string rootPath;
    bool running;

    // Приватний конструктор, щоб превентувати установлення
    OperatingSystem();

public:

    OperatingSystem(const OperatingSystem&) = delete;// конструктор копіювання, превентує створення ще одної операційної сиситеми на основі існуючого
    OperatingSystem& operator=(const OperatingSystem&) = delete;// оператор присвоєння, не дає перезаписати обєкт іншим

    // гарантує існування тільки одного екземпляру класу
    static OperatingSystem& instance();

    // Геттери
    std::string getName() const;
    int getYear() const;
    std::string getVersion() const;
    std::string getRootPath() const;
    bool isRunning() const;

    // Сеттери
    bool setName(const std::string& newName);
    bool setYear(int newYear);
    bool setVersion(const std::string& newVersion);
    bool setRootPath(const std::string& newPath);


    bool start();
    bool stop();
    void printStatus() const;
};

#endif //INC_2ND_YEAR_CPP_OPERATINGSYSTEM_H
