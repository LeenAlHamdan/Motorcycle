
// Created by Leen Al-Hamdan on 09/01/2021.

#ifndef MOTORCYCLE_RECORD_H
#define MOTORCYCLE_RECORD_H

#endif //MOTORCYCLE_RECORD_H

#include <iostream>
#include <string>
#include "Motorcycle.h"

using namespace std;

class Record{
private:
    Motorcycle motorcycle;
    Customer customer;
   
public:
    //overload == operator to easily compare
    bool operator == (const Record& r) const { return  motorcycle==r.motorcycle&& customer==r.customer;}

    //overload != operator to easily compare
    bool operator != (const Record& r) const {return !operator==(r);}

    Record()
    {
    }

    Record( Motorcycle motorcycleName,Customer customer)
    {
        this->motorcycle=motorcycleName;
        motorcycle.setIsBooked(true);
        this->customer=customer;
    }

    Motorcycle getMotorcycle()  {
        return motorcycle;
    }

    void setMotorcycle(Motorcycle motorcycleName) {
        Record::motorcycle = motorcycleName;
    }

     Customer getCustomer() {
        return customer;
    }

    void setCustomer( Customer customer) {
        Record::customer = customer;
    }


};