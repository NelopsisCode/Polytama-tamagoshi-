
#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H
#include "Item.h"
#include "Bar.h"
using namespace std;
/**
 * \class <Consommable>
 * @brief Un Consommable est une denree alimentaire 
 * @param food Valeur de changement sur la jauge de nourriture
 * @param hydration Valeur de changement sur la jauge d'hydratation
 * @param hygiene Valeur de changement sur la jauge de proprete
 * @param happiness Valeur de changement sur la jauge de joie
 */
class Consommable : public Item {
public:
	
	//Constructeur/Destructeur
	/**
	 * @brief Constructeur par defaut
	 */
	Consommable();
	
	/**
	 * @brief Constructeur par copie
	 * @param idIt Identifiant du consommable a copier
	 * @param nameIt Nom du consommable a copier
	 * @param nbIt Nombre de consommables a copier
	 * @param foo Valeur de changement sur la jauge de nourriture a copier
	 * @param hydra Valeur de changement sur la jauge d'hydratation a copier
	 * @param hyg Valeur de changement sur la jauge de proprete a copier
	 * @param happi Valeur de changement sur la jauge de joie a copier
	 */
	Consommable(const unsigned int & idIt,const string& nameIt,
		const int& nbIt,const int &foo, const int& hydra, 
		const int& hyg, const int& happi);

	/**
	 * @brief Destructeur, valeur de changement des jauges a 0
	 */
	~Consommable();
	
	//SET/GET
	/**
	 * @brief Mutateur de la valeur de changement sur la jauge de nourriture 
	 * @param foo Valeur de changement sur la jauge de nourriture
	 */
	void setFood (const int& foo);
	
	/**
	 * @brief Accesseur de la valeur de changement sur la jauge de nourriture
	 * @return Valeur de changement sur la jauge de nourriture 
	 */
	int getFood()const;
	
	/**
	 * @brief Mutateur de la valeur de changement sur la jauge d'hydratation
	 * @param hydra Valeur de changement sur la jauge d'hydratation
	 */
	void setHydration(const int & hydra);
	
	/**
	 * @brief Accesseur de la valeur de changement sur la jauge d'hydratation
	 * @return Valeur de changement sur la jauge d'hydratation
	 */
	int getHydration ()const;
	
	/**
	 * @brief Mutateur de la valeur de changement sur la jauge de proprete
	 * @param hyg Valeur de changement sur la jauge de proprete
	 */
	void setHygiene(const int& hyg);
	
	/**
	 * @brief Accesseur de la valeur de changement sur la jauge de proprete
	 * @return Valeur de changement sur la jauge de proprete
	 */
	int getHygiene ()const;
	
	/**
	 * @brief Mutateur de la valeur de changement sur la jauge de joie
	 * @param happi Valeur de changement sur la jauge de joie
	 */
	void setHappiness (const int & happi);
	
	/**
	 * @brief Accesseur de la valeur de changement sur la jauge de joie
	 * @return Valeur de changement sur la jauge de joie
	 */
	int getHappiness ()const;
	
	//surcharge =
	/**
	 * @brief Surchage de =
	 * @param conso Consommable
	 * @return Consommable
	 */
	Consommable operator=(const Consommable& conso);
	

	
private:
	int food;
	int hydration;
	int hygiene;
	int happiness;

};

#endif /* CONSOMMABLE_H */

