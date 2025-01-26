#ifndef INST_DEAL_H
#define INST_DEAL_H
#include "Instructor.h"
#include "Adult.h"

class Instructor;
class Adult;

class InstDeal{
private:
    Adult* client;
    Instructor* instructor;
    int expTime = 60; 
public:
    InstDeal(Adult* client, Instructor* instructor);
    void getState();
    bool checkExpTime(clock_t begin, clock_t curTime);
    Adult* getClient();
    Instructor* getInstructor();
};

#endif