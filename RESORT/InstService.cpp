#include <vector>
#include <string>
#include <iostream>
#include "Instructor.h"
#include "InstDeal.h"
#include "InstService.h"

void InstService::addInst(Instructor* instructor, SkiPass* skiPass){
    instructor->setSkiPass(skiPass);
    instructors.push_back(instructor);
}
void InstService::giveInst(Adult* client){
    Instructor* instructor = instructors[rand() % instructors.size()];
    InstDeal* deal = new InstDeal(client, instructor);
    client->instDeal = deal;
    instructor->instDeal = deal;
    cout << instructor->getName() << "giving lesson to " << client->getName() << endl;
}
void InstService::checkDeals(clock_t begin, clock_t curTime){
    for(int i = 0; i < activeInstDeals.size(); i++){
        if(!(activeInstDeals[i]->checkExpTime(begin, curTime))){
            activeInstDeals.erase(activeInstDeals.begin() + i);
            delete activeInstDeals[i]->getClient()->instDeal;
            activeInstDeals[i]->getClient()->instDeal = nullptr;
            activeInstDeals[i]->getInstructor()->instDeal = nullptr;
        }
    }
}
void InstService::getState(){
    cout << "Instructor Service (active instructor deals): ";
    for(int i = 0; i < activeInstDeals.size();i++){
        activeInstDeals[i]->getState();
    }
}
