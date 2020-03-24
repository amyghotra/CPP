//
//  main.cpp
//  
//
//  Created by Amy Ghotra on 2/13/20.
//

#include "main.hpp"
#include <iostream>
#include "Fish.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Animal.hpp"
using namespace std;

int main()
{
//    Mammal cat;
//    cat.setName("Kitty");
//    cout << cat.getName() << " " << cat.hasHair() << cat.isAirborne() << cat.isAquatic() << cat.isToothed() << cat.hasFins() << cat.hasTail() << cat.legs();
    
    Bird parakeet;
    cout << parakeet.isAirborne() << parakeet.isAquatic();
    
    return 0;
}
