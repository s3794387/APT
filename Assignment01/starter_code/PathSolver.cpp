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

    updateEnvNodes(env);

    NodeList *openList = new NodeList();
    NodeList *closeList = new NodeList();

    NodeList *neighbouringNodes = new NodeList();

    openList->addElement(startNode);

    int manhattanDistance = ENV_DIM * 2;
    int estimatedDist2Goal = ENV_DIM * ENV_DIM;

    Node *selectedNode = nullptr;

    while (manhattanDistance > 0)
    {

        for (int i = 0; i < openList->getLength(); i++)
        {
            if (estimatedDist2Goal >= openList->getNode(i)->getEstimatedDist2Goal(endNode) && !closeList->contains(*(openList->getNode(i))))
            {
                estimatedDist2Goal = openList->getNode(i)->getEstimatedDist2Goal(endNode);
                selectedNode = openList->getNode(i);
            }
        }

        neighbouringNodes = searchNeibouringNodes(env, selectedNode);
        manhattanDistance = abs(selectedNode->getCol() - endNode->getCol()) + abs(selectedNode->getRow() - endNode->getRow());

        if (manhattanDistance > 0)
        {
            for (int i = 0; i < neighbouringNodes->getLength(); i++)
            {
                neighbouringNodes->getNode(i)->setDistanceTraveled(neighbouringNodes->getNode(i)->getDistanceTraveled() + 1);
                openList->addElement(neighbouringNodes->getNode(i));
            }
        }
        else
        {
            endNode = selectedNode;
        }
        closeList->addElement(selectedNode);

        closeList->printNodes();

        std::cout << manhattanDistance << std::endl;
        estimatedDist2Goal = ENV_DIM * ENV_DIM;
    }
    // Produces a DEEP COPY of the nodesExplored
    nodesExplored = new NodeList(*closeList);
}

NodeList *PathSolver::getNodesExplored()
{
    return nodesExplored;
}

NodeList *PathSolver::getPath(Env env)
{
    // Initialize variables
    NodeList *path = nullptr;
    NodeList *neighbouringNodes = nullptr;

    NodeList *endList = new NodeList();

    endList->addElement(endNode);

    for (int i = 0; i < endNode->getDistanceTraveled()-1; i++)
    {
        neighbouringNodes = searchNeibouringNodes(env, endList->getNode(i));

        for (int j = 0; j < neighbouringNodes->getLength(); j++)
        {
            neighbouringNodes->getNode(j)->setDistanceTraveled(neighbouringNodes->getNode(j)->getDistanceTraveled() - 1);

            for (int k = 0; k < nodesExplored->getLength(); k++)
            {
                if (nodesExplored->getNode(k)->sameNode(neighbouringNodes->getNode(j)) && nodesExplored->getNode(k)->getDistanceTraveled() == neighbouringNodes->getNode(j)->getDistanceTraveled())
                {
                    endList->addElement(neighbouringNodes->getNode(j));
                }
            }
        }
    }

    endList->addElement(startNode);

    endList->printNodes();
    path = reverseList(endList);
    path->printNodes();
    return path;
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

NodeList *PathSolver::searchNeibouringNodes(Env env, Node *node)
{
    // Pass current Row and Col values
    int currentRow = node->getRow();
    int currentCol = node->getCol();

    NodeList *neighbouringNodes = new NodeList();

    int distanceTraveled = node->getDistanceTraveled();

    // Validate co-ordicates when searching for neighbouring nodes at the edges

    if (currentCol > 0)
    {
        if (env[currentRow][currentCol - 1] == '.' || env[currentRow][currentCol - 1] == 'G')
        {
            neighbouringNodes->addElement(new Node(currentRow, currentCol - 1, distanceTraveled));
        }
    }
    if (currentCol < ENV_DIM - 1)
    {
        if (env[currentRow][currentCol + 1] == '.' || env[currentRow][currentCol + 1] == 'G')
        {
            neighbouringNodes->addElement(new Node(currentRow, currentCol + 1, distanceTraveled));
        }
    }
    if (currentRow > 0)
    {
        if (env[currentRow - 1][currentCol] == '.' || env[currentRow - 1][currentCol] == 'G')
        {
            neighbouringNodes->addElement(new Node(currentRow - 1, currentCol, distanceTraveled));
        }
    }
    if (currentRow < ENV_DIM - 1)
    {
        if (env[currentRow + 1][currentCol] == '.' || env[currentRow + 1][currentCol] == 'G')
        {
            neighbouringNodes->addElement(new Node(currentRow + 1, currentCol, distanceTraveled));
        }
    }
    return neighbouringNodes;
}

NodeList *PathSolver::reverseList(NodeList *sample)
{
    NodeList *reverseList = new NodeList();
    for (int i = sample->getLength() - 1; i >= 0; i--)
    {
        reverseList->addElement(sample->getNode(i));
    }
    return reverseList;
}