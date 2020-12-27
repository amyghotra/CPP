#pragma once
#include <vector>

class Field
{
private:
    // actual vector with the 2d user input
    std::vector<std::vector<int>> myVector;

    // vector that holds sums up to a certain point
    std::vector<std::vector<int>> sumAt;
public:
    // parameterized copy constructor
    Field(const std::vector<std::vector<int>>& userInput);
    // parameterized move constructor
    Field(std::vector<std::vector<int>>&& userInput);
    // cost from (0,0) to (n-1, n-1) where n is the size of the length and width
    int PathCost() const;
    // total sum of given rectangle
    int Weight(int x1, int y1, int x2, int y2) const;
};
