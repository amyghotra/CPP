#include "Maze.cpp" // maze.cpp
#include <vector>
#include <queue>
#include <map>

using namespace std;

namespace solutions
{

int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

bool canTravel(MazeNode *a_node)
{
    if (a_node == nullptr || a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

// helper function that returns the number of traversable neighbors a node has
int numberNeighbors(MazeNode *a_maze)
{
    // start off at 0
    int numNeighbors = 0;

    // check to see if the noed can travel in a certain direction
    if (canTravel(a_maze->getDirectionNode(directions::NORTH)))
    {
        // increment if the current direction has a node to which the current node can travel to
        numNeighbors++;
    }
    // check to see if the noed can travel in a certain direction
    if (canTravel(a_maze->getDirectionNode(directions::EAST)))
    {
        // increment if the current direction has a node to which the current node can travel to
        numNeighbors++;
    }
    // check to see if the noed can travel in a certain direction
    if (canTravel(a_maze->getDirectionNode(directions::SOUTH)))
    {
        // increment if the current direction has a node to which the current node can travel to
        numNeighbors++;
    }
    // check to see if the noed can travel in a certain direction
    if (canTravel(a_maze->getDirectionNode(directions::WEST)))
    {
        // increment if the current direction has a node to which the current node can travel to
        numNeighbors++;
    }

    // return the number of neighbors a node has
    return numNeighbors;
}

std::vector<MazeNode> solveDFS(Maze &a_maze)
{
    // set the first node equal to visited so that it is not visited again (avoid infinite loop)
    a_maze.getFirstNode()->setVisited();
    // stack for holding unvisited nodes
    std::vector<MazeNode> finalPath; 
    // add the first node to the finalPath (the starting point)
    finalPath.push_back((*a_maze.getCurrentNode()));

    // while the node is not equal to the final node 
    while (a_maze.getCurrentNode() != a_maze.getLastNode()) 
    {
        // if the node can travel to neighbors
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)))
        {
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH));
            // set the new node to visited
            a_maze.getCurrentNode()->setVisited(); 
            // add the node to the stack holding the final path to the final node
            finalPath.push_back(*(a_maze.getCurrentNode()));
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::EAST)))
        {
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::EAST));
            // set the new node to visited 
            a_maze.getCurrentNode()->setVisited(); 
            // add the node to the stack holding the final path to the final node
            finalPath.push_back(*(a_maze.getCurrentNode()));
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)))
        {
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH));
            // set the new node to visited 
            a_maze.getCurrentNode()->setVisited(); 
            // add the node to the stack holding the final path to the final node
            finalPath.push_back(*(a_maze.getCurrentNode()));
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::WEST)))
        {
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::WEST));
            // set the new node to visited 
            a_maze.getCurrentNode()->setVisited(); 
            // add the node to the stack holding the final path to the final node
            finalPath.push_back(*(a_maze.getCurrentNode()));
        } // end if

        // if the node cannot travel any further it needs to backtrack because it is at a dead end
        else
        {
            // set a wall
            a_maze.getCurrentNode()->setWall();
            // move to the previous node
            finalPath.pop_back();
            // set the current node equal to the node visited right before the current one (backtrack)
            a_maze.setCurrentNode(&(finalPath.back()));
            
        } // end else
        
    } // end while
    
    // return the vector holding the path from the first node to the last one
    return finalPath;
} // end DFS

std::vector<MazeNode> solveBFS(Maze &a_maze)
{
    // queue of vectors
    std::queue<MazeNode> nodes;

    // add the first/sart node to the queue and stacks
    nodes.push(*(a_maze.getCurrentNode()));

    // set the current node equal to visited to avoid any loops
    a_maze.getFirstNode()->setVisited();

    // stack to help reconstruct the shortest path from the first node to the last node
    // vector of node pairs: first node is the current node, second is the parent (child, parent)
    std::vector<pair<MazeNode ,MazeNode> > parentTracker;

    // vector to hold the final path
    // will be reversed beacause will start from last node and find way back
    vector<MazeNode> finalPathReverse;

    // hold the actual path from the first node to the last node
    vector<MazeNode> finalPath;

    // bool to determine if the last node has been found yet
    bool lastFound = false;
    
    // get neighbors, add them to the queue, and remove the first item when neighbors are retrieved
    while (!lastFound)
    {
        // set the current node equal to the first node in the queue
        a_maze.setCurrentNode(&(nodes.front()));
        // remove the first node from the queue (dequeue)
        nodes.pop();

        // check to see if the node can travel in a given direction
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)))
        {
            // mark the node as visited
            a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)->setVisited();
            // add it to the queue
            nodes.push(*(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)));
            // make and add a (child,parent) pair to the vector of pairs
            parentTracker.push_back(std::make_pair(*a_maze.getCurrentNode()->getDirectionNode(directions::NORTH), *a_maze.getCurrentNode()));
            
            // if the current node that's just been found == lastNode of the maze
            if (a_maze.getCurrentNode()->getDirectionNode(directions::NORTH) == (a_maze.getLastNode()))
            {
                // set the bool equal to true to break out of the while loop
                lastFound = true;
            } // end if
            
        } // end if
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::EAST)))
        {
            // mark the node as visited
            a_maze.getCurrentNode()->getDirectionNode(directions::EAST)->setVisited();
            // add it to the queue
            nodes.push(*(a_maze.getCurrentNode()->getDirectionNode(directions::EAST)));
            // make and add a (child,parent) pair to the vector of pairs
            parentTracker.push_back(std::make_pair(*a_maze.getCurrentNode()->getDirectionNode(directions::EAST), *a_maze.getCurrentNode()));
            // if the current node that's just been found == lastNode of the maze
            if (a_maze.getCurrentNode()->getDirectionNode(directions::EAST) == a_maze.getLastNode())
            {
                // set the bool equal to true to break out of the while loop
                lastFound = true;
            } // end if 

        } // end if
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)))
        {
            // mark the node as visited
            a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)->setVisited();
            // add it to the queue
            nodes.push(*(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)));
            
            // make and add a (child,parent) pair to the vector of pairs
            parentTracker.push_back(std::make_pair(*a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH), *a_maze.getCurrentNode()));
            // if the current node that's just been found == lastNode of the maze
            if (a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH) == a_maze.getLastNode())
            {
                // set the bool equal to true to break out of the while loop
                lastFound = true;
            } // end if 

        } // end if
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::WEST)))
        {
            // mark the node as visited
            a_maze.getCurrentNode()->getDirectionNode(directions::WEST)->setVisited();
            // add it to the queue
            nodes.push(*(a_maze.getCurrentNode()->getDirectionNode(directions::WEST)));
            
            
            // for that position in the parent tracker list, add the position of the parent node
            parentTracker.push_back(std::make_pair(*a_maze.getCurrentNode()->getDirectionNode(directions::WEST), *a_maze.getCurrentNode()));
            
            // if the current node that's just been found == lastNode of the maze
            if (a_maze.getCurrentNode()->getDirectionNode(directions::WEST) == a_maze.getLastNode())
            {
                // set the bool equal to true to break out of the while loop
                lastFound = true;
            } // end if

        } // end if

    } // end while

    // set the current node equal to the last node
    a_maze.setCurrentNode(a_maze.getLastNode());

    // create var that will be used to iterate through the vector of pairs
    int i = parentTracker.size() - 1;

    // while loop to go through vector of pairs and find a path from first to last 
    while ((i >= 0) )
    {
        // if the child of the current pair is equal to the current node
        if (parentTracker[i].first.getStrPos() == a_maze.getCurrentNode()->getStrPos())
        {
            // add the parent to the finalPath
            finalPathReverse.push_back(parentTracker[i].second);
            // set the current node equal to the parent
            a_maze.setCurrentNode(&(parentTracker[i].second));

        } // end if

        // decrement
        i--;
    } // end while

    // while loop starts from the last node and makes its way to the first 
    // loop matches the current node to the first element of some pair
    // if the first element of some pair is equal to the current node,
    // the current node will be set to the parent of that node, and now the parent is the child

    // for loop to reverse the path found using finalPathReverse
    for (int j = finalPathReverse.size() - 1; j >= 0; j--)
    {
        // add elements of the reversed vector into the normal vector
        finalPath.push_back(finalPathReverse[j]);
    }

    // add the final node
    finalPath.push_back(*(a_maze.getLastNode()));

    // return the path holding the route from the first  node to the last
    return finalPath;

} // end BFS

std::vector<MazeNode> solveDEF(Maze &a_maze)
{
    // store the nodes leading to the final path
    std::vector<MazeNode> finalPath;

    // store the nodes that fill up the dead ends
    std::vector<MazeNode> deadEnds;

    vector<MazeNode> allNodes = a_maze.getNodes();

    vector<MazeNode> anotherVector;

    // use a for loop to get all of the dead ends and put them in stack
    for (int i = 0; i < allNodes.size(); i++)
    {
        // set the current node equal to the node in the maze that is currently being looked at
        a_maze.setCurrentNode(&allNodes[i]);

        // make sure that the current node is not a wall or null
        if (!a_maze.getCurrentNode()->isWall() && (a_maze.getCurrentNode() != nullptr))
        {
            // make sure that the current node is not equal to the first or last nodes
            // want to make sure if this^ so that first/last nodes are not marked as dead ends
            if ((a_maze.getCurrentNode()->getStrPos() != a_maze.getFirstNode()->getStrPos()) && (a_maze.getCurrentNode()->getStrPos() != a_maze.getLastNode()->getStrPos()))
            {
                // get how many neighbors the current node has
                int numNeighbors = numberNeighbors(a_maze.getCurrentNode());

                // if it only has 1 neighbor it's a dead end
                if (numNeighbors == 1)
                {
                    // add it to the vector with the dead ends
                    deadEnds.push_back(*a_maze.getCurrentNode());
                }

            } // end if

        } // end if

    } // end for

    // create a new variable that will hold the number of neighbors each node will have
    int neighbors = 0;

    // traverse through the vector holding the dead ends
    for (int i = 0; i < deadEnds.size(); i++)
    {
        // set the current node equal to a dead node
        a_maze.setCurrentNode(&deadEnds[i]);

        // get the number of neighbors
        neighbors = numberNeighbors(a_maze.getCurrentNode());

        // while it current node only has one neighbor
        while (neighbors == 1)
        {
            // check to see if it can go over to one of its neighbors
            if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)))
            {
                // set the current node equal to the neighboring node
                a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH));
                // set a wall at what was previously the current node so that it is not visited again
                a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)->setWall();
                // get the number of neighbors the new current node has
                neighbors = numberNeighbors(a_maze.getCurrentNode());
            } // end if
            else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::EAST)))
            {
                // set the current node equal to the neighboring node
                a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::EAST));
                // set a wall at what was previously the current node so that it is not visited again
                a_maze.getCurrentNode()->getDirectionNode(directions::WEST)->setWall();
                //std::cout << "else if statement 1 the current node is: " << a_maze.getCurrentNode()->getStrPos() << std::endl;
                neighbors = numberNeighbors(a_maze.getCurrentNode());
                //std::cout << neighbors << std::endl;
            } // end else if
            else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)))
            {
                // set the current node equal to the neighboring node
                a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH));
                // set a wall at what was previously the current node so that it is not visited again
                a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)->setWall();
                //std::cout << "else if statement 2 the current node is: " << a_maze.getCurrentNode()->getStrPos() << std::endl;
                neighbors = numberNeighbors(a_maze.getCurrentNode());
                //std::cout << neighbors << std::endl;
            } // end else if
            else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::WEST)))
            {
                // set the current node equal to the neighboring node
                a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::WEST));
                // set a wall at what was previously the current node so that it is not visited again
                a_maze.getCurrentNode()->getDirectionNode(directions::EAST)->setWall();
                //std::cout << "else if statement 3 the current node is: " << a_maze.getCurrentNode()->getStrPos() << std::endl;
                neighbors = numberNeighbors(a_maze.getCurrentNode());
                //std::cout << neighbors << std::endl;
            } // end else if
         } // end while
    } // end for

    // set the current node equal to the first node
    a_maze.setCurrentNode(a_maze.getFirstNode());
    // add the first node to the vactor holding the final path
    finalPath.push_back(*(a_maze.getCurrentNode()));

    // while not at the last node
    while (a_maze.getCurrentNode() != a_maze.getLastNode())
    {
        // check to see if can travel in a certain direction
        if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)))
        {
            // if can travel push the node onto the finalPath vector
            finalPath.push_back(*a_maze.getCurrentNode()->getDirectionNode(directions::NORTH));
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::NORTH));
            // set the new node to visited
            a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)->setVisited();
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::EAST)))
        {
            // if can travel push the node onto the finalPath vector
            finalPath.push_back(*a_maze.getCurrentNode()->getDirectionNode(directions::EAST));
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::EAST));
            // set the new node to visited
            a_maze.getCurrentNode()->getDirectionNode(directions::WEST)->setVisited();
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH)))
        {
            // if can travel push the node onto the finalPath vector
            finalPath.push_back(*a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH));
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::SOUTH));
            // set the new node to visited
            a_maze.getCurrentNode()->getDirectionNode(directions::NORTH)->setVisited();
        } // end if
        else if (canTravel(a_maze.getCurrentNode()->getDirectionNode(directions::WEST)))
        {
            finalPath.push_back(*a_maze.getCurrentNode()->getDirectionNode(directions::WEST));
            // change the value of the node
            a_maze.setCurrentNode(a_maze.getCurrentNode()->getDirectionNode(directions::WEST));
            // set the new node to visited
            a_maze.getCurrentNode()->getDirectionNode(directions::EAST)->setVisited();
        } // end if
    }

    // return the vector holding the path from the first to the last node
    return finalPath;
} // end DEF
} // end namespace solutions
