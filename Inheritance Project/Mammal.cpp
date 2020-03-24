//
//  Mammal.cpp
//  
//
//  Created by Amy Ghotra on 2/6/20.
//

#include "Mammal.hpp"

// default constructor method
// no need to type out code in order to call the default constructor of the parent class; parent class default constructor is automatically called
Mammal::Mammal(): hair_(false), airborne_(false), aquatic_(false), toothed_(false), tail_(false), fins_(false), legs_(0)
{
    // constructor which takes paramters
    // this inside can be left empty
}

/* call the parent's constructor which takes parameters
    the parameteres need to be initizliaed to false
  no need to set domestic and predator equal to false because this was already done so in the header file*/
Mammal::Mammal(std::string name, bool domestic, bool predator): Animal(name, domestic, predator), hair_(false), airborne_(false), aquatic_(false), toothed_(false), tail_(false), fins_(false), legs_(0)
{
    // constructor that takes parameters
}
// return whether the animal has hair or not
// const indicates that this function will not modify any of the private data members
bool Mammal::hasHair() const
{
    return hair_;
}
// return whether the animal is airborne not
// const indicates that this function will not modify any of the private data members
bool Mammal::isAirborne() const
{
    return airborne_;
}
// return whether the animal is aquatic or not
// const indicates that this function will not modify any of the private data members
bool Mammal::isAquatic() const
{
    return aquatic_;
}
// return whether the animal it toothes or not
// const indicates that this function will not modify any of the private data members
bool Mammal::isToothed() const
{
    return toothed_;
}
// return whether the animal has fins or not
// const indicates that this function will not modify any of the private data members
bool Mammal::hasFins() const
{
    return fins_;
}

// return whether the animal has a tail or not
// const indicates that this function will not modify any of the private data members
bool Mammal::hasTail() const
{
    return tail_;
}
// return the number of legs the animal has
// const indicates that this function will not modify any of the private data members
int Mammal::legs() const
{
    return legs_;
}
// will set priv membr hair_ equal to true
void Mammal::setHair()
{
    hair_ = true;
}

// will set private member airborne_ equal to true
void Mammal::setAirborne()
{
    airborne_ = true;
}

// will set priv member toothed_ equal to true
void Mammal::setToothed()
{
    toothed_ = true;
}

// will set private data meber fins_ equal to true
void Mammal::setFins()
{
    fins_ = true;
}

// will set tail_ equal to true
void Mammal::setTail()
{
    tail_ = true;
}

// will set legs_ equal to the number of legs specified
void Mammal::setLegs(int legs)
{
    legs_ = legs;
}
