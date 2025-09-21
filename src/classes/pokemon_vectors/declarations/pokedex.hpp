#pragma once
#include "base.hpp"

class Pokedex : public virtual Pokemon_Vector {
    private:
        static Pokedex* instance;
        Pokedex();

    public:
        static Pokedex* getInstance();
        ~Pokedex();
};