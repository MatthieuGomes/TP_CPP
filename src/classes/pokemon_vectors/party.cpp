#include "declarations/party.hpp"

// Constructors & Destructor
//// Constructors
Pokemon_Party::Pokemon_Party(Pokemon first_pkmn) {
    this->pokemons.push_back(new Pokemon(first_pkmn));
}
Pokemon_Party::Pokemon_Party(int first_pkmn_id) {
    this->pokemons.push_back(new Pokemon(first_pkmn_id));
}
////

//// Destructor
Pokemon_Party::~Pokemon_Party() {
    std::cout << "Destroying Pokemon Party" << std::endl;
}
////
//

// Getters & Setters
//// Getters
std::vector<Pokemon*> Pokemon_Party::getPokemons(){
    return this->pokemons;
}
Pokemon* Pokemon_Party::getPokemon(int index){
    if(index < 0 || index >= pokemons.size()) {
        std::cout << "Index out of range" << std::endl;
        return nullptr;
    }
    return pokemons.at(index);
}
////

//// Setters
bool Pokemon_Party::addPokemon(Pokemon pkmn){
    this->pokemons.push_back(new Pokemon(pkmn));
    return true;
}
bool Pokemon_Party::addPokemon(int pkmn_id){
    this->pokemons.push_back(new Pokemon(pkmn_id));
    return true;
}
bool Pokemon_Party::removePokemon(int index){
    if(index < 0 || index >= pokemons.size()) {
        std::cout << "Index out of range" << std::endl;
        return false;
    }
    delete pokemons.at(index);
    pokemons.erase(pokemons.begin() + index);
    return true;
}
////
//
