#include <string>
#include <iostream>
using namespace std;
#include "Registry.h"
#include "Rental.h"
#include "InstService.h"

SkiResort::SkiResort(string name, Registry* registry, Rental* rental, InstService* instService){
    this->name = name;
    this->registry = registry;
    this->rental = rental;
    this->instService = instService;
    cout << "Ski resort " << name << " initialized" << endl;
}
string SkiResort::getName(){
    return name;
}
void SkiResort::getRegistryReport(){
    registry->getState();
    cout << endl;
}
void SkiResort::getRentalReport(){
    rental->getState();
    cout << endl;
}
void SkiResort::getInstServiceReport(){
    instService->getState();
    cout << endl;
}
void SkiResort::getState(){
    SkiResort::getRegistryReport();
    SkiResort::getRentalReport();
    SkiResort::getInstServiceReport();
}

