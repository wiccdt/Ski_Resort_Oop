#ifndef INST_SERVICE_H
#define INST_SERVICE_H
#include <vector>
#include <string>
#include <iostream>
#include "Instructor.h"
#include "InstDeal.h"

class InstDeal;
class Instructor;

class InstService{
private:
    vector<Instructor*> instructors;
    vector<InstDeal*> activeInstDeals;
public:
    void addInst(Instructor* instructor, SkiPass* skiPass);
    void giveInst(Adult* client);
    void checkDeals(clock_t begin, clock_t curTime);
    void getState();
};

#endif