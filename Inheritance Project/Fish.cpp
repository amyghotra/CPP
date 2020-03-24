//
//  Fish.cpp
//  Fish
//
//  Created by Amy Ghotra on 2/13/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
//

#include "Fish.hpp"

// default constructor
// need to initialize the variables to false
// no need to type out code in order to call the default constructor of the parent class; parent class default constructor is automatically called
Fish::Fish(): venomous_(false)
{
    // default constructor
    // calling this also calls the defauly constructor of the parent, Animal, class
}
// constructor class which takes parameters
// calling this requires providing parameters
// all the private members of the Fish class must be initialized to false
Fish::Fish(std::string name, bool domestic, bool predator): Animal(name, domestic, predator), venomous_(false)
{
    // constructor class that takes parameters
}
// return whether the animal is venemous or not; the "const" keyword indicates that the fucntion will not modify the private data members of the Fish class
bool Fish::isVenomous() const
{
    return venomous_;
}
// calling this will set venomous to true
void Fish::setVenomous()
{
    venomous_ = true;
}
