#include "declarations/pokedex.hpp"

Pokedex *Pokedex::instance = nullptr;

// Constructors & Destructor
//// Constructors
Pokedex::Pokedex()
{
    string nomFichier = "../data/pokemons/pokedex.csv";
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open())
    { 
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
        return;
    }
    string ligne;
    int ligne_num = 0;
    int temp_id = 0;
    while (std::getline(fichier, ligne))
    { // Lit le fichier ligne par ligne
        if (ligne_num == 0)
        {
            ligne_num++;
            continue;
        }                            // Ignore la premi�re ligne (en-t�tes)
        std::stringstream ss(ligne); // Utilise un flux pour diviser la ligne
        string cellule;
        std::vector<string> donneesLigne;
        // Divise la ligne en cellules s�par�es par des virgules
        
        while (std::getline(ss, cellule, ','))
        {
            donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur
        }
        // Affiche les donn�es de la ligne
        int id = std::stoi(donneesLigne.at(0));
        
        if (id != temp_id)
        {
            temp_id = id;
            string name = donneesLigne.at(1);
            int evolution = 0;
            int maxHealthPoints = std::stoi(donneesLigne.at(5));
            int attackPoints = std::stoi(donneesLigne.at(6));
            int defensePoints = std::stoi(donneesLigne.at(7));
            Pokemon *pkmn = new Pokemon(id, name, evolution, maxHealthPoints, attackPoints, defensePoints);
            pokemons.push_back(pkmn);
        }
    }
    fichier.close(); // Ferme le fichier
}
////

//// Destructor
Pokedex::~Pokedex()
{
    std::cout << "Destroying pokedex" << std::endl;
}
////
//

// Getters & Setters
//// Getters
Pokedex* Pokedex::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Pokedex();
    }
    return instance;
}
////
//
