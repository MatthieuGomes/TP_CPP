#include "declarations/attack.hpp"
#include <bits/stdc++.h>

int Pokemon_Attack::team_capacity = 6;

/**
 * @brief Constructor for the Pokemon_Attack class.
 * @param party The Pokemon_Party object representing the party of Pokemons.
 * @param first_pkmn_party_index The index of the first Pokemon to be added to the attack team.
 */
Pokemon_Attack::Pokemon_Attack(Pokemon_Party party, int first_pkmn_party_index) : party(party) {
    this->pokemons.push_back(party.getPokemon(first_pkmn_party_index));
}
/**
 * @brief Destructor for the Pokemon_Attack class.
 * @details Cleans up resources used by the Pokemon_Attack object.
 * @note Currently, this destructor only outputs a message indicating that the Pokemon_Attack has been destroyed.
 */
Pokemon_Attack::~Pokemon_Attack() {
    std::cout << "Destroying Pokemon Attack" << std::endl;
}
/**
 * @brief Gets the list of Pokemons in the attack team.
 * @return A vector of pointers to the Pokemons in the attack team.
 * @details This method returns the current list of Pokemons that are part of the attack team.
 */
std::vector<Pokemon*> Pokemon_Attack::getPokemons(){
    return this->pokemons;
}
/**
 * @brief Gets a Pokemon from the attack team by its index.
 * @param index The index of the Pokemon in the attack team.
 * @return A pointer to the Pokemon if found, nullptr otherwise.
 * @details This method checks if the provided index is valid and returns the corresponding Pokemon from the attack team. If the index is out of range, it returns nullptr and outputs an error message.
 */
Pokemon* Pokemon_Attack::getPokemon(int index){
    if(index < 0 || index >= pokemons.size()) {
        std::cout << "Pokemon not found in attack team" << std::endl;
        return nullptr;
    }
    return pokemons.at(index);
}
// Setters
/**
 * @brief Adds a Pokemon from the party to the attack team if there is capacity.
 * @param pkmn_party_index The index of the Pokemon in the party to be added
 * @return true if the Pokemon was successfully added, false otherwise.
 * @details This method checks if the attack team has reached its capacity. If not, it adds the specified Pokemon from the party to the attack team and removes it from the party.
 * @note The attack team has a fixed capacity defined by the static member `team_capacity`.
 */
bool Pokemon_Attack::addPokemon(int pkmn_party_index){
    if (pkmn_party_index < 0 || pkmn_party_index >= party.getPokemons().size()) {
        std::cout << "Selected Pokemon not in party" << std::endl;
        return false;
    }
    
    if (this->pokemons.size() < team_capacity) {
        this->pokemons.push_back(new Pokemon(*party.getPokemon(pkmn_party_index)));
        this->party.removePokemon(pkmn_party_index);
        return true;
    } else {
        std::cout << "Team is at full capacity!" << std::endl;
        return false;
    }
}
/**
 * @brief Removes a Pokemon from the attack team and adds it back to the party.
 * @param pkmn_attack_index The index of the Pokemon in the attack team to be removed.
 * @return true if the Pokemon was successfully removed, false otherwise.
 * @details This method checks if the specified index is valid and if there is more than one Pokemon in the attack team. If both conditions are met, it removes the specified Pokemon from the attack team and adds it back to the party.
 * @note The attack team must always have at least one Pokemon.
 */
bool Pokemon_Attack::removePokemon(int pkmn_attack_index){
    if (pkmn_attack_index < 0 || pkmn_attack_index >= pokemons.size()) {
        std::cout << "Selected Pokemon not in attack team" << std::endl;
        return false;
    }
    if (pokemons.size() <= 1) {
        std::cout << "Cannot remove the last Pokemon from the attack team!" << std::endl;
        return false;
    }
    this->party.addPokemon(*pokemons.at(pkmn_attack_index));
    delete pokemons.at(pkmn_attack_index);
    pokemons.erase(pokemons.begin() + pkmn_attack_index);
    return true;
}
/**
 * @brief Moves a Pokemon within the attack team from one index to another.
 * @param from_index The current index of the Pokemon to be moved.
 * @param to_index The target index where the Pokemon should be moved.
 * @return true if the Pokemon was successfully moved, false otherwise.
 * @details This method checks if both indices are valid and not the same. If valid, it moves the Pokemon from the `from_index` to the `to_index`. If the `to_index` is beyond the current size of the attack team but within capacity, it rotates the team to accommodate the move.
 */
bool Pokemon_Attack::movePokemon(int from_index, int to_index) {
    bool indexes_in_valid_range = (from_index >= 0 && from_index < pokemons.size()) && (to_index >= 0 && to_index < team_capacity) && (from_index != to_index);
    if(!indexes_in_valid_range){
        std::cout << "Indexes not in the valid range" << std::endl;
        return false;
    }
    if(!(indexes_in_valid_range && to_index > pokemons.size())) {
        std::swap(pokemons.at(from_index), pokemons.at(to_index));
        return true;
    }
    else{
        std::rotate(pokemons.begin()+from_index, pokemons.begin()+from_index+1, pokemons.end());
        return true;
    }
}