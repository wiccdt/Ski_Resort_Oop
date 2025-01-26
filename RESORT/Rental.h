#ifndef RENTAL_H
#define RENTAL_H
#include <vector>
using namespace std;
#include "LeaseDeal.h"
#include "Adult.h"
#include "Inventory.h"
class Adult;
class LeaseDeal;



class Rental{
private:
    vector<LeaseDeal*> leaseDeals;
public:
    void getState();
    void giveInventory(Adult* client, bool withChild);

    void getInventory(Adult* client, bool withChild);
};

#endif