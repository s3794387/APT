/* 
 * My approach for Milestone 2 is to follow the pseudo code given in the assignment specs, create
 * helper functions as I go and create small tests to check for errors. I did the same for Milestone
 * 3 by regularly printing out nodeLists to make sure that every node was added correctly. For Milestone
 * 4, after implementing the new nodeList and Env, I had some difficulties figuring out how to read 
 * the standard input correctly and was constantly getting segmentation fault. One of the bigest challenge 
 * that I've encounterd was durring Milestone3 when I had to find the correct neighbouring Nodes and add 
 * it to the pathNodes. I spent quite some time trying to find the errors and figured that there were several
 * nodes in the neighbouringNodes that has the same distance travelled and co-ordinates with the nodes
 * from the nodesExplored. I resolved the problem by only add one node from the neighbouring nodes and 
 * ignore the rest.
 * 
 * Test files are located in Tests folder, some test cases will be different from actual because there are
 * several shortest paths to Goal and expected output is only one of them. 
*/



#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
void testNode();
void testNodeList();

// Read an environment from standard input, pass in the address of rows and cols to be modified
void readEnvStdin(Env &env, int &rows, int &cols);

// Dynamically allocate memory for the environment
Env make_env(const int rows, const int cols);

//Delete a dymanically allocated environment
void delete_env(Env env, int rows, int cols);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution, int rows, int cols);

// Print out an Environment to standard output (without path) for testing.
void printEnv(Env env, int rows, int cols);

int main(int argc, char **argv)
{
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    // testNode();
    // testNodeList();
    // std::cout << "DONE TESTING" << std::endl
    //           << std::endl;

    // Load Environment
    Env env = nullptr;

    // Initialize rows and cols variables to be used later by other functions
    int rows;
    int cols;

    // Read Environment from standard input, pass in rows and cols to be modified
    readEnvStdin(env, rows, cols);

    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    PathSolver *pathSolver = new PathSolver(rows, cols);
    pathSolver->forwardSearch(env);

    NodeList *exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();
    // exploredPositions->printNodes();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList *solution = pathSolver->getPath(env);

    // solution->printNodes();

    printEnvStdout(env, solution, rows, cols);

    delete_env(env, rows, cols);
    delete pathSolver;
    delete exploredPositions;
    delete solution;
}

void readEnvStdin(Env &env, int &rows, int &cols)
{
    // value of 1 because environment cannot be empty
    int row = 1;
    int col = 0;
    int index = 0;

    // a string to store environment characters
    std::string envString = "";

    char c;

    // Loop through standard input until the end
    while (std::cin.get(c))
    {
        // For Testing  purpose
        // std::cout << c << std::endl;

        // Check if standard input returns a newline
        if (c != '\n')
        {
            envString += c;
            index++;
        }
        else
        {
            //when standard input reaches a new line, set value of col if not yet set
            if (col == 0)
            {
                col = index;
            }
            row++;
        }
    }

    // Change variables accordingly
    rows = row;
    cols = col;

    env = make_env(rows, cols);

    // Loop through the environment and set values from the environment string
    for (int i = 0; i < (rows * cols); i++)
    {
        env[i / cols][i % cols] = envString[i];
    }
}

void printEnv(Env env, int rows, int cols)
{

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            std::cout << env[row][col];
        }
        std::cout << std::endl;
    }
}
void printEnvStdout(Env env, NodeList *solution, int rows, int cols)
{
    int row = 0;
    int col = 0;

    // Replace robot path based on the co-ordinates of current node and the node before it
    for (int i = 1; i < solution->getLength() - 1; i++)
    {
        row = solution->getNode(i)->getRow();
        col = solution->getNode(i)->getCol();

        if (row < solution->getNode(i + 1)->getRow())
        {
            env[row][col] = 'v';
        }

        if (row > solution->getNode(i + 1)->getRow())
        {
            env[row][col] = '^';
        }

        if (col < solution->getNode(i + 1)->getCol())
        {
            env[row][col] = '>';
        }

        if (col > solution->getNode(i + 1)->getCol())
        {
            env[row][col] = '<';
        }
    }

    printEnv(env, rows, cols);
}

void testNode()
{
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node *node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList()
{
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList *nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node *b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node *b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node *getB = nodeList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    nodeList->printNodes();
}

Env make_env(int rows, int cols)
{
    Env env = nullptr;

    if (rows >= 0 && cols >= 0)
    {
        env = new char *[rows];
        for (int i = 0; i != rows; ++i)
        {
            env[i] = new char[cols];
        }
    }

    return env;
}

void delete_env(Env env, int rows, int cols)
{
    if (rows >= 0 && cols >= 0)
    {
        for (int i = 0; i != rows; ++i)
        {
            delete env[i];
        }
        delete env;
    }

    return;
}