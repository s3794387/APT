#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver()
{
    this->nodesExplored = 0;
}

PathSolver::~PathSolver()
{
}
Node *searchStartNode(Env env);

Node *searchEndNode(Env env);

int getEstimatedDist2Goal(Node *node, Node *goal);

NodeList &searchNeibouringNodes(Env env, Node *node);

void PathSolver::forwardSearch(Env env)
{
    // Search for the starting Node and Goal node
    updateEnvNodes(env);

    NodeList *openList = new NodeList();
    NodeList *closeList = new NodeList();

    openList->addElement(startNode);

    int manhattanDistance = ENV_DIM * 2;
    int estimatedDist2Goal = ENV_DIM * ENV_DIM;

    Node *selectedNode = new Node(0, 0, 0);
    NodeList *neighbouringNodes = new NodeList();

    while (manhattanDistance > 0)
    {

        for (int i = 0; i < openList->getLength(); i++)
        {
            if (estimatedDist2Goal >= getEstimatedDist2Goal(openList->getNode(i), endNode) && !closeList->contains(*(openList->getNode(i))))
            {
                estimatedDist2Goal = getEstimatedDist2Goal(openList->getNode(i), endNode);
                selectedNode = openList->getNode(i);
            }
        }

        neighbouringNodes = new NodeList(searchNeibouringNodes(env, selectedNode));
        openList->addElements(neighbouringNodes);
        closeList->addElement(selectedNode);

        openList->printNodes();
        manhattanDistance = abs(selectedNode->getCol() - endNode->getCol()) + abs(selectedNode->getRow() - endNode->getRow());
        std::cout << manhattanDistance << std::endl;
        estimatedDist2Goal = ENV_DIM * ENV_DIM;
    }
}

NodeList *PathSolver::getNodesExplored()
{
    return nullptr;
}

NodeList *PathSolver::getPath(Env env)
{
    return nullptr;
}

//-----------------------------

void PathSolver::updateEnvNodes(Env env)
{

    for (int row = 0; row < ENV_DIM; ++row)
    {
        for (int col = 0; col < ENV_DIM; ++col)
        {
            if (env[row][col] == 'S')
            {
                startNode = new Node(row, col, 0);
            }
            else if (env[row][col] == 'G')
            {
                endNode = new Node(row, col, 0);
            }
        }
    }
}

int getEstimatedDist2Goal(Node *node, Node *goal)
{
    int dist = node->getDistanceTraveled() + abs(node->getCol() - goal->getCol()) + abs(node->getRow() - goal->getRow());
    return dist;
}

NodeList &searchNeibouringNodes(Env env, Node *node)
{
    int currentRow = node->getRow();
    int currentCol = node->getCol();

    NodeList *neighbouringNodes = new NodeList();
    Node *tempNode = new Node(0, 0, 0);

    if (currentCol > 0)
    {
        if (env[currentRow][currentCol - 1] == '.' || env[currentRow][currentCol - 1] == 'G')
        {
            tempNode = new Node(currentRow, currentCol - 1, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentCol < ENV_DIM - 1)
    {
        if (env[currentRow][currentCol + 1] == '.' || env[currentRow][currentCol + 1] == 'G')
        {
            tempNode = new Node(currentRow, currentCol + 1, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentRow > 0)
    {
        if (env[currentRow - 1][currentCol] == '.' || env[currentRow - 1][currentCol] == 'G')
        {
            tempNode = new Node(currentRow - 1, currentCol, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentRow < ENV_DIM - 1)
    {
        if (env[currentRow + 1][currentCol] == '.' || env[currentRow + 1][currentCol] == 'G')
        {
            tempNode = new Node(currentRow + 1, currentCol, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    return *neighbouringNodes;
}
