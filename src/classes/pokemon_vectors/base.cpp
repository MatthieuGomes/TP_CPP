#include "declarations/base.hpp"
// Constructors & Destructor
//// Destructor
Pokemon_Vector::~Pokemon_Vector()
{
    for (Pokemon* pkmn : pokemons) {
        delete pkmn;
    }
    pokemons.clear();
}
////
//

// Getters & Setters
//// Getters
Pokemon* Pokemon_Vector::getPokemon(int id){
    return new Pokemon(*pokemons.at(id-1));
}
////
//