//
//  Mammal.hpp
//  
//
//  Created by Amy Ghotra on 2/6/20.
//

#ifndef Mammal_hpp
#define Mammal_hpp
#include "Animal.hpp" // include reference to the header file of the parent class

// the class Mammal will inherit from the parent class of Animal
// the  Mammal class only has access to the public members of the Animal class-- i.e. it cannot directly access anything in the private section
class Mammal: public Animal
{
// list of private data members accessible only by the public members of this class
private:
    bool hair_;
    bool airborne_;
    bool aquatic_;
    bool toothed_;
    bool fins_;
    bool tail_;
    int legs_;
// public members that can be used to call/instantiate this class
// public members are used to modify/return the private members
public:
    // defauly constructor
    Mammal();
    // default constructor that takes parameters
    Mammal(std::string name, bool domestic = false, bool predator = false);
    
    // functions to return the value of private members
    bool hasHair() const;
    bool isAirborne() const;
    bool isAquatic() const;
    bool isToothed() const;
    bool hasFins() const;
    bool hasTail() const;
    int legs() const;
    
    // functions to change the value of the private members to true
    void setHair();
    void setAirborne();
    void setAquatic();
    void setToothed();
    void setFins();
    void setTail();
    
    // function that will set the value of the legs_ private member to the number of specified legs
    void setLegs(int legs);
};
#endif /* Mammal_hpp */
