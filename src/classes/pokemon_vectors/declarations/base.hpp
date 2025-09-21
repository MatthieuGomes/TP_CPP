#pragma once
#include "../../pokemon.hpp"



class Pokemon_Vector {
    protected:
        std::vector<Pokemon*> pokemons;
    public: 
        virtual Pokemon* getPokemon(int id);
        virtual ~Pokemon_Vector();
};