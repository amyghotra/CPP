#include "Field.h"
#include <iostream>

/*
parameterized copy constructor
*/
Field::Field(const std::vector<std::vector<int>>& userInput): myVector(userInput)
{
    // resize the vector that will hold the sums
    sumAt.resize(myVector.size());
    for(int i = 0; i < myVector.size(); i++)
    {
        sumAt[i].resize(myVector[0].size());
    }
    // add the very first element
    sumAt[0][0] = myVector[0][0];

    // sum of all elems in first (0th) row
    // sum (0,0) --> (0,i)
    for(int i = 1; i < myVector[0].size(); i++)
    {
        sumAt[0][i] = sumAt[0][i-1] + myVector[0][i];
    }

    // sum of all elems in first (0th) column
    // sum (0,0) --> (i,0)
    for(int i = 1; i < myVector.size(); i++)
    {
        sumAt[i][0] = sumAt[i - 1][0] + myVector[i][0];
    }
    // get the rest of the sums
    for(int i = 1; i < myVector.size(); i++)
    {
        for(int j = 1; j < myVector[0].size(); j++)
        {
            sumAt[i][j] = myVector[i][j] + sumAt[i-1][j] + sumAt[i][j-1] - sumAt[i-1][j-1];
        }
    }

}

/*
parameterized move constructor
*/
Field::Field(std::vector<std::vector<int>>&& userInput):myVector(std::move(userInput))
{
    // resize the vector that will hold all of the sums
    sumAt.resize(myVector.size());
    for(int i = 0; i < myVector.size(); i++)
    {
        sumAt[i].resize(myVector[0].size());
    }
    // set the first value
    sumAt[0][0] = myVector[0][0];

    // sum of all elems in first (0th) row
    // sum (0,0) --> (0,i)
    for(int i = 1; i < myVector[0].size(); i++)
    {
        sumAt[0][i] = sumAt[0][i-1] + myVector[0][i];
    }

    // sum of all elems in first (0th) column
    // sum (0,0) --> (i,0)
    for(int i = 1; i < myVector.size(); i++)
    {
        sumAt[i][0] = sumAt[i - 1][0] + myVector[i][0];
    }

    // adding up the rest of the elements
    for(int i = 1; i < myVector.size(); i++)
    {
        for(int j = 1; j < myVector[0].size(); j++)
        {
            sumAt[i][j] = myVector[i][j] + sumAt[i-1][j] + sumAt[i][j-1] - sumAt[i-1][j-1];
        }
    }
}

/*
Weight function: gets the sum of all the values between two points
*/
int Field::Weight(int x1,  int y1,  int x2,  int y2) const
{
    // changing the variables to account for how the assignment is supposed to be done
    int first__x = x1;
    x1 = y1;
    y1 = first__x;

    int second__x = x2;
    x2 = y2;
    y2 = second__x;

    // validate input
    if((x1 < 0) || (x2 < 0) || (y1 < 0) || (y2 < 0) || (x1 >= myVector.size()) || (x2 >= myVector.size()) || (y1 >= myVector[0].size()) || (y2 >= myVector[0].size()))
    {
        return 0;
    }
    // if user wants value at one square
    if((x1 == x2) && (y1 == y2))
    {
        return myVector[x1][y1];
    }

    // int to hold total
    int total = 0;

    // (1,4)(3,2) --> swap y vals --> (1,2) (3,4)
    // (0,4)(0,2) --> swap y vals --> (0,2) (0,4)
    if((x1 <= x2) && (y2 < y1))
    {
        int temp = y1;
        y1 = y2;
        y2  = temp;
    }
    // (3,4) (1,2) --> (1,2) (2,3)
    else if((x1 > x2) && (y1 > y2))
    {
        int temp_x1 = x1;
        int temp_y1 = y1;
        x1 = x2;
        y1 = y2;
        x2 = temp_x1;
        y2 = temp_y1;
    }
    // (4,1)(3,6) --> swap x vals --> (3,1) (4,6)
    else if((x1 > x2) && (y1 <= y2))
    {
        int temp_x = x1;
        x1 = x2;
        x2 = temp_x;
    }
    // make sure the smaller coordinate values are not 0
    if((x1 > 0) && (y1 > 0))
    {
        total = sumAt[x2][y2] - sumAt[x1 - 1][y2] - sumAt[x2][y1 - 1] + sumAt[x1 - 1][y1 - 1];
        return total;
    }
    // if the smaller x value = 0
    else if((x1 == 0) && (y1 > 0))
    {
        total = sumAt[x2][y2] - sumAt[x2][y1 - 1];
        return total;
    }
    // if the smaller y value = 0
    else if((x1 > 0) && (y1 == 0))
    {
        total = sumAt[x2][y2] - sumAt[x1 - 1][y2];
        return total;
    }
    // if the smaller coordinate is the very first coordinate
    else if((x1 == 0) && (y1 == 0))
    {
        
        total = sumAt[x2][y2];
        return total;
    }

    return total;
}

/*
find the cheapest cost of getting from (0,0) --> (n-1, n-1) where n is the length and width of the vector
*/
int Field::PathCost() const
{
    // edge cases
    if(myVector.size() == 0)
    {
        return 0;
    }
    if(myVector.size() == 1)
    {
        if(myVector[0].size() == 1)
        {
            return myVector[0][0];
            int sum = 0;
            for(int i = 0; i < myVector[0].size(); i++)
            {
                sum+= myVector[0][i];
            }
            return sum;
        }
    }

    // 2d vector to hold the final cost
    std::vector<std::vector<int>> cost;
    // resize the vector so that it is the same size as myVector
    cost.resize(myVector.size());
    for(int i = 0; i < myVector.size(); i++)
    {
        cost[i].resize(myVector[i].size());
    }
    // initial cost is the cost at the very first square (starting point)
    cost[0][0] = myVector[0][0];

    // loop through rows
    for(int i = 0; i < myVector.size(); i++)
    {
        // loop through elements of vector
        for(int j = 0; j < myVector[i].size(); j++)
        {
            // if the row and column are not 0 (i.e. there are other rows and columns around them)
            if((i > 0) && (j > 0))
            {
                // the cost is the cost at the current square...
                cost[i][j] = myVector[i][j];
                // ... added to the previous minimum cost
                cost[i][j] += std::min(cost[i][j-1], cost[i-1][j]);
            }
            // if the row is the top most row but the column is not the left most column
            else if((i == 0) && (j > 0))
            {
                // get the cost at the current index
                cost[i][j] = myVector[i][j];
                // add it to the last accessible/appropriate elem (one that is immediately left)
                cost[i][j] += cost[i][j-1];
            }
            // if the column is the left most column but the row is not the top most row
            else if((i > 0) && (j == 0))
            {
                // get the cost at the current index
                cost[i][j] = myVector[i][j];
                // add it to the cost of the last accessible/appropriate element 
                // (i.e. add it to the elem one row up)
                cost[i][j] += cost[i - 1][j];
            }
        }
    }

    // get the final cost, which is the very last element of the vector
    int finalCost = cost[cost.size() - 1][cost[0].size() - 1];

    // return the cost
    return finalCost;
}
