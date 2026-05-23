#include <iostream>
#include <string>

using namespace std;

/* =======================
   Base class
   ======================= */
class GameObject {
public:
    virtual ~GameObject() = default;
};

/* =======================
   Composition classes
   ======================= */
class Stats {
public:
    int health;
    int mana;

    Stats(int health = 100, int mana = 50)
        : health(health), mana(mana) {}
};

class SoulMark {
public:
    string mark;
    SoulMark(const string& mark = "Claw Tattoo") : mark(mark) {}
};

/* =======================
   Aggregation: Guild
   ======================= */
class Guild {
    string name;

public:
    Guild(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};

/* =======================
   Weapon hierarchy
   ======================= */
class Weapon {
protected:
    string name;
    int damage;

public:
    Weapon(const string& name, int damage)
        : name(name), damage(damage) {}

    virtual void attack() {
        cout << "Attacking with " << name
             << " for " << damage << " damage!\n";
    }

    virtual ~Weapon() {}
};

class Sword : public Weapon {
    int sharpness;   // ✅ added

public:
    Sword(const string& name, int damage, int sharpness)
        : Weapon(name, damage), sharpness(sharpness) {}

    void attack() override {
        cout << "You attacked with " << name
             << " causing " << damage + sharpness
             << " damage!\n";
    }
};

/* =======================
   Dependency: Potion
   ======================= */
class Potion {
public:
    int healAmount;

    Potion(int healAmount) : healAmount(healAmount) {}
};

/* =======================
   Hero
   ======================= */
class Hero : public GameObject {   // ✅ now inherits
    Stats stats;                   // ✅ composition
    SoulMark soulMark;             // ✅ composition

    Guild* guild;                  // aggregation
    Weapon* weapon;                // aggregation

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

    void usePotion(Potion* p) {    // ✅ dependency
        stats.health += p->healAmount;
        cout << "Potion used. Health is now "
             << stats.health << "\n";
    }

    void attack() {
        if (weapon)
            weapon->attack();
        else
            cout << "No weapon equipped!\n";
    }

    ~Hero() {
        cout << "Hero destroyed. Stats and SoulMark destroyed too.\n";
    }
};

/* =======================
   Main
   ======================= */
int main() {
    // Guilds
    Guild healingGuild("Healing Guild");
    Guild combatGuild("Combat Guild");
    Guild merchantGuild("Merchant Guild");

    Hero* hero = new Hero();   // ✅ dynamic allocation

    // Guild selection menu
    int choice;
    cout << "Choose a guild:\n";
    cout << "1. Healing\n";
    cout << "2. Combat\n";
    cout << "3. Merchant\n";
    cin >> choice;

    switch (choice) {
    case 1: hero->joinGuild(&healingGuild); break;
    case 2: hero->joinGuild(&combatGuild); break;
    case 3: hero->joinGuild(&merchantGuild); break;
    default:
        cout << "Invalid option.\n";
    }

    // Weapon
    Sword sword("Master Sword", 25, 10);
    hero->equipWeapon(&sword);

    // Potion
    Potion potion(20);
    hero->usePotion(&potion);

    // Attack
    hero->attack();

    // Delete Hero
    delete hero;

    // Prove Guild still exists
    cout << "Guild still exists: "
         << combatGuild.getName() << "\n";

    return 0;
}
