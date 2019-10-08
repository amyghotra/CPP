//
//  main.cpp
//  Factorials
//
//  Created by Amy Ghotra on 10/7/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//
/*
 Program print out the factorial of the inputted number
 Program will also print out the factorials of numbers less than the input
*/

#include <iostream>
using namespace std;

int factorials(int factorial);

int main()
{
    int i;
    cin >> i;
    
    // use while loop to call the recursive function which will compute the factorials
    while (i >= 1)
    {
        cout << factorials(i) << endl;
        
        // decrement by 1!
        i--;
    }
    
    return 0;
}

// use recursuve function to find factorial of each number less then or equal to the inputted number
int factorials(int factorial)
{
    if (factorial == 0)
        return 1;
    
    return factorial * factorials(factorial - 1);
}
