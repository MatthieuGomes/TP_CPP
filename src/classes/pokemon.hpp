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
        // Constructors
        Pokemon(int id, string name, int evolution, int maxHealthPoints, int attackPoints, int defensePoints); // Invent a pokemon
        Pokemon(int id); // Get a pokemon from the pokedex by its id
        Pokemon(const Pokemon &pkm); // Copy constructor
        ~Pokemon(); // Destructor
        
        // Methods
        //// Getters
        int Id() const;
        string Name() const;
        int Evolution() const;
        int MaxHealthPoints() const;
        int CurrentHealthPoints() const;
        int AttackPoints() const;
        int DefensePoints() const;
        
        //// Setters
        //bool setCurrentHealthPoints(int hp) { currentHealthPoints = hp; }

        //// Actions
        void attack(Pokemon &target);
        void takeDamage(int damage);

        //// Utils
        string toString();
};