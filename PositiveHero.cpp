#include "PositiveHero.h"
#include <iostream>
#include <sstream>

PositiveHero::PositiveHero() : Hero(), name("Unknown"), weapon("None") {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    std::cout << "Создан PositiveHero по умолчанию\n";
}

PositiveHero::PositiveHero(const std::string& name, const std::string& weapon, const std::string& skillsStr)
    : Hero(), name(name), weapon(weapon) {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    setSkills(skillsStr);
    std::cout << "Создан PositiveHero: " << name << "\n";
}

PositiveHero::PositiveHero(const PositiveHero& other)
    : Hero(), name(other.name), weapon(other.weapon) {
    skillsCapacity = other.skillsCapacity;
    skills = new std::string[skillsCapacity];
    skillsCount = other.skillsCount;
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }
    std::cout << "Скопирован PositiveHero: " << name << "\n";
}

PositiveHero::~PositiveHero() {
    delete[] skills;
    skills = nullptr;
    std::cout << "Удален PositiveHero: " << name << "\n";
}

void PositiveHero::setName(const std::string& name) { this->name = name; }
std::string PositiveHero::getName() const { return name; }

void PositiveHero::setWeapon(const std::string& weapon) { this->weapon = weapon; }
std::string PositiveHero::getWeapon() const { return weapon; }

void PositiveHero::setSkills(const std::string& skillsStr) {
    skillsCount = 0;
    std::istringstream iss(skillsStr);
    std::string skill;
    while (iss >> skill) {
        if (skillsCount == skillsCapacity) {
            expandSkills();
        }
        skills[skillsCount++] = skill;
    }
}

std::string* PositiveHero::getSkills() const { return skills; }
int PositiveHero::getSkillsCount() const { return skillsCount; }

void PositiveHero::printInfo() const {
    std::cout << "Герой: " << name << ", Оружие: " << weapon << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        std::cout << skills[i] << " ";
    }
    std::cout << std::endl;
}

std::string PositiveHero::serialize() const {
    std::string serializedSkills;
    for (int i = 0; i < skillsCount; ++i) {
        serializedSkills += skills[i] + " ";
    }
    return "PositiveHero " + name + " " + weapon + " " + serializedSkills;
}

std::string PositiveHero::getInfoForClipboard() const {
    std::ostringstream oss;
    oss << "Герой: " << name << ", Оружие: " << weapon << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        oss << skills[i] << " ";
    }
    return oss.str();
}


PositiveHero& PositiveHero::operator=(const PositiveHero& other) {
    if (this == &other) return *this;


    delete[] skills;


    name = other.name;
    weapon = other.weapon;
    skillsCapacity = other.skillsCapacity;
    skillsCount = other.skillsCount;


    skills = new std::string[skillsCapacity];
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }

    return *this;
}