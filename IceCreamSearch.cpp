//
//  main.cpp
//  IceCreamSearch
//
//  Created by Amy Ghotra on 10/14/19.
//  Copyright © 2019 Amy Ghotra. All rights reserved.
//
/*
 program will take a target price and try to find what flavor(s) of ice cream you can get
*/

#include <iostream>
#include <vector>
using namespace std;

// function prototype
vector<int> getFlavors(string flavors[], int price[], int targetPrice);

int main()
{
    // list of possible ice cream flavors
    string flavors[] = {"strawberry","blueberry","nutella","vanilla","banana", "bubblegum","chocolate", "rice"};
    // list of prices corresponding to list of flavors
    int price[] = {2,7,13,5,4,13,5,4};
    //int price[] = {2,7,13,5,4,13,5,4};
    // max you are able to spend
    int targetPrice = 10;
    
    vector<int> results = getFlavors(flavors, price, targetPrice);
    if (results.size() == 2) {
        cout << "with $" << targetPrice << " you can get: " << flavors[results[0]] << " and " << flavors[results[1]] << endl;
    }
    if (results.size() == 1)
    {
        cout << "with $" << targetPrice << " you can get: " << flavors[results[0]] << endl;
    }
    
    return 0;
}

vector<int> getFlavors(string flavors[], int price[], int targetPrice)
{
    vector<int> numbers;
    
    int counter = 0;
    int currentSum = price[counter] + price[sizeof(*price) - 1];
    int firstSave = -1;
    int secondSave = -1;
    
    // determine if there is an element in the array which fulfills/equals the target price
    for (int i = 0; i < sizeof(price); i++)
    {
        if (price[i] == targetPrice)
        {
            numbers.push_back(i);
            return numbers;
        }
    }
    
    // if not then...
    if (sizeof(flavors) % 2 != 0) {
        int firstHalf = (sizeof(flavors)/2) + 1;
        for (int i = 0; i < firstHalf; i++)
        {
            currentSum = price[i] + price[i+3];
            if (currentSum == targetPrice)
            {
                firstSave = i;
                secondSave = i+3;
            }
        }
    }
    if (sizeof(flavors) % 2 == 0) {
        int firstHalf = (sizeof(flavors)/2);
        for (int i = 0; i < firstHalf; i++)
        {
            currentSum = price[i] + price[i+3];
            if (currentSum == targetPrice)
            {
                firstSave = i;
                secondSave = i+3;
            }
        }
    }
    
    numbers.push_back(firstSave);
    numbers.push_back(secondSave);
    
    return numbers;
}
