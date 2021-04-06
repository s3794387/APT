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
    this->startNode = searchStartNode(env);
    this->endNode = searchEndNode(env);

    NodeList *openList = new NodeList();
    openList->addElement(startNode);

    int manhattanDistance = ENV_DIM * 2;
    int estimatedDist2Goal = ENV_DIM * 2;

    int distanceTravelled = 0;

    Node *selectedNode = new Node(0, 0, 0);
    NodeList *neighbouringNodes = new NodeList();

    while (manhattanDistance > 0)
    {

        for (int i = 0; i < openList->getLength(); i++)
        {
            if (estimatedDist2Goal >= getEstimatedDist2Goal(openList->getNode(i), endNode) && openList->getNode(i)->getDistanceTraveled() == distanceTravelled)
            {
                estimatedDist2Goal = getEstimatedDist2Goal(openList->getNode(i), endNode);
                selectedNode = openList->getNode(i);
            }
            neighbouringNodes = new NodeList(searchNeibouringNodes(env, selectedNode));
            openList->addElements(neighbouringNodes);
            distanceTravelled++;
            openList->printNodes();
            manhattanDistance = estimatedDist2Goal - distanceTravelled;
        }
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

Node *searchStartNode(Env env)
{
    Node *sNode = new Node(0, 0, 0);

    for (int row = 0; row < ENV_DIM; ++row)
    {
        for (int col = 0; col < ENV_DIM; ++col)
        {
            if (env[row][col] == 'S')
            {
                *sNode = Node(row, col, 0);
            }
        }
    }
    return sNode;
}

Node *searchEndNode(Env env)
{
    Node *eNode = new Node(0, 0, 0);

    for (int row = 0; row < ENV_DIM; ++row)
    {
        for (int col = 0; col < ENV_DIM; ++col)
        {
            if (env[row][col] == 'G')
            {
                *eNode = Node(row, col, 0);
            }
        }
    }
    return eNode;
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
        if (env[currentRow][currentCol - 1] == '.')
        {
            tempNode = new Node(currentRow, currentCol - 1, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentCol < ENV_DIM - 1)
    {
        if (env[currentRow][currentCol + 1] == '.')
        {
            tempNode = new Node(currentRow, currentCol + 1, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentRow > 0)
    {
        if (env[currentRow - 1][currentCol] == '.')
        {
            tempNode = new Node(currentRow - 1, currentCol, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    if (currentRow < ENV_DIM - 1)
    {
        if (env[currentRow + 1][currentCol] == '.')
        {
            tempNode = new Node(currentRow + 1, currentCol, node->getDistanceTraveled() + 1);

            neighbouringNodes->addElement(tempNode);
        }
    }
    return *neighbouringNodes;
}
