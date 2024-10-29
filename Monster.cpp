#include "Monster.h"
#include <iostream>
#include <sstream>

Monster::Monster() : name("Unknown"), description("Unknown") {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    std::cout << "Создан Monster по умолчанию\n";
}

Monster::Monster(const std::string& name, const std::string& description)
    : name(name), description(description) {
    skills = new std::string[skillsCapacity];
    skillsCount = 0;
    std::cout << "Создан Monster: " << name << "\n";
}

Monster::Monster(const Monster& other)
    : Hero(), name(other.name), description(other.description) {
    skillsCapacity = other.skillsCapacity;
    skills = new std::string[skillsCapacity];
    skillsCount = other.skillsCount;
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }
    std::cout << "Скопирован Monster: " << name << "\n";
}

Monster& Monster::operator=(const Monster& other) {
    if (this == &other) return *this;


    delete[] skills;


    name = other.name;
    description = other.description;
    skillsCapacity = other.skillsCapacity;
    skillsCount = other.skillsCount;


    skills = new std::string[skillsCapacity];
    for (int i = 0; i < skillsCount; ++i) {
        skills[i] = other.skills[i];
    }

    std::cout << "Присвоен монстр: " << name << "\n";
    return *this;
}

Monster::~Monster() {
    delete[] skills;
    skills = nullptr;
    std::cout << "Удален Monster: " << name << "\n";
}

void Monster::setName(const std::string& name) { this->name = name; }
std::string Monster::getName() const { return name; }

void Monster::setDescription(const std::string& description) { this->description = description; }
std::string Monster::getDescription() const { return description; }

void Monster::setSkills(const std::string& skillsStr) {
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

std::string* Monster::getSkills() const { return skills; }
int Monster::getSkillsCount() const { return skillsCount; }

void Monster::printInfo() const {
    std::cout << "Монстр: " << name << ", Описание: " << description << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        std::cout << skills[i] << " ";
    }
    std::cout << std::endl;
}

std::string Monster::serialize() const {
    std::string serializedSkills;
    for (int i = 0; i < skillsCount; ++i) {
        serializedSkills += skills[i] + " ";
    }
    return "Monster " + name + " " + description + " " + serializedSkills;
}

std::string Monster::getInfoForClipboard() const {
    std::ostringstream oss;
    oss << "Монстр: " << name << ", Описание: " << description << ", Навыки: ";
    for (int i = 0; i < skillsCount; ++i) {
        oss << skills[i] << " ";
    }
    return oss.str();
}
