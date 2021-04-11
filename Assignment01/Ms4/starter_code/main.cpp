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

// Read a environment from standard input.
void readEnvStdin(Env &env, int &rows, int &cols);

Env make_env(const int rows, const int cols);

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
    int rows;
    int cols;
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

    delete pathSolver;
    delete exploredPositions;
    delete solution;
}

void readEnvStdin(Env &env, int &rows, int &cols)
{
    int row = 0;
    int col = 0;

    std::string envString = "";

    while (!std::cin.eof())
    {

        char c = std::cin.get();
        if (c != '\n' && c != '\0')
        {
            envString += c;
            col++;
        }
        else
        {
            row++;
        }
    }

    rows = row;
    cols = (col - 1) / row;

    env = make_env(rows, cols);

    for (int i = 0; i < (rows * cols); i++)
    {

        env[i / rows][i % cols] = envString[i];
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

/*
 * This function is to help you delete a 
 * dynamically allocated 2D Environment.
 */
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