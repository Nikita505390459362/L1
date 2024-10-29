#ifndef POSITIVEHERO_H
#define POSITIVEHERO_H

#include "Hero.h"
#include <string>

class PositiveHero : public Hero {
private:
    std::string name;
    std::string weapon;

public:
    PositiveHero();
    PositiveHero(const std::string& name, const std::string& weapon, const std::string& skills);
    PositiveHero(const PositiveHero& other);
    PositiveHero& operator=(const PositiveHero& other);
    ~PositiveHero();

    void setName(const std::string& name) override;
    std::string getName() const override;

    void setWeapon(const std::string& weapon);
    std::string getWeapon() const;

    void setSkills(const std::string& skills) override;
    std::string* getSkills() const override;
    int getSkillsCount() const override;

    void printInfo() const override;
    std::string serialize() const override;
    std::string getInfoForClipboard() const override;
};

#endif // POSITIVEHERO_H
