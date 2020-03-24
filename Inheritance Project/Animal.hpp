//
//  Animal.hpp
//  Animal
//
//  Created by Amy Ghotra on 2/6/20.
//  Copyright © 2020 Amy Ghotra. All rights reserved.
// CSCI 235 PROJECT 1

#ifndef Animal_hpp
#define Animal_hpp
#include <string>

// create class of Animal
class Animal
{
// private members
private:
    std::string name_;
    bool predator_;
    bool domestic_;
// public members
public:
    Animal(); // default constructor method
    // constructor method
    Animal(std::string name, bool domestic = false, bool predator = false);
    // method to return the name of the animal
    std::string getName() const;
    // method to determine of animal is domestic
    bool isDomestic() const;
    // method to determine of animal is predator
    bool isPredator() const;
    // meothod to set the name
    void setName(std::string name);
    void setDomestic();
    void setPredator();
 
};

#endif /* Animal_hpp */
