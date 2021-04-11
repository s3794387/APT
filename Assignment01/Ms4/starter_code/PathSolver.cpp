#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver()
{
}

PathSolver::~PathSolver()
{
}

PathSolver::PathSolver(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
}

void PathSolver::forwardSearch(Env env)
{
    // Initializing variables
    updateEnvNodes(env);

    NodeList *openList = new NodeList(rows, cols);
    NodeList *closeList = new NodeList(rows, cols);

    NodeList *neighbouringNodes = nullptr;

    openList->addElement(startNode);

    int manhattanDistance = rows * cols * 2;
    int estimatedDist2Goal = rows * cols;

    Node *selectedNode = nullptr;

    // loop until the goal is reached
    while (manhattanDistance > 0)
    {
        // find the node with shortest estimated distance to goal in openList
        for (int i = 0; i < openList->getLength(); i++)
        {
            if (estimatedDist2Goal >= openList->getNode(i)->getEstimatedDist2Goal(endNode) && !closeList->contains(*(openList->getNode(i))))
            {
                estimatedDist2Goal = openList->getNode(i)->getEstimatedDist2Goal(endNode);
                selectedNode = openList->getNode(i);
            }
        }

        neighbouringNodes = searchNeibouringNodes(env, selectedNode);

        // recalculate manhattanDistance to check if selectedNode is the endNode
        manhattanDistance = abs(selectedNode->getCol() - endNode->getCol()) + abs(selectedNode->getRow() - endNode->getRow());

        if (manhattanDistance > 0)
        {
            // loop through the neighbouring nodes, setDistanceTraveled to one more of selected node and add to openList
            for (int i = 0; i < neighbouringNodes->getLength(); i++)
            {
                neighbouringNodes->getNode(i)->setDistanceTraveled(selectedNode->getDistanceTraveled() + 1);
                openList->addElement(neighbouringNodes->getNode(i));
            }
        }

        // if goalreached, selectedNode is endNode
        else
        {
            endNode = selectedNode;
        }
        closeList->addElement(selectedNode);

        // closeList->printNodes();

        // std::cout << manhattanDistance << std::endl;
        estimatedDist2Goal = rows * cols;
    }
    // closeList->printNodes();
    // Produces a DEEP COPY of the nodesExplored
    nodesExplored = new NodeList(*closeList, rows, cols);
    // openList->printNodes();
    // nodesExplored->printNodes();
}

NodeList *PathSolver::getNodesExplored()
{
    return nodesExplored;
}

NodeList *PathSolver::getPath(Env env)
{
    // Initialize variables
    NodeList *neighbouringNodes = nullptr;

    NodeList *endList = new NodeList(rows, cols);

    bool nodeFound;

    endList->addElement(endNode);

    // since we've already know the distance from S to G, we can loop that exact number of times to get the correct number of path nodes
    for (int i = 0; i < endNode->getDistanceTraveled() - 1; i++)
    {
        neighbouringNodes = searchNeibouringNodes(env, endList->getNode(i));

        // check if a neighbouring node has been addded
        nodeFound = false;

        // loop through each neighbouring node
        for (int j = 0; j < neighbouringNodes->getLength(); j++)
        {
            neighbouringNodes->getNode(j)->setDistanceTraveled(neighbouringNodes->getNode(j)->getDistanceTraveled() - 1);

            // loop through each node in the nodesExplored nodeList
            for (int k = 0; k < nodesExplored->getLength(); k++)
            {

                // check if they have the same co-ordinates and distance traveled
                if (nodesExplored->getNode(k)->sameNode(neighbouringNodes->getNode(j)) && nodesExplored->getNode(k)->getDistanceTraveled() == neighbouringNodes->getNode(j)->getDistanceTraveled() && !nodeFound)
                {
                    // add node to the endList
                    endList->addElement(neighbouringNodes->getNode(j));

                    nodeFound = true;
                }
            }
        }
    }

    // add startNode to the end of the List
    endList->addElement(startNode);

    // endList->printNodes();

    // reverse the endList so that we have a List of nodes from start to finish
    NodeList *path = new NodeList(*reverseList(endList), rows, cols);
    // path->printNodes();

    return path;
}

//-----------------------------

void PathSolver::updateEnvNodes(Env env)
{
    // loop through the environment to find node S and G and update local variables
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
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

    NodeList *neighbouringNodes = new NodeList(rows, cols);

    int distanceTraveled = node->getDistanceTraveled();

    // Validate co-ordicates when searching for neighbouring nodes at the edges

    if (currentCol > 0)
    {
        if (env[currentRow][currentCol - 1] == '.' || env[currentRow][currentCol - 1] == 'G')
        {
            neighbouringNodes->addElement(new Node(currentRow, currentCol - 1, distanceTraveled));
        }
    }
    if (currentCol < cols - 1)
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
    if (currentRow < rows - 1)
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
    NodeList *reverseList = new NodeList(rows, cols);
    for (int i = sample->getLength() - 1; i >= 0; i--)
    {
        reverseList->addElement(sample->getNode(i));
    }
    return reverseList;
}