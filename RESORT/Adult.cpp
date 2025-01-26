#include "Adult.h"
#include <iostream>
using namespace std;
#include<string>
#include <random>
#include "Child.h"
#include "LeaseDeal.h"
#include "SkiPass.h"
#include "InstDeal.h"
#include "SkiResort.h"
#include "Inventory.h"
#include <iostream>

Adult::Adult(string name){
    this->name = name;
    child = nullptr;
    deposit = true;
    inventory = NO_INVENTORY;
    instDeal = nullptr;
    skiPass = nullptr;
    cout << "Client: " << name << endl;
}
void Adult::setChild(Child* child){
    this->child = child;
}
void Adult::actSkiPass(SkiResort* skiResort){
    srand(time(0));
    SkiPassOption option = static_cast<SkiPassOption>(rand() % 4);
    skiResort->registry->actSkiPass((Human*)this, option);
    if(this->child != nullptr){
        option = static_cast<SkiPassOption>(rand() % 4);
        skiResort->registry->actSkiPass((Human*)this->getChild(), option);
    }
}
void Adult::getInventory(SkiResort* skiResort){
    if(child != nullptr){
        skiResort->rental->giveInventory(this, true);
        return;
    }
    skiResort->rental->giveInventory(this, false);
}
void Adult::returnInventory(SkiResort* skiResort){
    if(child != nullptr){
        skiResort->rental->getInventory(this, true);
        return;
    }
    skiResort->rental->getInventory(this, false);
}

void Adult::setDeposit(bool deposit){
    this->deposit = deposit;
}

void Adult::takeInstructor(SkiResort* skiResort){
    skiResort->instService->giveInst(this);
}

Child* Adult::getChild(){
    return child;
}
void Adult::getState(){
    cout << "adult: " << name << endl;
    child->getState();
    cout << "deposit" << deposit << endl;
    switch(inventory){
        case NO_INVENTORY:
            cout << "skipass: not activated" << endl;
            break;
        case ADULT_DESK:
            cout << "skipass: adult full day" << endl;
            break;
        case ADULT_SKI:
            cout << "skipass: adult half day" << endl;
            break;
        case CHILD_DESK:
            cout << "skipass: child full day" << endl;
            break;
        case CHILD_SKI:
            cout << "skipass: child half day" << endl;
            break;
    }
    skiPass->getState();
    leaseDeal->getState();
    instDeal->getState();
}

string Adult::getName(){
    return name;
}

