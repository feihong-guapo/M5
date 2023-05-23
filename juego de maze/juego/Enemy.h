#include "Character.h"
#pragma once
#include <iostream>
class Enemy : public Character {
public:
    Enemy(const string& name, int health, int attack) : Character(name, health, attack) {}

    // EL ENEMIGO 
    void move() {
       // EL ENEMIGO NO SE MUEVE
    }
};




class FinalEnemy : public Character {
private:
    int superAttackDamage;

public:
    FinalEnemy(const string& name, int health, int attack, int superAttackDamage) : Character(name, health, attack), superAttackDamage(superAttackDamage) {}

    // ATAQUE DE ENEMIGO FINAL
    void superAttack(Character& player) {
        int damage = superAttackDamage;
        player.decreaseHealth(damage);
    }
};


