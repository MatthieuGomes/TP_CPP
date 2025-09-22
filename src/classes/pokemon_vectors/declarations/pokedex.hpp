#pragma once
#include "base.hpp"
/**
 * @file pokedex.hpp
 * @class Pokedex
 * @see Pokemon_Vector
 * @brief Singleton class representing the Pokedex, a collection of all known Pokemons.
 * 
 * This class inherits from Pokemon_Vector and provides functionality to load and manage a comprehensive list of Pokemons.
 * It ensures that only one instance of the Pokedex exists throughout the application using the singleton design pattern.
 * 
 */
class Pokedex : public virtual Pokemon_Vector {
    private:
        /** Singleton instance */
        static Pokedex* instance;
        // Constructors & Destructor
        //// Constructors
        /**
         * @brief Private constructor for the Pokedex class.
         * @details This constructor initializes the Pokedex by loading Pokemon data from a CSV file located at "../data/pokemons/pokedex.csv".
         * It reads the file line by line, parses the data, and creates Pokemon objects which are then stored in the inherited pokemons vector.
         * 
         * @note The constructor is private to enforce the singleton pattern, preventing direct instantiation from outside the class.
         * 
         * @see Pokemon
         * @see Pokemon_Vector
         */
        Pokedex();
        ////
        //
    public:
        // Constructors & Destructor
        //// Destructor
        /**
         * @brief Destructor for the Pokedex class.
         * @details Cleans up resources used by the Pokedex object.
         * @note Currently, this destructor does not perform any specific actions.
         * 
         * @see Pokemon_Vector::~Pokemon_Vector
         */
        ~Pokedex();
        ////
        //
        // Getters & Setters
        //// Getters
        /**
         * @brief Retrieves a Pokemon by its ID from the Pokedex.
         * @param id The ID of the Pokemon to retrieve.
         * @return A pointer to a new Pokemon object with the specified ID.
         * @details This method overrides the base class method to provide access to Pokemons stored in the Pokedex.
         * 
         * @see Pokemon_Vector::getPokemon
         */
        static Pokedex* getInstance();
        ////
        //
        
};