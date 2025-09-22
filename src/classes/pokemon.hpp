#pragma once
#include "../utils/basic_import.hpp"

/**
 * @file pokemon.hpp
 * @class Pokemon
 * @brief Represents a Pokemon with various attributes and behaviors.
 * 
 * 
 */
class Pokemon {
    private:
        int id;
        string name;
        int evolution = 0;
        int maxHealthPoints;
        int currentHealthPoints;
        int attackPoints;
        int defensePoints;
    public:
        // Constructors & Destructor
        //// Constructors
        /**
         * @brief Constructs a new Pokemon object with specified attributes.
         * 
         * @param id The unique identifier for the Pokemon.
         * @param name The name of the Pokemon.
         * @param evolution The evolution stage of the Pokemon.
         * @param maxHealthPoints The maximum health points of the Pokemon.
         * @param attackPoints The attack points of the Pokemon.
         * @param defensePoints The defense points of the Pokemon.
         * 
         * @details Create a custom Pokemon with given attributes.
         */
        Pokemon(int id, string name, int evolution, int maxHealthPoints, int attackPoints, int defensePoints); // Invent a pokemon
        /**
         * @brief Constructs a new Pokemon object by copying another Pokemon.
         * 
         * @param pkmn The Pokemon object to copy from.
         * 
         * @details This copy constructor creates a new Pokemon instance with the same attributes as the provided Pokemon object.
         */
        Pokemon(int id); // Get a pokemon from the pokedex by its id
        /**
         * @brief Constructs a new Pokemon from the Pokedex using its ID.
         * 
         * @param id The unique identifier for the Pokemon to retrieve from the Pokedex.
         * @see Pokemon::Pokemon
         * @details This constructor initializes a Pokemon object by fetching its attributes from the Pokedex singleton instance using the provided ID.
         * 
         */
        Pokemon(const Pokemon &pkm); // Copy constructor
        ////

        //// Destructor
                /**
         * @brief Destructor for the Pokemon class.
         * @details Cleans up resources used by the Pokemon object.
         * @note Currently, this destructor only outputs a message indicating that the Pokemon has been destroyed.
         */
        ~Pokemon();
        ////
        //
        
        // Getters and Setters
        //// Getters
        /**
         * @brief Gets the ID of the Pokemon.
         * @return The unique identifier of the Pokemon.
         */
        int Id() const;
        /**
         * @brief Gets the name of the Pokemon.
         * @return The name of the Pokemon.
         */
        string Name() const;
        /**
         * @brief Gets the evolution stage of the Pokemon.
         * @return The evolution stage of the Pokemon.
         */
        int Evolution() const;
        /**
         * @brief Gets the maximum health points of the Pokemon.
         * @return The maximum health points of the Pokemon.
         */
        int MaxHealthPoints() const;
        /**
         * @brief Gets the current health points of the Pokemon.
         * @return The current health points of the Pokemon.
         */
        int CurrentHealthPoints() const;
        /**
         * @brief Gets the attack points of the Pokemon.
         * @return The attack points of the Pokemon.
         */
        int AttackPoints() const;
        /**
         * @brief Gets the defense points of the Pokemon.
         * @return The defense points of the Pokemon.
         */
        int DefensePoints() const;
        ////
        //

        // Methodes
        //// Actions
        /**
         * @brief Attacks another Pokemon, dealing damage based on attack and defense points.
         * @param target The Pokemon to be attacked.
         * @details This method calculates the damage dealt to the target Pokemon by subtracting its defense points from the attacker's attack points. If the target's health points drop to zero or below, it is considered defeated.
         * @note so far no specific rules applied
         */
        void attack(Pokemon &target);
        /**
         * @brief Reduces the Pokemon's current health points by the specified damage amount.
         * @param damage The amount of damage to be taken.
         * @details This method decreases the current health points of the Pokemon by the damage amount. If the health points drop to zero or below, they are set to zero, indicating that the Pokemon is defeated.
         */
        void takeDamage(int damage);
        ////

        //// Utils
        /**
         * @brief Returns a string representation of the Pokemon object.
         * @return A string containing the Pokemon's attributes.
         */
        string toString();
        ////
        //
};