
#include "Add.h"
#include <iostream>
#include <cstring>

int Player::playerCount = 0;

Player::Player(const char* name, int health, int level)
    : name(new char[std::strlen(name ? name : "Unknown") + 1]),
    health(health < 0 ? 0 : health),
    level(level) {

    std::strcpy(this->name, name ? name : "Unknown");
    playerCount++;
}

Player::Player() : Player("Unknown", 100, 1) {}

Player::Player(const Player& other)
    : name(new char[std::strlen(other.name) + 1]),
    health(other.health),
    level(other.level) {

    std::strcpy(name, other.name);
    playerCount++;
}

Player::~Player() {
    delete[] name;
    playerCount--;
}

const char* Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLevel() const {
    return level;
}

void Player::setName(const char* name) {
    const char* newName = name ? name : "Unknown";

    char* temp = new char[std::strlen(newName) + 1];
    std::strcpy(temp, newName);

    delete[] this->name;
    this->name = temp;
}

void Player::setHealth(int health) {
    if (health >= 0) {
        this->health = health;
    }
}

void Player::takeDamage(int damage) {
    if (damage > 0) {
        health -= damage;

        if (health < 0) {
            health = 0;
        }
    }
}

void Player::heal(int amount) {
    if (amount > 0) {
        health += amount;

        if (health > 100) {
            health = 100;
        }
    }
}

void Player::levelUp() {
    level++;
}

void Player::printStats() const {
    std::cout << "\nPlayer: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Level: " << level << "\n";
}

int Player::getPlayerCount() {
    return playerCount;
}
