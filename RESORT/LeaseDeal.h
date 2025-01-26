#ifndef LEASE_DEAL_H
#define LEASE_DEAL_H
#include "Adult.h"
#include "Rental.h"
class Adult;
class Rental;

class LeaseDeal{
private:
    Adult* client;
    Rental* rental;
public:
    LeaseDeal(Adult* client, Rental* rental);
    Adult* getClient();
    Rental* getRental();
    void getState();
};

#endif