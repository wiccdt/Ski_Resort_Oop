#ifndef Child_H
#define Child_H
#include <string>
using namespace std;
#include "Human.h"
#include "Adult.h"
#include "SkiPass.h"
#include "Rental.h"
#include "Inventory.h"

class Adult;
class Human;
class SkiPass;

class Child: public Human{
private:
    string name;
    Adult* parent;
public:
    Inventory inventory;
    SkiPass* skiPass;
    Child(string name, Adult* parent);
    void getState();
};

#endif