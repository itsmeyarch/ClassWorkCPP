
#include <iostream>
#include "Add.h"

int main() {
    Player player1("Warrior", 100, 5);
    Player player2;
    Player player3("Mage", 80, 3);

    std::cout << "===== INITIAL PLAYERS =====\n";

    player1.printStats();
    player2.printStats();
    player3.printStats();

    std::cout << "\nTotal players: "
        << Player::getPlayerCount() << "\n";

    std::cout << "\n===== PLAYER METHODS =====\n";

    player1.takeDamage(30);
    player1.printStats();

    player1.heal(20);
    player1.printStats();

    player1.levelUp();
    player1.printStats();

    std::cout << "\n===== SETTERS AND GETTERS =====\n";

    player2.setName("Knight");
    player2.setHealth(90);

    std::cout << "Name: " << player2.getName() << "\n";
    std::cout << "Health: " << player2.getHealth() << "\n";
    std::cout << "Level: " << player2.getLevel() << "\n";

    std::cout << "\n===== COPY CONSTRUCTOR =====\n";

    Player player4(player1);
    player4.printStats();

    std::cout << "\nTotal players: "
        << Player::getPlayerCount() << "\n";

    std::cout << "\n===== END OF PROGRAM =====\n";
}
