#include "Keeper.h"
#include "PositiveHero.h"
#include "Villain.h"
#include "Monster.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void menu() {
    std::cout << "Меню:\n"
              << "1. Добавить героя\n"
              << "2. Удалить героя\n"
              << "3. Показать всех героев\n"
              << "4. Сохранить в файл\n"
              << "5. Загрузить из файла\n"
              << "6. Копировать героя\n"
              << "0. Выйти\n";
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    Keeper keeper;
    int choice;

    while (true) {
        menu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
                case 1: {
                    int heroType;
                    std::cout << "Выберите тип героя:\n1. Положительный герой\n2. Злодей\n3. Монстр\n";
                    std::cin >> heroType;
                    std::cin.ignore();

                    if (heroType == 1) {
                        std::string name, weapon, skills;
                        std::cout << "Введите имя: ";
                        std::getline(std::cin, name);
                        std::cout << "Введите оружие: ";
                        std::getline(std::cin, weapon);
                        std::cout << "Введите навыки (через пробел): ";
                        std::getline(std::cin, skills);
                        keeper.addObject(new PositiveHero(name, weapon, skills));
                    } else if (heroType == 2) {
                        std::string name, weapon, crime, location, skills;
                        std::cout << "Введите имя: ";
                        std::getline(std::cin, name);
                        std::cout << "Введите оружие: ";
                        std::getline(std::cin, weapon);
                        std::cout << "Введите преступление: ";
                        std::getline(std::cin, crime);
                        std::cout << "Введите место обитания: ";
                        std::getline(std::cin, location);
                        std::cout << "Введите навыки (через пробел): ";
                        std::getline(std::cin, skills);
                        keeper.addObject(new Villain(name, weapon, crime, location, skills));
                    } else if (heroType == 3) {
                        std::string name, description;
                        std::cout << "Введите имя монстра: ";
                        std::getline(std::cin, name);
                        std::cout << "Введите описание: ";
                        std::getline(std::cin, description);
                        keeper.addObject(new Monster(name, description));
                    } else {
                        std::cout << "Неверный выбор типа героя.\n";
                    }
                    break;
                }

                case 2: {
                    int index;
                    std::cout << "Введите индекс для удаления: ";
                    std::cin >> index;
                    keeper.removeObject(index);
                    break;
                }

                case 3:
                    keeper.printAll();
                    break;

                case 4:
                    keeper.saveToFile("heroes.txt");
                    std::cout << "Данные сохранены в файл.\n";
                    break;

                case 5:
                    keeper.loadFromFile("heroes.txt");
                    std::cout << "Данные загружены из файла.\n";
                    break;

                case 6: {
                    int sourceIndex, targetIndex;
                    std::cout << "Введите индекс героя для копирования: ";
                    std::cin >> sourceIndex;
                    std::cout << "Введите индекс героя для присвоения: ";
                    std::cin >> targetIndex;

                    Hero* sourceHero = keeper.getObject(sourceIndex);
                    Hero* targetHero = keeper.getObject(targetIndex);

                    if (sourceHero == nullptr || targetHero == nullptr) {
                        std::cout << "Один из индексов недействителен.\n";
                    } else if (typeid(*sourceHero) != typeid(*targetHero)) {
                        std::cout << "Типы героев не совпадают, копирование невозможно.\n";
                    } else {
                        if (auto sourcePosHero = dynamic_cast<PositiveHero*>(sourceHero)) {
                            auto targetPosHero = dynamic_cast<PositiveHero*>(targetHero);
                            *targetPosHero = *sourcePosHero;
                        } else if (auto sourceVillain = dynamic_cast<Villain*>(sourceHero)) {
                            auto targetVillain = dynamic_cast<Villain*>(targetHero);
                            *targetVillain = *sourceVillain;
                        } else if (auto sourceMonster = dynamic_cast<Monster*>(sourceHero)) {
                            auto targetMonster = dynamic_cast<Monster*>(targetHero);
                            *targetMonster = *sourceMonster;
                        } else {
                            std::cout << "Ошибка: Неизвестный тип героя.\n";
                        }
                        std::cout << "Герой скопирован успешно.\n";
                    }
                    break;
                }

                case 0:
                    exit(0);

                default:
                    std::cout << "Неверный выбор.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
}
