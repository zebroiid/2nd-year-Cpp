#include "OperatingSystem.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>



OperatingSystem::OperatingSystem()
    : name("Unknown"), year(2000), version("1.0"), rootPath("/"), running(false) {} // дефолтний конструктор

OperatingSystem& OperatingSystem::instance() {
    static OperatingSystem singleInstance;
    return singleInstance;
}

std::string OperatingSystem::getName() const {
    return name;
}

int OperatingSystem::getYear() const {
    return year;
}

std::string OperatingSystem::getVersion() const {
    return version;
}

std::string OperatingSystem::getRootPath() const {
    return rootPath;
}

bool OperatingSystem::isRunning() const {
    return running;
}

bool OperatingSystem::setName(const std::string& newName) {
    if (running || newName.empty()) {
        return false;
    }
    name = newName;
    return true;
}

bool OperatingSystem::setYear(int newYear) {
    if (running || newYear < 1970 || newYear > 2100) {
        return false;
    }
    year = newYear;
    return true;
}

bool OperatingSystem::setVersion(const std::string& newVersion) {
    if (running || newVersion.empty()) {
        return false;
    }
    version = newVersion;
    return true;
}

bool OperatingSystem::setRootPath(const std::string& newPath) {
    // Reject empty paths or empty quotes ""
    if (running || newPath.empty() || newPath == "\"\"") {
        return false;
    }
    rootPath = newPath;
    return true;
}

bool OperatingSystem::start() {
    if (running) {
        return false;
    }
    running = true;
    return true;
}

bool OperatingSystem::stop() {
    if (!running) {
        return false;
    }
    running = false;
    return true;
}

void OperatingSystem::printStatus() const {
    std::cout << "OK | Name: " << name << ", Year: " << year << ", Version: " << version << ", Path: " << rootPath << ", State: " << (running ? "ON" : "OFF") << '\n';
}



int main() {
    OperatingSystem& os1 = OperatingSystem::instance();// перевірка чи є синглетоном
    OperatingSystem& os2 = OperatingSystem::instance();

    if (&os1 != &os2) {
        std::cout << "ERROR: Singleton instances do not match\n";
        return 1;
    }

    std::string initName;
    int initYear;
    std::string initVersion;
    std::string initPath;


    std::cout << "Enter initial OS parameters (name year version path): ";
    if (!(std::cin >> initName >> initYear >> initVersion >> initPath)) {
        return 0;
    }


    os1.setName(initName);
    os1.setYear(initYear);
    os1.setVersion(initVersion);
    os1.setRootPath(initPath);


    std::cout << "Enter number of commands: ";
    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    // приберає \n пред використанням std::getline
    std::string dummy;
    std::getline(std::cin, dummy);

    std::cout << "\nAvailable commands: SET_NAME, SET_YEAR, SET_VERSION, SET_PATH, START, STOP, STATUS\n";

    std::string line;


    for (int i = 0; i < n; ++i) {
        std::cout << "Command " << (i + 1) << "/" << n << ": ";
        if (!std::getline(std::cin, line)) {
            break;
        }

        // сплітання рядка на команду і аргумент
        std::istringstream iss(line);
        std::string cmd;
        std::string arg;

        iss >> cmd;
        std::getline(iss >> std::ws, arg);

        //видалення зайвих пробільних символів у кінці рядка
        size_t endPos = arg.find_last_not_of(" \t\r\n"); //Перевіряє, чи знайшовся в рядку хоча б один потрібний символ. константа std::string::npos означає позицію не знайдено
        if (endPos != std::string::npos) {
            arg.erase(endPos + 1);
        } else {
            arg.clear();// порожній або одні табуляції
        }

        if (cmd == "SET_NAME") {
            std::cout << (os2.setName(arg) ? "OK" : "ERROR") << '\n';
        } else if (cmd == "SET_YEAR") {
            try {
                size_t parsedChars = 0;
                int y = std::stoi(arg, &parsedChars);
                if (parsedChars == arg.size() && os2.setYear(y)) {
                    std::cout << "OK\n";
                } else {
                    std::cout << "ERROR\n";
                }
            } catch (const std::exception&) {
                std::cout << "ERROR\n";
            }
        } else if (cmd == "SET_VERSION") {
            std::cout << (os2.setVersion(arg) ? "OK" : "ERROR") << '\n';
        } else if (cmd == "SET_PATH") {
            std::cout << (os2.setRootPath(arg) ? "OK" : "ERROR") << '\n';
        } else if (cmd == "START") {
            std::cout << (os2.start() ? "OK" : "ERROR") << '\n';
        } else if (cmd == "STOP") {
            std::cout << (os2.stop() ? "OK" : "ERROR") << '\n';
        } else if (cmd == "STATUS") {
            os2.printStatus();
        } else {
            std::cout << "ERROR\n";
        }
    }

    return 0;
}

//Linux 2023 6.5 /root
// 5
