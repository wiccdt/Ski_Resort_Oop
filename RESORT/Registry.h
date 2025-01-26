#ifndef REGISTRY_H
#define REGISTRY_H
#include <vector>
#include "Human.h"
#include "SkiPass.h"
#include "SkiPassOption.h"
using namespace std;

class SkiPass;
class Human;

class Registry{
private:
    vector<SkiPass*> activeSkiPasses;
public:
    void getState();
    void actSkiPass(Human* client, SkiPassOption option);
    void checkSkiPasses(clock_t begin, clock_t curTime);
};

#endif