#include "Keeper.h"
#include <fstream>


Keeper::Keeper() : size(0), capacity(2) {
    objects = new Hero*[capacity];
}


Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;
}


void Keeper::resize() {
    capacity *= 2;
    Hero** newObjects = new Hero*[capacity];
    for (int i = 0; i < size; ++i) {
        newObjects[i] = objects[i];
    }
    delete[] objects;
    objects = newObjects;
}


void Keeper::addObject(Hero* obj) {
    if (size == capacity) {
        resize();
    }
    objects[size++] = obj;
}


void Keeper::removeObject(int index) {
    if (index >= 0 && index < size) {
        delete objects[index];
        for (int i = index; i < size - 1; ++i) {
            objects[i] = objects[i + 1];
        }
        --size;
    }
}


void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (int i = 0; i < size; ++i) {
        outFile << objects[i]->serialize() << std::endl;
    }
}


void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string line;
    while (std::getline(inFile, line)) {
    }
}

void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        objects[i]->printInfo();
    }
}
