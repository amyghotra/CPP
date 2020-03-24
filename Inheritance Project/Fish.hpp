//
//  Fish.hpp
//  Fish
//
//  Created by Amy Ghotra on 2/13/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
//

#ifndef Fish_hpp
#define Fish_hpp
#include "Animal.hpp"

// the class Fish will inherit from the parent class of Animal
// the Fish class only has access to the public members of the Animal class-- i.e. it cannot directly access anything in the private section
class Fish: public Animal
{
// list of private data members that cannot be accessed in any other way than through the public members of the class
private:
    bool venomous_;
// list of public members that can be used to modify/return the value of the private data members
public:
    Fish(); // default constructor
    
    // default constructor that takes parameters; invoking this will invoke the parent constructor which also takes parameters
    Fish(std::string name, bool domestic = false, bool predator = false);
    // will return whether the animal is venomous or not
    // const indicates that the function will not change anything
    bool isVenomous() const;
    // will set private data member venomous_ to true
    void setVenomous();
};


#endif /* Fish_hpp */
