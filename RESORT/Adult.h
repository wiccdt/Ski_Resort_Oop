#ifndef ADULT_H
#define ADULT_H
using namespace std;
#include<string>
#include "Child.h"
#include "Human.h"
#include "LeaseDeal.h"
#include "SkiPass.h"
#include "InstDeal.h"
#include "SkiResort.h"
#include "Inventory.h"
class Child;
class Human;
class LeaseDeal;
class InstDeal;
class SkiPass;


class Adult: public Human{
private:
    string name;
    Child* child;
    bool deposit;
public:
    Inventory inventory;
    LeaseDeal* leaseDeal;
    InstDeal* instDeal;
    SkiPass* skiPass;
    Adult(string name);
    void setChild(Child* child);
    void actSkiPass(SkiResort* skiResort);
    void getInventory(SkiResort* skiResort);
    void returnInventory(SkiResort* skiResort);
    void setDeposit(bool deposit);
    void takeInstructor(SkiResort* skiResort);
    string getName();
    Child* getChild();
    void getState();

};

#endif