#include "Node.h"
#include <iostream>

Node::Node(int row, int col, int dist_traveled)
{
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
}

Node::~Node()
{
}

int Node::getRow()
{
    return row;
}

int Node::getCol()
{
    return col;
}

int Node::getDistanceTraveled()
{
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    this->dist_traveled = dist_traveled;
}

int Node::getEstimatedDist2Goal(Node *goal)
{
    int dist2Goal = dist_traveled + abs(col - goal->getCol()) + abs(row - goal->getRow());

    return dist2Goal;

}

//--------------------------------

bool Node::sameNode(Node *node)
{
    return (node->getRow() == row && node->getCol() == col);
}