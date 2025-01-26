#include "Adult.h"
#include "Rental.h"
#include <iostream>
LeaseDeal::LeaseDeal(Adult* client, Rental* rental){
    this->client = client;
    this->rental = rental;
}
Adult* LeaseDeal::getClient(){
    return client;
}
Rental* LeaseDeal::getRental(){
    return rental;
}
void LeaseDeal::getState(){
    cout << "deal with " << client->getName();
}
