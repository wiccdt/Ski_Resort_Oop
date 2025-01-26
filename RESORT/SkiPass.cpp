#include <iostream>
using namespace std;
#include "SkiPass.h"
#include "Human.h"
#include "SkiPassOption.h"

SkiPass::SkiPass(Human* owner){
    this->owner = owner;
    owner->skiPass = this;
    option = NOT_ACTIVATED;
    expTime = 0;
}
void SkiPass::setSkiPass(SkiPassOption option){
    this->option = option;
    if(option == FULL_DAY_ADULT || option == FULL_DAY_CHILD){
        expTime = 4000; //4 sec
        return;
    }else if(option == HALF_DAY_ADULT || option == HALF_DAY_CHILD){
        expTime = 2000; //2 sec
        return;
    }
    expTime = 0;
}
void SkiPass::getState(){
    switch(option){
        case NOT_ACTIVATED:
            cout << owner->getName() << "'s skipass: not activated" << endl;
            break;
        case FULL_DAY_ADULT:
            cout << owner->getName() << "'s skipass: adult full day" << endl;
            break;
        case HALF_DAY_ADULT:
            cout << owner->getName() << "'s skipass: adult half day" << endl;
            break;
        case FULL_DAY_CHILD:
            cout << owner->getName() << "'s skipass: child full day" << endl;
            break;
        case HALF_DAY_CHILD:
            cout << owner->getName() << "'s skipass: child half day" << endl;
            break;
        case ALWAYS_ACTIVATED:
            break;
    }
}
bool SkiPass::checkExpTime(clock_t begin, clock_t curTime){
    if(curTime - begin >= expTime){
        option = NOT_ACTIVATED;
        expTime = 0;
        return false;
    }
    return true;
}
int SkiPass::getExpTime(){
    return expTime;
}
