//
//  Bird.hpp
//  Bird
//
//  Created by Amy Ghotra on 2/13/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
//

#ifndef Bird_hpp
#define Bird_hpp
#include <string>
#include "Animal.hpp" // include reference to the parent class header file

// the class Bird will inherit from the parent class of Animal
// the Bird class only has access to the public members of the Animal class-- i.e. it cannot directly access anything in the private section
class Bird: public Animal
{
// list of private members
// accessible only by the public members of the class
private:
    bool airborne_;
    bool aquatic_;
// list of public members
// will be used to invoke the class/create an instance, or to edit/call the private members
public:
    Bird();
    Bird(std::string name, bool domestic = false, bool predator = false);
    bool isAirborne() const;
    bool isAquatic() const;
    void setAirborne();
    void setAquatic();
};


#endif /* Bird_hpp */
