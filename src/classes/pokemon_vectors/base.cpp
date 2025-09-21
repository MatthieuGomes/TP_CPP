#include "declarations/base.hpp"

Pokemon_Vector::~Pokemon_Vector()
{
    for (Pokemon* pkmn : pokemons) {
        delete pkmn;
    }
    pokemons.clear();
}

Pokemon* Pokemon_Vector::getPokemon(int id){
    return new Pokemon(*pokemons.at(id-1));
}
