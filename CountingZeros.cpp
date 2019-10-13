//
//  main.cpp
//  CountingZeros
//
//  Created by Amy Ghotra on 10/12/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//


/*
 This program will ask the user for a number
 the program will then compute the factorial of the inputted number
 the program converts the final number into a string in order to determine
 how many zeros are in it
*/


#include <iostream>
#include <string>
using namespace std;

//program to determine how many trailing 0s there are after a factorial
int factorials(int factorial);

int main()
{
    // var to store value
    int someNumber;
    cout << "say something\n";
    // get number value from user
    cin >> someNumber;
    
    // call recursive function and store its value in an integer
    int finalAnswer = factorials(someNumber);
    // convert integer into string
    string answerInString = to_string(finalAnswer);
    
    // create a counter to keep track of how mant zeros are in the string
    int counter = 0;
    // create for loop to read through the string
    for (int i = 0; i < answerInString.length(); i++)
    {
        if (answerInString[i] == '0')
        {
            counter++;
        }
    }
    
    if (counter == 0)
    {
        cout << "no zeros" << endl;
    }
    if (counter == 1)
    {
        cout << "1 zero" << endl;
    }
    if (counter > 1)
    {
        cout << counter << " amount of zeros" << endl;
    }
    
    return 0;
}

// recursive function to calculate factorial
int factorials(int factorial)
{
    
    // NEW REPLACEMENT
    if (factorial == 1) {
        return factorial;
    }
    
    // otherwise keep calling this function using currentNumber - 1
    return factorial * factorials(factorial - 1);
}
