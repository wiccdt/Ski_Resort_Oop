#include <string>
#include <iostream>
using namespace std;
#include "Child.h"
#include "Human.h"
#include "Adult.h"
#include "SkiPass.h"
#include "Inventory.h"

Child::Child(string name, Adult* parent){
    this->name = name;
    this->parent = parent;
    parent->setChild(this);
    inventory = NO_INVENTORY;
    skiPass = nullptr;
    cout << parent->getName()  << "' child: " << name << endl;
}
void Child::getState(){
    cout << "Child: " << name;
    cout << "Parent: " << parent->getName();
}
