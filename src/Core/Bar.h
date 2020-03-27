#ifndef BAR_H
#define BAR_H
#include <string>
using namespace std;

class Bar {

public :

  // Constructeur
  Bar();
  Bar(unsigned int val);

  // Get / Set
  void setValue (unsigned int val);
  unsigned int getValue() const;
  void setTypeBar (string type);
  string getTypeBar() const;
  void setMaxBar (unsigned int max);
  unsigned int getMaxBar() const;

  // Fonction membre
  void printValue() const;
  void changeValue (int valAdded);
  void regressionBar();

  // Surcharge operateur
  void operator+=(const unsigned int & val);
  void operator-=(const unsigned int & val);
  Bar* operator=(const Bar& b);


private : 

unsigned int valueBar;
unsigned int maxBar;
string typeBar;

};


#endif /* BAR_H */