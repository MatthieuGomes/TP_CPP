#pragma once
#include "base.hpp"
/**
 * @file party.hpp
 * @class Pokemon_Party
 * @see Pokemon_Vector
 * @brief Represents a party of Pokemons.
 */
class Pokemon_Party : public virtual Pokemon_Vector {
public:
    // Constructors & Destructor
    //// Constructors
    /**
     * @brief Constructor for the Pokemon_Party class with a Pokemon object.
     * @param first_pkmn The first Pokemon to be added to the party.
     * @details This constructor initializes the party with a single Pokemon provided as an argument.
     * @note The Pokemon is copied to ensure the party has its own instance.
     * @see Pokemon
     */
    Pokemon_Party(Pokemon first_pkmn);
    /**
     * @brief Constructor for the Pokemon_Party class with a Pokemon ID.
     * @param first_pkmn_id The ID of the first Pokemon to be added to the party.
     * @details This constructor initializes the party by creating a new Pokemon instance using the provided ID.
     * @note The Pokemon is fetched from the Pokedex using its ID.
     * @see Pokemon
     * @see Pokedex
     */
    Pokemon_Party(int first_pkmn_id);
    ////
    //// Destructor
    /**
     * @brief Destructor for the Pokemon_Party class.
     * @details Cleans up resources used by the Pokemon_Party object.
     * @note Currently, this destructor only outputs a message indicating that the Pokemon_Party has been destroyed.
     */
    ~Pokemon_Party();
    ////
    //
    // Getters & Setters
    //// Getters
    /**
     * @brief Gets the list of Pokemons in the party.
     * @return A vector of pointers to the Pokemons in the party.
     * @details This method returns the current list of Pokemons that are part of the party.
     */
    std::vector<Pokemon*> getPokemons();
    /**
     * @brief Gets a Pokemon from the party by its index.
     * @param index The index of the Pokemon in the party.
     * @return A pointer to the Pokemon if found, nullptr otherwise.
     * @details This method checks if the provided index is valid and returns the corresponding Pokemon from the party. If the index is out of range, it returns nullptr and outputs an error message.
     */
    Pokemon* getPokemon(int index);
    ////
    //// Setters
    /**
     * @brief Adds a Pokemon to the party.
     * @param pkmn The Pokemon object to be added to the party.
     * @return true if the Pokemon was successfully added, false otherwise.
     * @details This method adds a copy of the provided Pokemon to the party.
     * @note The Pokemon is copied to ensure the party has its own instance.
     * @see Pokemon
     */
    bool addPokemon(Pokemon pkmn);
    /**
     * @brief Adds a Pokemon to the party using its ID.
     * @param pkmn_id The ID of the Pokemon to be added to the party.
     * @return true if the Pokemon was successfully added, false otherwise.
     * @details This method creates a new Pokemon instance using the provided ID and adds it to the party.
     * @note The Pokemon is fetched from the Pokedex using its ID.
     * @see Pokemon
     * @see Pokedex
     */
    bool addPokemon(int pkmn_id);
    /**
     * @brief Removes a Pokemon from the party by its index.
     * @param index The index of the Pokemon to be removed from the party.
     * @return true if the Pokemon was successfully removed, false otherwise.
     * @details This method checks if the provided index is valid and removes the corresponding Pokemon from the party. If the index is out of range, it returns false and outputs an error message.
     */
    bool removePokemon(int index);
    //// 
    //
    
};
