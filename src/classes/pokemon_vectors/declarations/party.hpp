#pragma once
#include "base.hpp"
/**
 * @file party.hpp
 * @class Pokemon_Party
 * @see Pokemon_Vector
 * @brief Represents a party of Pokemons.
 */
class Pokemon_Party : public Pokemon_Vector {
public:
    Pokemon_Party(Pokemon first_pkmn);
    Pokemon_Party(int first_pkmn_id);
    ~Pokemon_Party();
    std::vector<Pokemon*> getPokemons();
    void addPokemon(Pokemon pkmn);
    void addPokemon(int pkmn_id);
    void removePokemon(int index);
    Pokemon* getPokemon(int index);
};
