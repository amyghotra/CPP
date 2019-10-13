//
//  main.cpp
//  Factorials
//
//  Created by Amy Ghotra on 10/13/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//
/*
 Program will ask the user for a number
 2 will be raised to that number
 the program then takes the answer which was obtained
 and adds up all of the digits of which the number was composed
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
    int i;
    cout << "enter a power to raise to two ";
    cin >> i;
    
    // var will be used to calculate the sum of the digits from the resulting answer
    int sum = 0;
    int answer = pow(2, i);
    
    // turn into string
    string stringVersion = to_string(answer);
    
    for (int i = 0; i < stringVersion.length(); i++)
    {
        /* in order to obtain the digit, find the ascii number associated with
         the character and then subtract 48 (which is 0 in ascii)
         this gives you the difference btwn 0 and the digit, helping you
         obtain the number */
        int findingNumberUsingASCII = int(stringVersion[i]) - 48;
        sum += findingNumberUsingASCII;
    }
    
    cout << "the sum of " << answer << " is:  " << sum << endl;
    
    return 0;
}
