#ifndef VILLAIN_H
#define VILLAIN_H

#include "Hero.h"
#include <string>

class Villain : public Hero {
private:
    std::string name;
    std::string weapon;
    std::string crime;
    std::string location;

public:
    Villain();
    Villain(const std::string& name, const std::string& weapon, const std::string& crime, const std::string& location, const std::string& skills);
    Villain(const Villain& other);
    Villain& operator=(const Villain& other);
    ~Villain() override;

    void setName(const std::string& name) override;
    std::string getName() const override;
    void setWeapon(const std::string& weapon);
    std::string getWeapon() const;

    void setCrime(const std::string& crime);
    std::string getCrime() const;
    void setLocation(const std::string& location);
    std::string getLocation() const;

    void setSkills(const std::string& skills) override;
    std::string* getSkills() const override;
    int getSkillsCount() const override;

    void printInfo() const override;
    std::string serialize() const override;
    std::string getInfoForClipboard() const override;
};

#endif // VILLAIN_H
