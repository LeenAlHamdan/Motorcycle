
// Created by Leen Al-Hamdan on 09/01/2021.

#ifndef MOTORCYCLE_CUSTOMER_H
#define MOTORCYCLE_CUSTOMER_H

#endif //MOTORCYCLE_CUSTOMER_H

#include <iostream>
#include <string>

class Customer
{
private:
    string surName;
    string firstName;
    int yearOfBirth;
    string telephoneNumber;
    bool hasDriveLicence;
    Address address;

public:
    //overload == operator to easily compare
    bool operator == (const Customer& c) const {
        return  surName==c.surName &&
        firstName==c.firstName &&
        yearOfBirth==c.yearOfBirth &&
        telephoneNumber==c.telephoneNumber &&
        hasDriveLicence==c.hasDriveLicence &&
        address==c.address;}

    //overload != operator to easily compare
    bool operator != (const Customer& c) const {return !operator==(c);}

    Customer()
    {
    }
    Customer(string surName, string firstName, int yearOfBirth, string telephoneNumber, bool hasDriveLicence, Address adress)
    {
        this->surName=surName;
        this->firstName=firstName;
        this->yearOfBirth=yearOfBirth;
        this->telephoneNumber=telephoneNumber;
        this->hasDriveLicence=hasDriveLicence;
        this->address=adress;
    }

    void setSurName(string surName)
    {
        this->surName=surName;
    }

    void setFirstName(string firstName)
    {
        this->firstName=firstName;
    }

    void setTelephneNumber(string telephneNumber)
    {
        this->telephoneNumber=telephneNumber;
    }

    void setYearOfBirth(int yearOfBirth)
    {
        this->yearOfBirth=yearOfBirth;
    }

    void setHasDriveLicence(bool hasDriveLicence)
    {
        this->hasDriveLicence=hasDriveLicence;
    }

    void setAdress(Address adress)
    {
        this->address=adress;
    }

    string getSurName()
    {
        return surName;
    }

    string getFirstName()
    {
        return firstName;
    }

    int getYearOfBirth()
    {
        return yearOfBirth;
    }

    string getTelephneNumber()
    {
        return telephoneNumber;
    }

    bool getHasDriveLicence()
    {
        return hasDriveLicence;
    }

    Address getAdress()
    {
        return address;
    }
};
