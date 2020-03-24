//
//  Bird.cpp
//  Bird
//
//  Created by Amy Ghotra on 2/13/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
//

#include "Bird.hpp"

// no need to type out code in order to call the default constructor of the parent class; parent class default constructor is automatically called
Bird::Bird()
{
    // default constructor
}
// call the parent's constructor which takes parameters
// the parameteres need to be initizliaed to false
Bird::Bird(std::string name, bool domestic, bool predator): Animal(name, domestic, predator), airborne_(false), aquatic_(false)
{
    // constructor which takes paramters
    // this inside can be left empty
}
// return whether the bird is airborne or not
// "const" tells the program that this method will not modify anything
bool Bird::isAirborne() const
{
    return airborne_;
}
// return whether the bird is acquatic or not
// "const" tells the program that this method will not modify anything
bool Bird::isAquatic() const
{
    return aquatic_;
}
// set airborne to true
// "const" tells the program that this method will not modify anything
void Bird::setAirborne()
{
    airborne_ = true;
}
// set aquatic to true
// "const" tells the program that this method will not modify anything
void Bird::setAquatic()
{
    aquatic_ = true;
}
