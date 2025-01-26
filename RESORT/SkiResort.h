#ifndef SKI_RESORT_H
#define SKI_RESORT_H
#include <string>
using namespace std;
#include "Registry.h"
#include "Rental.h"
#include "InstService.h"

class Registry;
class Rental;
class InstService;

class SkiResort{
public:
    string name;
    Registry* registry;
    Rental* rental;
    InstService* instService;
    SkiResort(string name, Registry* registry, Rental* rental, InstService* instService);
    string getName();
    void getRegistryReport();
    void getRentalReport();
    void getInstServiceReport();
    void getState();
};

#endif