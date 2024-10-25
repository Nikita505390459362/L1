#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>

class Hero {
protected:
    std::string name;
    std::string weaponType;
    std::string skills[5]; // Сделать выбор количества навыков меню
    int skillCount; // Количество текущих навыков

public:
    Hero(const std::string& name, const std::string& weaponType, const std::string skills[], int skillCount)
        : name(name), weaponType(weaponType), skillCount(skillCount) {
        for (int i = 0; i < skillCount && i < 5; ++i) {
            this->skills[i] = skills[i];
        }
    }

    virtual ~Hero() = default;

    virtual void printInfo() const = 0;
    virtual std::string serialize() const = 0;

    std::string getName() const { return name; }
    std::string getWeaponType() const { return weaponType; }


    void printSkills() const {
        for (int i = 0; i < skillCount; ++i) {
            std::cout << skills[i] << (i < skillCount - 1 ? ", " : "");
        }
    }
};

#endif // HERO_H
