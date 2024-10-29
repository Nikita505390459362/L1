#include "Hero.h"
#include <iostream>

Hero::Hero() : skills(nullptr), skillsCount(0), skillsCapacity(2) {
    skills = new std::string[skillsCapacity];
}

Hero::~Hero() {
    delete[] skills;
}

void Hero::expandSkills() {
    skillsCapacity *= 2;
    std::string* newSkills = new std::string[skillsCapacity];


    for (int i = 0; i < skillsCount; ++i) {
        newSkills[i] = skills[i];
    }


    delete[] skills;
    skills = newSkills;
}
