#include "pokemon_vectors/declarations/pokedex.hpp"


// Constructors & Destructor
//// Constructors
Pokemon::Pokemon(int id, string name, int evolution, int maxHealthPoints, int attackPoints, int defensePoints) {
    this->id = id;
    this->name = name;
    this->evolution = evolution;
    this->maxHealthPoints = maxHealthPoints;
    this->currentHealthPoints = maxHealthPoints;
    this->attackPoints = attackPoints;
    this->defensePoints = defensePoints;
}

Pokemon::Pokemon(const Pokemon &pkmn) : id(pkmn.id), name(pkmn.name), evolution(pkmn.evolution), maxHealthPoints(pkmn.maxHealthPoints), currentHealthPoints(pkmn.currentHealthPoints), attackPoints(pkmn.attackPoints), defensePoints(pkmn.defensePoints) {
}

Pokemon::Pokemon(int id) {
    Pokedex* pokedex = Pokedex::getInstance();
    Pokemon pkmn = *pokedex->getPokemon(id);
    *this = pkmn;   
}

Pokemon::~Pokemon() {
    std::cout << "Pokemon " << name << " destroyed." << std::endl;
    // No need to delete this; it will be automatically managed.
}
// Getters and Setters
//// Getters
int Pokemon::Id() const { return id; }

string Pokemon::Name() const { return name; }

int Pokemon::Evolution() const { return evolution; }

int Pokemon::MaxHealthPoints() const { return maxHealthPoints; }

int Pokemon::CurrentHealthPoints() const { return currentHealthPoints; }

int Pokemon::AttackPoints() const { return attackPoints; }

int Pokemon::DefensePoints() const { return defensePoints; }
////
//

// Methods
//// Actions
void Pokemon::attack(Pokemon &target) {
    if(target.currentHealthPoints <= 0) {
        std::cout << target.name << " is already defeated!" << std::endl;
        return;
    }
    int damage = this->attackPoints - target.defensePoints;
    if (damage < 0) damage = 0;
    std::cout << this->name << " attacks " << target.name << " for " << damage << " damage!" << std::endl;
    target.takeDamage(damage);
}

void Pokemon::takeDamage(int damage) {
    this->currentHealthPoints -= damage;
    if (this->currentHealthPoints < 0) this->currentHealthPoints = 0;
    std::cout << this->name << " now has " << this->currentHealthPoints << " HP." << std::endl;
}
////

///// Utils
string Pokemon::toString() {
    return "Pokemon{id: " + std::to_string(id) + ", name: " + name + ", evolution: " + std::to_string(evolution) + ", maxHealthPoints: " + std::to_string(maxHealthPoints) + ", currentHealthPoints: " + std::to_string(currentHealthPoints) + ", attackPoints: " + std::to_string(attackPoints) + ", defensePoints: " + std::to_string(defensePoints) + "}";
}
////
//