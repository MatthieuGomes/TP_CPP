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
        enum Type {
            player = 6,
            opponent = 6,
            wild = 1
        };
        /**
         * @brief The party of Pokemons from which the attack team is formed.
         * @see Pokemon_Party
         */
        Pokemon_Party party;
        /**
         * @brief The maximum capacity of the attack team.
         * @details This static member variable defines the maximum number of Pokemons that can be part of the attack team.
         */
        int team_capacity;
    public:
        /**
         * @brief Constructor for the Pokemon_Attack class.
         * @param party The Pokemon_Party object representing the party of Pokemons.
         * @param first_pkmn_party_index The index of the first Pokemon to be added to the attack team.
         */
        Pokemon_Attack(int first_pkmn_party_index, Pokemon_Party party);
        /**
         * @brief Destructor for the Pokemon_Attack class.
         * @details Cleans up resources used by the Pokemon_Attack object.
         * @note Currently, this destructor only outputs a message indicating that the Pokemon_Attack has been destroyed.
         */
        ~Pokemon_Attack();
        /**
         * @brief Gets the list of Pokemons in the attack team.
         * @return A vector of pointers to the Pokemons in the attack team.
         * @details This method returns the current list of Pokemons that are part of the attack team.
         */
        std::vector<Pokemon*> getPokemons();
        /**
         * @brief Gets a Pokemon from the attack team by its index.
         * @param index The index of the Pokemon in the attack team.
         * @return A pointer to the Pokemon if found, nullptr otherwise.
         * @details This method checks if the provided index is valid and returns the corresponding Pokemon from the attack team. If the index is out of range, it returns nullptr and outputs an error message.
         */
        bool addPokemon(int pkmn_party_index);
        /**
         * @brief Adds a Pokemon from the party to the attack team if there is capacity.
         * @param pkmn_party_index The index of the Pokemon in the party to be added
         * @return true if the Pokemon was successfully added, false otherwise.
         * @details This method checks if the attack team has reached its capacity. If not, it adds the specified Pokemon from the party to the attack team and removes it from the party.
         * @note The attack team has a fixed capacity defined by the static member `team_capacity`.
         */
        bool removePokemon(int pkmn_attack_index);
        /**
         * @brief Removes a Pokemon from the attack team and adds it back to the party.
         * @param pkmn_attack_index The index of the Pokemon in the attack team to be removed.
         * @return true if the Pokemon was successfully removed, false otherwise.
         * @details This method checks if the specified index is valid and if there is more than one Pokemon in the attack team. If both conditions are met, it removes the specified Pokemon from the attack team and adds it back to the party.
         * @note The attack team must always have at least one Pokemon.
         */
        bool movePokemon(int from_index, int to_index);
        /**
         * @brief Moves a Pokemon within the attack team from one index to another.
         * @param from_index The current index of the Pokemon to be moved.
         * @param to_index The target index where the Pokemon should be moved.
         * @return true if the Pokemon was successfully moved, false otherwise.
         * @details This method checks if both indices are valid and not the same. If valid, it moves the Pokemon from the `from_index` to the `to_index`. If the `to_index` is beyond the current size of the attack team but within capacity, it rotates the team to accommodate the move.
         */
        Pokemon* getPokemon(int index);
};
