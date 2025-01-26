#include "Registry.h"
#include <vector>
#include <iostream>
#include "Human.h"
#include "SkiPass.h"
#include "SkiPassOption.h"
using namespace std;

void Registry::getState(){
    cout << "Registry (active SkiPasses): ";
    for(int i = 0; i < activeSkiPasses.size();i++){
        if(activeSkiPasses[i] == nullptr){
            cout << "0" << endl;
            return;
        }
        activeSkiPasses[i]->getState();
        cout << ", ";
    }
    cout << endl;
}
void Registry::actSkiPass(Human* client, SkiPassOption option){ 
    client->skiPass->setSkiPass(option);
    cout << client->getName() << " - activated skipass" << client->getName() << endl;
}
void Registry::checkSkiPasses(clock_t begin, clock_t curTime){
    for(int i = 0; i < activeSkiPasses.size(); i++){
        if(!(activeSkiPasses[i]->checkExpTime(begin, curTime))){
            activeSkiPasses.erase(activeSkiPasses.begin() + i);
        }
    }
}

