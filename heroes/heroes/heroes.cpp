#include <iostream>
#include <string>

using namespace std;


class GameObject {
public:
    virtual ~GameObject() = default;
};


class Stats {
public:
    int health;
    int mana;

    Stats(int health = 100, int mana = 50)
        : health(health), mana(mana) {
    }
};


class SoulMark {
public:
    string mark;
    SoulMark(const string& mark = "Claw Tattoo") : mark(mark) {}
};


class Guild {
    string name;

public:
    Guild(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};


class Weapon {
protected:
    string name;
    int damage;

public:
    Weapon(const string& name, int damage)
        : name(name), damage(damage) {
    }

    virtual void attack() {
        cout << "Attacking with " << name
            << " for " << damage << " damage!\n";
    }

    string getName() const {
        return name;
    }

    virtual ~Weapon() {}
};


class Sword : public Weapon {
public:
    Sword(const string& name, int damage)
        : Weapon(name, damage) {
    }

    void attack() override {
        cout << "You attacked with " << name
            << " causing " << damage << " damage!\n";
    }
};

class Hero {
    Guild* guild;
    Weapon* weapon;

public:
    Hero() : guild(nullptr), weapon(nullptr) {}

    void joinGuild(Guild* g) {
        guild = g;
        cout << "You joined the guild: "
            << guild->getName() << "\n";
    }

    void equipWeapon(Weapon* w) {
        weapon = w;
        cout << "You equipped: "
            << weapon->getName() << "\n";
    }

    void attack() {
        if (weapon)
            weapon->attack();
        else
            cout << "No weapon equipped!\n";
    }
};


// Main

int main() {
    // Guilds
    Guild healingGuild("Healing Guild");
    Guild combatGuild("Combat Guild");
    Guild merchantGuild("Merchant Guild");

    Hero hero;

    // Guild selection menu
    int choice;
    cout << "Choose a guild:\n";
    cout << "1. Healing\n";
    cout << "2. Combat\n";
    cout << "3. Merchant\n";
    cin >> choice;

    switch (choice) {
    case 1: hero.joinGuild(&healingGuild); break;
    case 2: hero.joinGuild(&combatGuild); break;
    case 3: hero.joinGuild(&merchantGuild); break;
    default:
        cout << "Invalid option.\n";
    }

    // Weapon
    Sword sword("Master Sword", 25);
    hero.equipWeapon(&sword);

    // Attack
    hero.attack();

    return 0;
}