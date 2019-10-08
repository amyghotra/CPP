//
//  main.cpp
//  Factorials with Recursive
//
//  Created by Amy Ghotra on 10/7/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
// program simply prints out facorial of given number using recursive formula

#include <iostream>
using namespace std;

int factorials(int factorial);

int main()
{
    // var to store value
    int someNumber;
    
    // get number value from user
    cin >> someNumber;
    
    // call recursive function and print out result
    cout << factorials(someNumber) << endl;
    
    return 0;
}

int factorials(int factorial)
{
    // if factorials == 0 simply return 1
    if (factorial == 0)
        return 1;
    
    // otherwise keep calling this function using currentNumber - 1
    return factorial * factorials(factorial - 1);
}
