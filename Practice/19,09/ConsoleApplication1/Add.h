
#ifndef ADD_H
#define ADD_H

class Player {
private:
    char* name;
    int health;
    int level;

    static int playerCount;

public:
    Player(const char* name, int health, int level);
    Player();
    Player(const Player& other);
    ~Player();

    const char* getName() const;
    int getHealth() const;
    int getLevel() const;

    void setName(const char* name);
    void setHealth(int health);

    void takeDamage(int damage);
    void heal(int amount);
    void levelUp();

    void printStats() const;

    static int getPlayerCount();
};

#endif
