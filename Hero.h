#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>

class Hero {
protected:
    std::string name;
    std::string weaponType;
    std::vector<std::string> skills;

public:
    Hero(const std::string& name, const std::string& weaponType, const std::vector<std::string>& skills)
        : name(name), weaponType(weaponType), skills(skills) {}

    virtual ~Hero() = default;

    virtual void printInfo() const = 0;

    std::string getName() const { return name; }
    std::string getWeaponType() const { return weaponType; }
    std::vector<std::string> getSkills() const { return skills; }
};

#endif // HERO_H

