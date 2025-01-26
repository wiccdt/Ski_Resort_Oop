#include <vector>
#include "Rental.h"
#include <iostream>
using namespace std;
#include "LeaseDeal.h"
#include "Adult.h"
#include "Inventory.h"




void Rental::getState(){
    cout << "Rental (active lease deals): ";
    for(int i = 0; i < leaseDeals.size();i++){
        if(leaseDeals.empty()){
            cout << "0" << endl;
            return;
        }
        leaseDeals[i]->getState();
        cout << ", ";
    }
    cout << endl;
}
void Rental::giveInventory(Adult* client, bool withChild){
    srand(time(0));

    LeaseDeal* deal = new LeaseDeal(client, this);
    leaseDeals.push_back(deal);
    client->leaseDeal = deal;

    Inventory inventory = static_cast<Inventory>(rand() % 2 + 1);
    client->inventory = inventory;
    if(withChild){
        inventory = static_cast<Inventory>(rand() % 2 + 3);
        client->getChild()->inventory = inventory;
    }
    client->setDeposit(false);
    cout << client->getName() << " - got inventory" << endl;
}

void Rental::getInventory(Adult* client, bool withChild){
    for(int i = 0; i < leaseDeals.size(); i++){
        if(leaseDeals[i] == client->leaseDeal){
            leaseDeals.erase(leaseDeals.begin() + i);
            break;
        }
    }
    client->leaseDeal = nullptr;
    client->setDeposit(true);
    client->inventory = NO_INVENTORY;
    if(withChild){
        client->getChild()->inventory = NO_INVENTORY;
    }
    cout << client->getName() << " - returned inventory" << endl;
}

