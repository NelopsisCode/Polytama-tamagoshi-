#include "Bar.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

Bar::Bar(){
    valueBar = 0;
    maxBar = 100;
    typeBar = "";
}

Bar::Bar(unsigned int val){
    maxBar = 100;
    assert (val <= 100);
    valueBar = val;
}


void Bar::setValue(unsigned int val){
    assert (val<=maxBar);
    valueBar = val;
}

unsigned int Bar::getValue()const{
    return valueBar;
}

void Bar::setMaxBar(unsigned int max){
    assert (max >= valueBar);
    maxBar = max;
}

unsigned int Bar::getMaxBar()const{
    return maxBar;
}

void Bar::setTypeBar(string type){
    typeBar = type;
}

string Bar::getTypeBar()const{
    return typeBar;
}

void Bar::changeValue(int valAdded){
    assert((valueBar+valAdded)<= maxBar);
    valueBar = valueBar+valAdded;
}

void Bar::printValue() const{
    cout<<"la valeur de la barre "<<typeBar<<" est "<< valueBar<<endl;
}

void Bar::operator+=(const unsigned int & val){
    if (valueBar <= maxBar - val)
    {
        valueBar += val;
    }
    else
    {
        valueBar = 100;
    } 
}

void Bar::operator-=(const unsigned int & val){
    if (valueBar >= val)
    {
        valueBar -= val;
    }
    else
    {
        valueBar = 0;
    } 
    
}

Bar* Bar::operator=(const Bar& b){
    return this;
}

void Bar::regressionBar(){
    cout<<"test constructeur";
    Bar b1;
    Bar b2(50);
    b1.setTypeBar("Test 1");
    assert(b1.getValue()==0 && b1.getTypeBar() == "Test 1" && b1.getMaxBar() == 100);
    assert(b2.getValue()==50 && b2.getTypeBar() == "" && b2.getMaxBar() == 100);
    cout<<"ok";

    cout<<"test accsseurs";
    b2.setMaxBar(200);
    b2.setTypeBar("SeAz19 **");
    b2.setValue(200);

    assert(b2.getValue()==200 && b2.getTypeBar() == "SeAz19 **" && b2.getMaxBar() == 200);
    cout<<"ok";

    cout<<"test operateur";
    b1 += 45;
    assert(b1.getValue()== 45);
    b1 -= 5;
    assert(b1.getValue() == 40);
    Bar b3 = b1;
    assert(b3.getValue()==40 && b3.getTypeBar() == "Test 1" && b3.getMaxBar() == 100);
    cout<<"ok";
   
    
    b1.printValue();

    cout << "la phrase affiché est elle : la valeur de la barre test 1 est 40.";
    string check;
    cin>>check;
    assert(check == "oui");
    

}