#include "Villain.h"
#include <iostream>
#include <sstream>

Villain::Villain() : name("Unknown"), weapon("None"), crime("Unknown"), location("Unknown") {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    std::cout << "Создан Villain по умолчанию\n";
}

Villain::Villain(const std::string& name, const std::string& weapon, const std::string& crime, const std::string& location, const std::string& skillsStr)
    : name(name), weapon(weapon), crime(crime), location(location) {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    setSkills(skillsStr);
    std::cout << "Создан Villain: " << name << "\n";
}

Villain::Villain(const Villain& other)
    : Hero(), name(other.name), weapon(other.weapon), crime(other.crime), location(other.location) {
    skillsCapacity = other.skillsCapacity;
    skills = new std::string[skillsCapacity];
    skillsCount = other.skillsCount;
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }
    std::cout << "Скопирован Villain: " << name << "\n";
}

Villain& Villain::operator=(const Villain& other) {
    if (this == &other) return *this;


    delete[] skills;


    name = other.name;
    weapon = other.weapon;
    crime = other.crime;
    location = other.location;
    skillsCapacity = other.skillsCapacity;
    skillsCount = other.skillsCount;


    skills = new std::string[skillsCapacity];
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }

    std::cout << "Assigned Villain: " << name << "\n";
    return *this;
}

Villain::~Villain() {
    delete[] skills;
    skills = nullptr;
    std::cout << "Удален Villain: " << name << "\n";
}

void Villain::setName(const std::string& name) { this->name = name; }
std::string Villain::getName() const { return name; }

void Villain::setWeapon(const std::string& weapon) { this->weapon = weapon; }
std::string Villain::getWeapon() const { return weapon; }

void Villain::setCrime(const std::string& crime) { this->crime = crime; }
std::string Villain::getCrime() const { return crime; }

void Villain::setLocation(const std::string& location) { this->location = location; }
std::string Villain::getLocation() const { return location; }

void Villain::setSkills(const std::string& skillsStr) {
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

std::string* Villain::getSkills() const { return skills; }
int Villain::getSkillsCount() const { return skillsCount; }

void Villain::printInfo() const {
    std::cout << "Злодей: " << name << ", Оружие: " << weapon << ", Преступление: " << crime << ", Место: " << location << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        std::cout << skills[i] << " ";
    }
    std::cout << std::endl;
}

std::string Villain::serialize() const {
    std::string serializedSkills;
    for (int i = 0; i < skillsCount; ++i) {
        serializedSkills += skills[i] + " ";
    }
    return "Villain " + name + " " + weapon + " " + crime + " " + location + " " + serializedSkills;
}

std::string Villain::getInfoForClipboard() const {
    std::ostringstream oss;
    oss << "Злодей: " << name << ", Оружие: " << weapon << ", Преступление: " << crime << ", Место: " << location << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        oss << skills[i] << " ";
    }
    return oss.str();
}
