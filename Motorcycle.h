
// Created by Leen Al-Hamdan on 09/01/2021.

#ifndef MOTORCYCLE_MOTORCYCLE_H
#define MOTORCYCLE_MOTORCYCLE_H

#endif //MOTORCYCLE_MOTORCYCLE_H

#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

class Motorcycle{
private:
    string motorcycleName;
    bool isBooked;

public:
    //overload == operator to easily compare
    bool operator == (const Motorcycle& m) const { return  isBooked==m.isBooked && motorcycleName==m.motorcycleName;}

    //overload != operator to easily compare
    bool operator != (const Motorcycle& m) const {return !operator==(m);}

    Motorcycle()
    {
    }

    Motorcycle( string motorcycleName, bool isBooked)
    {
        this->motorcycleName=motorcycleName;
        this->isBooked=isBooked;
    }

    string getMotorcycleName()  {
        return motorcycleName;
    }

    void setMotorcycleName( string motorcycleName) {
        this->motorcycleName = motorcycleName;
    }

    bool isBooked1()  {
        return isBooked;
    }

    void setIsBooked(bool isBooked) {
        this->isBooked = isBooked;
    }


};