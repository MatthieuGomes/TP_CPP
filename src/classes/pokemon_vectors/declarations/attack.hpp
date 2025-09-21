#include "base.hpp"
#include "party.hpp"


/**
 * @file attack.hpp
 * @class Pokemon_Attack
 * @see Pokemon_Vector
 * @brief Represents an attack team of Pokemons.
 */
class Pokemon_Attack : public virtual Pokemon_Vector {
    private:
        Pokemon_Party party;
        static int team_capacity;
    public:
        Pokemon_Attack(Pokemon_Party party, int first_pkmn_party_index);
        ~Pokemon_Attack();
        std::vector<Pokemon*> getPokemons();
        bool addPokemon(int pkmn_party_index);
        bool removePokemon(int pkmn_attack_index);
        bool movePokemon(int from_index, int to_index);
        Pokemon* getPokemon(int index);
};
