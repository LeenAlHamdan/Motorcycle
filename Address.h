
// Created by Leen Al-Hamdan on 09/01/2021.

#ifndef MOTORCYCLE_ADDRESS_H
#define MOTORCYCLE_ADDRESS_H

#endif //MOTORCYCLE_ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address{
private:
    string street;
    int number;
    string city;
    long postcode;
public:
    //overload == operator to easily compare
    bool operator == (const Address& a) const {
        return  street==a.street &&
                number==a.number &&
                city==a.city &&
                postcode==a.postcode;}

    //overload != operator to easily compare
    bool operator != (const Address& a) const {return !operator==(a) ;}
    Address()
    {
    }
    Address(string street, int number, string city, long postcode)
    {
        this->street=street;
        this->number=number;
        this->city=city;
        this->postcode=postcode;
    }

     string getStreet()  {
        return street;
    }

    void setStreet( string street) {
        Address::street = street;
    }

    int getNumber()  {
        return number;
    }

    void setNumber(int number) {
        Address::number = number;
    }

     string getCity()  {
        return city;
    }

    void setCity( string city) {
        Address::city = city;
    }

    long getPostcode()  {
        return postcode;
    }

    void setPostcode(long postcode) {
        Address::postcode = postcode;
    }
};