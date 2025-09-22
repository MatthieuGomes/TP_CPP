#include "declarations/attack.hpp"
#include <bits/stdc++.h>

// Constructors & Destructor
//// Constructors
Pokemon_Attack::Pokemon_Attack(int first_pkmn_party_index,Pokemon_Party party) : party(party) {
    this->party = party;
    this->pokemons.push_back(this->party.getPokemon(first_pkmn_party_index));
    this->team_capacity = 6;
}
////

//// Destructor
Pokemon_Attack::~Pokemon_Attack() {
    std::cout << "Destroying Pokemon Attack" << std::endl;
}
////
//

// Getters & Setters
//// Getters
std::vector<Pokemon*> Pokemon_Attack::getPokemons(){
    return this->pokemons;
}
Pokemon* Pokemon_Attack::getPokemon(int index){
    if(index < 0 || index >= pokemons.size()) {
        std::cout << "Pokemon not found in attack team" << std::endl;
        return nullptr;
    }
    return pokemons.at(index);
}
////

//// Setters
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
////
//