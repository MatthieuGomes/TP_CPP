#pragma once
#include "../../pokemon.hpp"


/**
 * @file base.hpp
 * @class Pokemon_Vector
 * @brief Base class for managing a collection of Pokemon objects.
 * 
 * This class provides a common interface and functionality for different types of Pokemon collections, such as parties or PC storage.
 * It includes methods for retrieving Pokemon by their ID and ensures proper memory management through its destructor.
 * 
 */
class Pokemon_Vector {
    protected:
        /**
         * @brief A vector that holds pointers to Pokemon objects.
         */
        std::vector<Pokemon*> pokemons;
    public: 
        // Constructors & Destructor
        //// Destructor
        /**
         * @brief Virtual destructor to ensure proper cleanup of derived classes.
         * 
         * This destructor iterates through the vector of Pokemon pointers, deletes each Pokemon object to free memory, and then clears the vector.
         */
        virtual ~Pokemon_Vector();
        ////
        //

        // Getters & Setters
        //// Getters
        /**
         * @brief Retrieves a Pokemon by its ID.
         * @param id The ID of the Pokemon to retrieve.
         * @return A pointer to a new Pokemon object with the specified ID.
         */
        virtual Pokemon* getPokemon(int id);
        ////
        //
        
};