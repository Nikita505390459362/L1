#ifndef KEEPER_H
#define KEEPER_H

#include "Hero.h"
#include <string>

class Keeper {
private:
    Hero** objects;
    int size;
    int capacity;

    void resize();

public:
    Keeper();
    ~Keeper();

    void addObject(Hero* obj);
    void removeObject(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void printAll() const;
};

#endif // KEEPER_H
