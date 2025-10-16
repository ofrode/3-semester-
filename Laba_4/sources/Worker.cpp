#include "../headers/Worker.h"

Worker::Worker(const std::string& name) : name(name) {}

void Worker::setName(const std::string& newName) {
    name = newName;
}

std::string Worker::getName() const {
    return name;
}

void Worker::inputData() {
    std::cout << "Введите имя работника: ";
    std::getline(std::cin >> std::ws, name);
}

void Worker::printInfo() const {
    std::cout << "Имя: " << name << std::endl;
}