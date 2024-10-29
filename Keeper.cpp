#include "Keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() : size(0), capacity(2) {
    objects = new Hero*[capacity];
    for (int i = 0; i < capacity; ++i) {
        objects[i] = nullptr;
    }
}

Keeper::~Keeper() {
    std::cout << "Вызван деструктор Keeper\n";
    for (int i = 0; i < size; ++i) {
        if (objects[i] != nullptr) {
            std::cout << "Удаляем объект по индексу " << i << "\n";
            delete objects[i];
            objects[i] = nullptr;
        }
    }
    delete[] objects;
    objects = nullptr;
}

void Keeper::resize() {
    capacity *= 2;
    Hero** newObjects = new Hero*[capacity];
    for (int i = 0; i < capacity; ++i) {
        newObjects[i] = nullptr;
    }
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
    std::cout << "Добавлен объект: ";
    obj->printInfo();
}

void Keeper::removeObject(int index) {
    if (index >= 0 && index < size) {
        delete objects[index];
        objects[index] = nullptr;

        for (int i = index; i < size - 1; ++i) {
            objects[i] = objects[i + 1];
        }
        objects[size - 1] = nullptr;
        --size;
    } else {
        std::cerr << "Ошибка: Неверный индекс для удаления." << std::endl;
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (objects[i] != nullptr) {
            outFile << objects[i]->serialize() << std::endl;
        }
    }
    outFile.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Ошибка открытия файла.");
    }

    for (int i = 0; i < size; ++i) {
        if (objects[i] != nullptr) {
            delete objects[i];
            objects[i] = nullptr;
        }
    }
    size = 0;

    std::string type, name, weapon, crime, location, description, skills;
    while (inFile >> type) {
        if (type == "PositiveHero") {
            inFile >> name >> weapon >> skills;
            addObject(new PositiveHero(name, weapon, skills));
        } else if (type == "Villain") {
            inFile >> name >> weapon >> crime >> location >> skills;
            addObject(new Villain(name, weapon, crime, location, skills));
        } else if (type == "Monster") {
            inFile >> name >> description;
            addObject(new Monster(name, description));
        }
    }
    inFile.close();
}

void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        if (objects[i] != nullptr) {
            objects[i]->printInfo();
        }
    }
}

int Keeper::getSize() const {
    return size;
}

Hero* Keeper::getObject(int index) const {
    if (index >= 0 && index < size) {
        return objects[index];
    }
    return nullptr;
}


void Keeper::copyObject(int srcIndex, int destIndex) {
    if (srcIndex < 0 || srcIndex >= size || destIndex < 0 || destIndex >= size) {
        std::cerr << "Ошибка: Неверные индексы для копирования." << std::endl;
        return;
    }

    if (objects[srcIndex] == nullptr || objects[destIndex] == nullptr) {
        std::cerr << "Ошибка: Один из указателей пустой." << std::endl;
        return;
    }


    if (auto src = dynamic_cast<PositiveHero*>(objects[srcIndex])) {
        if (auto dest = dynamic_cast<PositiveHero*>(objects[destIndex])) {
            *dest = *src;
        } else {
            std::cerr << "Ошибка: Несовпадающие типы при копировании PositiveHero." << std::endl;
        }
    } else if (auto src = dynamic_cast<Villain*>(objects[srcIndex])) {
        if (auto dest = dynamic_cast<Villain*>(objects[destIndex])) {
            *dest = *src;
        } else {
            std::cerr << "Ошибка: Несовпадающие типы при копировании Villain." << std::endl;
        }
    } else if (auto src = dynamic_cast<Monster*>(objects[srcIndex])) {
        if (auto dest = dynamic_cast<Monster*>(objects[destIndex])) {
            *dest = *src;
        } else {
            std::cerr << "Ошибка: Несовпадающие типы при копировании Monster." << std::endl;
        }
    } else {
        std::cerr << "Ошибка: Неизвестный тип объекта для копирования." << std::endl;
    }
}
