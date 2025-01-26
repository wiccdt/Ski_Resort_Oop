#include "InstDeal.h"
#include "Instructor.h"
#include "Human.h"
#include "SkiPass.h"
#include <string>
#include <iostream>
using namespace std;
class InstDeal;
Instructor::Instructor(string name){
    this->name = name;
    cout << "Instructor: " << name << endl;
}
void Instructor::getState(){
    cout << "Instructor: " << name << "deal with: " << instDeal->getClient()->getName();
}
void Instructor::setSkiPass(SkiPass* skiPass){
    this->skiPass = skiPass;
    skiPass->setSkiPass(ALWAYS_ACTIVATED);
}
