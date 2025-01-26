#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "InstDeal.h"
#include "Human.h"
#include "SkiPass.h"
#include <string>
using namespace std;
class InstDeal;
class SkiPass;

class Instructor: public Human{
private:
    string name;
public:
    InstDeal* instDeal;
    SkiPass* skiPass;
    Instructor(string name);
    void getState();
    void setSkiPass(SkiPass* skiPass);
};

#endif