#include "NodeList.h"
#include <iostream>

NodeList::NodeList()
{
    this->length = 0;
}

NodeList::~NodeList() {}

NodeList::NodeList(NodeList &other)
{
    length = other.getLength();
    for (int i = 0; i < length; i++)
    {
        this->nodes[i] = other.getNode(i);
    }
}
NodeList::NodeList(NodeList &other, int rows, int cols)
{
    {
        length = other.getLength();
        nodes = new Node *[rows * cols];
        for (int i = 0; i < length; i++)
        {
            this->nodes[i] = other.getNode(i);
        }
    }
}

NodeList::NodeList(int rows, int cols)
{
    this->length = 0;
    nodes = new Node *[rows * cols];
}

int NodeList::getLength()
{
    return length;
}

void NodeList::addElement(Node *newPos)
{
    nodes[length] = newPos;
    length++;
}

Node *NodeList::getNode(int i)
{
    return nodes[i];
}

void NodeList::printNodes()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << nodes[i]->getRow() << ",";
        std::cout << nodes[i]->getCol() << ",";
        std::cout << nodes[i]->getDistanceTraveled() << std::endl;
    }
}

bool NodeList::contains(Node &node)
{
    bool dublicate = false;

    for (int i = 0; i < length; i++)
    {
        if (nodes[i]->sameNode(&node))
        {
            dublicate = true;
        }
    }

    return dublicate;
}
