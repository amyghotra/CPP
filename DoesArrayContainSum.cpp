//
//  main.cpp
//  DoesArrayContainSum
//
//  Created by Amy Ghotra on 10/7/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//
/*
 
 The program will go through the array to determine if two numbers from the given array
 can be added together to get a certain target sum
 The program will first try to add the first element to the last one
 If the two numbers != targetSum because the sum is higher than the target sum,
 the program will add the first number to the number preceeding the final one
 If again that number is higher, it will take add the first number to the one preceeding the other number
 If the number is lower than the sum, the counter is reset and the number following the first one is added
 to the final number. If that one is less than the sum, the number following the smaller number is added to the final one
This goes on until all elements are parsed
 
*/


#include <iostream>
using namespace std;

int main()
{
    int array[] = {1,5,2,4};
    
    // var to hold sum; is initially set to the first element added to the last element
    int sum = array[0] + array[sizeof(*array) - 1];
    
    // we want to see if two elements from the array can add up to this
    int targetSum = 8;
    
    // counter for numbers going from left to right
    int counter = 0;
    
    // another counter for numbers going from right to left
    int secondCounter = sizeof(*array);
    
    // if the of two numbers is greater than the target sum
    while (sum > targetSum)
    {
        // ensure counter is set to 0
        counter = 0;
        // the first number should be added to the number preceeding the current one on the right side
        secondCounter -= 1;
        // update sum
        sum = array[counter] + array[secondCounter];
    }
    
    // if the sum is less than the target sum
    while (sum < targetSum)
    {
        // the final number should be added to the one following the current one on the left side
        counter += 1;
        // secondCounter is reset to equal the last element
        secondCounter = sizeof(*array) - 1;
        // update sum
        sum = array[counter] + array[secondCounter];
    }
    
    // if two numbers added together gets us the target sum
    if (sum == targetSum) {
        cout << "success" << endl;
        
    }
    else
    {
        cout << "no two numbers in the given array add up to " << targetSum << endl;
    }
    
    return 0;
}
