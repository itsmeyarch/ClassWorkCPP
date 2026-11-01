#include <iostream>
#include <vector>
#include <memory>
#include <Windows.h>

class IDamageable {
public:
    virtual void ReceiveDamage(int amount) = 0;
};

class Enemy : public IDamageable { // абстрактний клас
protected:
    int damage;
    int health;
    std::string name;
public:
    Enemy(int damage, int health, std::string name) : damage(damage), health(health), name(name) {}

    std::string getName() {
        return name;
    }
    int getDamage() {
        return damage;
    }
    int getHealth() {
        return health;
    }

    void ReceiveDamage(int amount) {
        if (health < 0) {
            return;
        }

        health -= amount;
        if (health > 0) {
            std::cout << name << " received damage. New health: " << health << '\n';
        }
        else {
            std::cout << name << " dies." << '\n';
        }
    }

    virtual void Attack(Enemy& target) const = 0; // чисто віртуальний метод
};

class Shooter : public Enemy {
private:
    std::string gun;
public:
    Shooter(int damage, int health, std::string name, std::string gun) : Enemy(damage, health, name), gun(gun) {}

    virtual void Attack(Enemy& target) const {
        std::cout << "Shooter " << name <<
            " shoots " << target.getName() << " with gun " << gun << '\n';
        target.ReceiveDamage(this->damage);
    }
};

class Bomber : public Enemy {
private:
    float radius;
public:
    Bomber(int damage, int health, std::string name, float radius) : Enemy(damage, health, name), radius(radius) {}

    virtual void Attack(Enemy& target) const {
        std::cout << "Bomber " << name << " throws bomb into " << target.getName() << '\n';
        target.ReceiveDamage(damage);
    }
};

class Swordman : public Enemy {
private:
    int distance;
public:
    Swordman(int damage, int health, std::string name, int distance) : Enemy(damage, health, name), distance(distance) {}

    virtual void Attack(Enemy& target) const {
        std::cout << "Swordman " << name << " strikes "
            << target.getName() << " with sowrd in distance " << distance << '\n';

        target.ReceiveDamage(damage);
    }
};

class Door :public IDamageable {
private:
    int strikeCounter = 0;
public:
    Door() {}

    void ReceiveDamage(int amount) {
        if (strikeCounter >= 2) {
            return;
        }

        strikeCounter++;
        if (strikeCounter >= 2) {
            std::cout << "Doors were smashed!\n";
        }
    }


};

class Spawner {
private:
    std::vector<Enemy*> enemies;
public:
    ~Spawner() {
        if (enemies.size() > 0) {
            for (int i = 0; i < enemies.size(); i++) {
                delete enemies[i];
            }
        }
    }

    Enemy* SpawnEnemy() {
        Enemy* enemy = nullptr;

        switch (rand() % 3) {
        case 0: enemy = new Shooter(40, 15, "Shooter", "Shotgun");
            break;
        case 1: enemy = new Bomber(60, 10, "Bomber", 45.5);
            break;
        case 2: enemy = new Swordman(25, 5, "Swordman", 2);
            break;
        }

        enemies.push_back(enemy);
        return enemy;
    }
};

int main()
{
    Bomber bomber(20, 100, "Bobmer", 20.5);
    Shooter shooter(10, 150, "Shooter", "Rifle");

    Door door(5);
    shooter.Attack(door);

    //while (shooter.getHealth() > 0 || bomber.getHealth() > 0)
    //{
    //    shooter.Attack(bomber);
    //    Sleep(1000);
    //    bomber.Attack(shooter);
    //    Sleep(1000);
    //}

    //Enemy enemy = Enemy(0, 0, "Abstract enemy");

    //enemy.Attack();

    //Spawner spawner;

    //const int MAX_ENEMIES = 5;
    //Enemy* enemies[MAX_ENEMIES];

    //int enemyCount = 0;
    //while (enemyCount < MAX_ENEMIES) {
    //    enemies[enemyCount++] = spawner.SpawnEnemy();
    //}

    //for (int i = 0; i < MAX_ENEMIES; i++) {
    //    enemies[i]->Attack();
    //    std::cout << '\n';
    //}
}