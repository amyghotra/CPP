//
//  Animal.cpp
//  Animal
//
//  Created by Amy Ghotra on 2/6/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
// CSCI 235 PROJECT 1

#include "Animal.hpp"

Animal::Animal()
{
    // everything should at first be set to false
    name_ = "";
    predator_ = false;
    domestic_ = false;
    // default constructor
}
// constructor method
// omit default params in CPP if theyre in HPP; e.g. omit the "false" part of "bool domestic = false"
Animal::Animal(std::string name, bool domestic, bool predator)
{
    // provide values to the private members of the Animal class
    name_ = name;
    predator_ = predator;
    domestic_ = domestic;
}
// return whwther animal is domestic or not
bool Animal::isDomestic() const
{
    return domestic_;
}
std::string Animal::getName() const
{
    return name_;
}
// return whether animal is pred or not
bool Animal::isPredator() const
{
    return predator_;
}
// set the name of the animal
void Animal::setName(std::string name)
{
    name_ = name;
}
// will set domestic to true
void Animal::setDomestic()
{
    domestic_ = true;
}
// call this will set the predator to true
void Animal::setPredator()
{
    predator_ = true;
}
