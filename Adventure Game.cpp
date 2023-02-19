#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate a random number between min and max (inclusive)
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    string playerName, choice;
    int health = 100, gold = 0, level = 1, monstersDefeated = 0;

    cout << "Welcome to the adventure game!" << endl;
    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << "You are now " << playerName << ", an adventurer exploring a dangerous world." << endl;
    cout << "You start your adventure at level 1 with 100 health and 0 gold." << endl;

    while (health > 0) {
        // Generate a random event
        int event = random(1, 3);

        if (event == 1) {
            // Encounter a monster
            int monsterLevel = random(level - 1, level + 1);
            int monsterHealth = random(50, 100);
            int monsterDamage = random(5, 10);

            cout << "You encounter a level " << monsterLevel << " monster!" << endl;

            while (monsterHealth > 0 && health > 0) {
                cout << "You have " << health << " health and the monster has " << monsterHealth << " health." << endl;
                cout << "What do you want to do? (type 'attack' to attack, 'flee' to try and run away): ";
                getline(cin, choice);

                if (choice == "attack") {
                    int damage = random(5, 10);
                    monsterHealth -= damage;
                    cout << "You deal " << damage << " damage to the monster." << endl;

                    if (monsterHealth <= 0) {
                        cout << "You defeat the monster!" << endl;
                        gold += random(10, 20);
                        monstersDefeated++;
                        level = 1 + monstersDefeated / 3;
                        cout << "You gain " << (10 + level * 5) << " experience points and " << (10 + level * 5) << " gold." << endl;
                    }
                    else {
                        int monsterDamage = random(5, 10);
                        health -= monsterDamage;
                        cout << "The monster deals " << monsterDamage << " damage to you." << endl;

                        if (health <= 0) {
                            cout << "You have been defeated by the monster. Game over." << endl;
                            break;
                        }
                    }
                }
                else if (choice == "flee") {
                    int fleeChance = random(1, 3);
                    if (fleeChance == 1) {
                        cout << "You successfully flee from the monster." << endl;
                        break;
                    }
                    else {
                        int monsterDamage = random(5, 10);
                        health -= monsterDamage;
                        cout << "The monster attacks you as you try to run away, dealing " << monsterDamage << " damage." << endl;

                        if (health <= 0) {
                            cout << "You have been defeated by the monster. Game over." << endl;
                            break;
                        }
                    }
                }
                else {
                    cout << "Invalid command. Type 'attack' to attack, 'flee' to try and run away." << endl;
                }
        }
    }
    else if (event == 2) {
        // Find a treasure chest
        int goldAmount = random(10, 30);
        cout << "You find a treasure chest containing " << goldAmount << " gold!" << endl;
        gold += goldAmount;
    }
    else {
        // Find a healing potion
        int potionAmount = random(20, 40);
        cout << "You find a healing potion that restores " << potionAmount << " health!" << endl;
        health += potionAmount;
        if (health > 100) {
            health = 100;
        }
    }

    // Display status
    cout << "Current status: level " << level << ", " << health << " health, " << gold << " gold." << endl;
    cout << "You have defeated " << monstersDefeated << " monsters so far." << endl;

    // Ask if the player wants to continue
    cout << "Do you want to continue? (type 'yes' to continue, anything else to quit): ";
    getline(cin, choice);

    if (choice != "yes") {
        break;
    }
}

// Game over
cout << "Game over. Thanks for playing!" << endl;

return 0;
  }