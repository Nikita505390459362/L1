#ifndef MONSTER_H
#define MONSTER_H

#include "Hero.h"
#include <string>

class Monster : public Hero {
private:
    std::string name;
    std::string description;

public:
    Monster();
    Monster(const std::string& name, const std::string& description);
    Monster(const Monster& other);
    Monster& operator=(const Monster& other);
    ~Monster();

    void setName(const std::string& name) override;
    std::string getName() const override;

    void setDescription(const std::string& description);
    std::string getDescription() const;

    void setSkills(const std::string& skills) override;
    std::string* getSkills() const override;
    int getSkillsCount() const override;

    void printInfo() const override;
    std::string serialize() const override;
    std::string getInfoForClipboard() const override;
};

#endif // MONSTER_H
