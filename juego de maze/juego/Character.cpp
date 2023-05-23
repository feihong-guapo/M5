#include "Character.h"
#pragma once
#include <iostream>

//metodos
void Character::setPosition(int x, int y) {
    positionX = x;
    positionY = y;
}
//ataque de personaje
void Character::attackEnemy(Character& enemy) {
    int damage = attack;
    enemy.decreaseHealth(damage);
}

// la vida de personaje
void Character::decreaseHealth(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

// a ver si esta vivo el personaje
void Character::bool isAlive() const {
    return health > 0;
}