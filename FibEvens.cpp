//
//  main.cpp
//  Factorials with Recursive
//
//  Created by Amy Ghotra on 10/13/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//
/*
 program will obtain two numbers -- upper and lower bound -- and
 will use them to obtain fibonacci numbers
 fib numbers are stored into a vector
 vector is then accessed to find even numbers and add them all together
*/

#include <iostream>
#include <vector>
using namespace std;

// function prototype
int fibGenerator(int fibNum);

int main()
{
    // vars to store value
    int lowerLevel; // lower bound
    int upperLevel; // upper bound
    // get and store user input
    cin >> lowerLevel;
    cin >> upperLevel;
    // vector will be used to store the fibonacci values which are generated
    vector<int> numSaver;
    // variable to hold sum of all even numbers
    int sum_even_values = 0;
    
    // store all fib values into a vector
    for (int i = lowerLevel; i <= upperLevel; i++)
    {
        numSaver.push_back(fibGenerator(i));
    }
    // go through the vector and find even numbers
    for (int i = 0; i < numSaver.size(); i++)
    {
        if (numSaver[i] % 2 == 0)
        {
            sum_even_values += numSaver[i];
        }
    }
    
    cout << "the sum of all even numbers = " << sum_even_values << endl;
    
    return 0;
}

// function to generate fib numbers
int fibGenerator(int fibNum)
{
    //cout << fibNum << endl;
    // if num <= 1 then it is not possible to add the previous two numbers
    if (fibNum <= 1) {
        return 1;
    }
    
    return fibGenerator(fibNum - 1) + fibGenerator(fibNum - 2);
}
