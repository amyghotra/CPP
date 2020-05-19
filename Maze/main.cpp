#include "Solutions.cpp"
using namespace std;
#include <vector>

int main()
{
    // create 3 maze to pass into functions
    // read cvs files
    Maze someMaze1("maze_1.csv");
    Maze someMaze2("maze_2.csv");
    Maze someMaze3("maze_3.csv");

    // vector<MazeNode> first = solutions::solveDFS(someMaze2);

    // for (int i = 0; i < first.size(); i++)
    // {
    //     cout << first[i] << endl;
    // }

    vector<MazeNode> second = solutions::solveDEF(someMaze1);

    for (int i = 0; i < second.size(); i++)
    {
        cout << second[i] << endl;
    }
    

    return 0;
}