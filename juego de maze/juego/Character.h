#pragma once
#include <iostream>
using namespace std;
class Character
{
protected:
    std::string name;
    int health;
    int attack;
    int positionX;
    int positionY;
public :
    //construtor
    Character(const string&name, int health, int attack) : name(name), health(health), attack(attack) {}
    // getter
    int getHealth() const {
        return health;
    }
    int getAttack() const {
        return attack;
    }
    void getPosition(int& x, int& y) const {
        x = positionX;
        y = positionY;
    }



    //setter
   void setPosition(int x, int y) {
    }

   void attackEnemy(Character& enemy) {
    }

    
    void decreaseHealth(int damage) {
    }
};

