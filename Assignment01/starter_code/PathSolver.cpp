#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver()
{
    this->nodesExplored = 0;
}

PathSolver::~PathSolver()
{
}

void PathSolver::forwardSearch(Env env)
{
    // Search for the starting Node and Goal node
    this->startNode = searchStartNode(env);
    this->endNode = searchEndNode(env);

    NodeList *openList = new NodeList();
    openList->addElement(startNode);

    int currentRow = startNode->getRow();
    int currentCol = startNode->getCol();

    bool goalReached = false;

    while (goalReached == false)
    {
        Node *selectedNode = new Node(0, 0, 0);
        int estimatedDist2Goal = ENV_DIM * 2;

        for (int i = 0; i < openList->getLength(); i++)
        {
            if (estimatedDist2Goal <= getEstimatedDist2Goal(openList->getNode(i), endNode))
            {
                estimatedDist2Goal = getEstimatedDist2Goal(openList->getNode(i), endNode);
                selectedNode = openList->getNode(i);
            }
        }
    }
}

NodeList *PathSolver::getNodesExplored()
{
    //TODO
}

NodeList *PathSolver::getPath(Env env)
{
    // TODO
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

NodeList *searchNeibouringNodes(Env env, Node *node)
{
    int currentRow = node->getRow();
    int currentCol = node->getCol();

    NodeList *neighbouringNodes = new NodeList();
    Node *node = new Node(0, 0, 0);

    if (currentCol > 0)
    {
        if (env[currentRow][currentCol - 1] == '.')
        {
            node = new Node(currentRow, currentCol, node->getDistanceTraveled());

            neighbouringNodes->addElement(node);
        }
    }
}
