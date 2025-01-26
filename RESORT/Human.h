#ifndef HUMAN_H
#define HUMAN_H
#include <string>
using namespace std;
#include "SkiPass.h"

class SkiPass;

class Human{
public:
    string name;
    SkiPass* skiPass;
    virtual void getState();
    string getName();
};


#endif