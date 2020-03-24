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

void Bar::operator+=(const int& val){
    this->changeValue(val);
}

void Bar::operator-=(const int& val){
    this->changeValue(-val);
}
//à refaire (avec return)
void Bar::operator=(const Bar& b){
    this->setMaxBar(b.getMaxBar());
    this->setValue(b.getValue());
    this->setTypeBar(b.getTypeBar());
}