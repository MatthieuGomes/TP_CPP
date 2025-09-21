#include "pokemon_vectors/declarations/pokedex.hpp"


// Constructors
/**
 * @brief Constructs a new Pokemon object with specified attributes.
 * 
 * @param id The unique identifier for the Pokemon.
 * @param name The name of the Pokemon.
 * @param evolution The evolution stage of the Pokemon.
 * @param maxHealthPoints The maximum health points of the Pokemon.
 * @param attackPoints The attack points of the Pokemon.
 * @param defensePoints The defense points of the Pokemon.
 * 
 * @details Create a custom Pokemon with given attributes.
 */
Pokemon::Pokemon(int id, string name, int evolution, int maxHealthPoints, int attackPoints, int defensePoints) {
    this->id = id;
    this->name = name;
    this->evolution = evolution;
    this->maxHealthPoints = maxHealthPoints;
    this->currentHealthPoints = maxHealthPoints;
    this->attackPoints = attackPoints;
    this->defensePoints = defensePoints;
}
/**
 * @brief Constructs a new Pokemon object by copying another Pokemon.
 * 
 * @param pkmn The Pokemon object to copy from.
 * 
 * @details This copy constructor creates a new Pokemon instance with the same attributes as the provided Pokemon object.
 */
Pokemon::Pokemon(const Pokemon &pkmn) : id(pkmn.id), name(pkmn.name), evolution(pkmn.evolution), maxHealthPoints(pkmn.maxHealthPoints), currentHealthPoints(pkmn.currentHealthPoints), attackPoints(pkmn.attackPoints), defensePoints(pkmn.defensePoints) {
}
/**
 * @brief Constructs a new Pokemon from the Pokedex using its ID.
 * 
 * @param id The unique identifier for the Pokemon to retrieve from the Pokedex.
 * @see Pokemon::Pokemon
 * @details This constructor initializes a Pokemon object by fetching its attributes from the Pokedex singleton instance using the provided ID.
 * 
 */
Pokemon::Pokemon(int id) {
    Pokedex* pokedex = Pokedex::getInstance();
    Pokemon pkmn = *pokedex->getPokemon(id);
    *this = pkmn;   
}
/**
 * @brief Destructor for the Pokemon class.
 * @details Cleans up resources used by the Pokemon object.
 * @note Currently, this destructor only outputs a message indicating that the Pokemon has been destroyed.
 */
Pokemon::~Pokemon() {
    std::cout << "Pokemon " << name << " destroyed." << std::endl;
    // No need to delete this; it will be automatically managed.
}
// Getters and Setters
//// Getters
/**
 * @brief Gets the ID of the Pokemon.
 * @return The unique identifier of the Pokemon.
 */
int Pokemon::Id() const { return id; }
/**
 * @brief Gets the name of the Pokemon.
 * @return The name of the Pokemon.
 */
string Pokemon::Name() const { return name; }
/**
 * @brief Gets the evolution stage of the Pokemon.
 * @return The evolution stage of the Pokemon.
 */
int Pokemon::Evolution() const { return evolution; }
/**
 * @brief Gets the maximum health points of the Pokemon.
 * @return The maximum health points of the Pokemon.
 */
int Pokemon::MaxHealthPoints() const { return maxHealthPoints; }
/**
 * @brief Gets the current health points of the Pokemon.
 * @return The current health points of the Pokemon.
 */
int Pokemon::CurrentHealthPoints() const { return currentHealthPoints; }
/**
 * @brief Gets the attack points of the Pokemon.
 * @return The attack points of the Pokemon.
 */
int Pokemon::AttackPoints() const { return attackPoints; }
/**
 * @brief Gets the defense points of the Pokemon.
 * @return The defense points of the Pokemon.
 */
int Pokemon::DefensePoints() const { return defensePoints; }
////
//

// Methods
/**
 * @brief Attacks another Pokemon, dealing damage based on attack and defense points.
 * @param target The Pokemon to be attacked.
 * @details This method calculates the damage dealt to the target Pokemon by subtracting its defense points from the attacker's attack points. If the target's health points drop to zero or below, it is considered defeated.
 * @note so far no specific rules applied
 */
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
/**
 * @brief Reduces the Pokemon's current health points by the specified damage amount.
 * @param damage The amount of damage to be taken.
 * @details This method decreases the current health points of the Pokemon by the damage amount. If the health points drop to zero or below, they are set to zero, indicating that the Pokemon is defeated.
 */
void Pokemon::takeDamage(int damage) {
    this->currentHealthPoints -= damage;
    if (this->currentHealthPoints < 0) this->currentHealthPoints = 0;
    std::cout << this->name << " now has " << this->currentHealthPoints << " HP." << std::endl;
}
//

///// Utils
/**
 * @brief Returns a string representation of the Pokemon object.
 * @return A string containing the Pokemon's attributes.
 */
string Pokemon::toString() {
    return "Pokemon{id: " + std::to_string(id) + ", name: " + name + ", evolution: " + std::to_string(evolution) + ", maxHealthPoints: " + std::to_string(maxHealthPoints) + ", currentHealthPoints: " + std::to_string(currentHealthPoints) + ", attackPoints: " + std::to_string(attackPoints) + ", defensePoints: " + std::to_string(defensePoints) + "}";
}