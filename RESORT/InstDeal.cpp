#include "Instructor.h"
#include "Adult.h"
#include <iostream>

class Instructor;
class Adult;

InstDeal::InstDeal(Adult* client, Instructor* instructor){
    this->client = client;
    this->instructor = instructor;
}
bool InstDeal::checkExpTime(clock_t begin, clock_t curTime){
    if(curTime - begin >= expTime){
        return false;
    }
    return true;
}
Adult* InstDeal::getClient(){
    return client;
}
Instructor* InstDeal::getInstructor(){
    return instructor;
}
void InstDeal::getState(){
    cout << instructor->getName() << "giving lesson to " << client->getName() << endl;
}
