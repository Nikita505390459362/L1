#ifndef HERO_H
#define HERO_H

#include <string>

class Hero {
protected:
    std::string* skills;
    int skillsCount;
    int skillsCapacity;

    void expandSkills();

public:
    Hero();
    virtual ~Hero();

    virtual void setSkills(const std::string& skills) = 0;
    virtual std::string* getSkills() const = 0;
    virtual int getSkillsCount() const = 0;

    virtual void printInfo() const = 0;
    virtual std::string serialize() const = 0;
    virtual std::string getInfoForClipboard() const = 0;

    virtual void setName(const std::string& name) = 0;
    virtual std::string getName() const = 0;
};

#endif // HERO_H
