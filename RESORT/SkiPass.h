#ifndef SKI_PASS_H
#define SKI_PASS_H
#include <ctime>
#include "Human.h"
#include "Registry.h"
#include "SkiPassOption.h"
class Human;
class Registry;

class SkiPass{
private:
    Human* owner; 
    SkiPassOption option;
    int expTime; 
public:
    SkiPass(Human* owner);
    void setSkiPass(SkiPassOption option);
    void getState();
    bool checkExpTime(clock_t begin, clock_t curTime);
    int getExpTime();
};

#endif