#ifndef BAR_H
#define BAR_H
#include <string>
using namespace std;

/**
\class <Bar>
@brief Cette classe permet de créer et de gérer des jauges de vie, de faim, de soif, d'hygiene et de joie

@param valueBar valeur de la jauge\n
@param maxBar le maximum que peut atteindre la jauge\n
@param typeBar le nom ou type de la jauge\n
*/
class Bar {

public :

  // Constructeur
/**
@brief Constructeur par défaut de la jauge
Crée une jauge vide
*/
  Bar();
  
/**
@brief Constructeur par copie de la jauge
Crée une jauge dont la valeur celle rentrée en parametre de la fonction

@param [in] val valeur qu'on souhaite donner à notre jauge en la créant
*/
  Bar(const unsigned int& val);

  // Get / Set
/**
@brief Mutateur de la valeur de la jauge

@param [in] val valeur qu'on souhaite donner à notre jauge
*/
  void setValue (const unsigned int& val);
  
/**
@brief Accesseur de la valeur de la jauge
 * @return Valeur de la jauge
*/
  unsigned int getValue() const;
  
/**
@brief Mutateur du type de la jauge (son nom)

@param [in] string nom qu'on souhaite donner à notre jauge
*/
  void setTypeBar (const string& type);
  
/**
@brief Accesseur du type de la jauge (son nom)
 * @return Type de la jauge
*/
  string getTypeBar() const;
  
/**
@brief Mutateur de la valeur maximale de la jauge

@param [in] max valeur maximale qu'on souhaite donner à notre jauge
*/
  void setMaxBar (const unsigned int& max);
  
/**
@brief Accesseur de la valeur maximale de la jauge
 * @return Maximum de la jauge
*/
  unsigned int getMaxBar() const;

  // Fonction membre
/**
@brief Affichage de la jauge
affiche la valeur de la jauge en spécifiant son nom
*/
  void printValue() const;
  
/**
@brief Changement de la valeur de la jauge
Permet d'ajouter une valeur a la jauge touy en vérifiant qu'elle ne depassera pas son maximum

@param [in] valAdded valeur qu'on souhaite donner à notre jauge en la créant
*/
  void changeValue (const int& valAdded);
  
/**
@brief Test de regression
Permet de tester toutes les fonctions de la classe bar
*/
  void regressionBar();

  // Surcharge operateur
  
/**
@brief Surcharge d'operateur += de la jauge

@param [in] val valeur qu'on souhaite ajouter à notre jauge
*/
  void operator+=(const unsigned int & val);
  
  /**
@brief Surcharge d'operateur -= de la jauge

@param [in] val valeur qu'on souhaite soustraire à notre jauge
*/
  void operator-=(const unsigned int & val);
  
 /**
@brief Surcharge d'operateur = de la jauge

@param [in] b jauge qu'on souhaite copier 
  * @return Pointeur sur la jauge
*/
  Bar* operator=(const Bar& b);


private : 

unsigned int valueBar;
unsigned int maxBar;
string typeBar;

};


#endif /* BAR_H */