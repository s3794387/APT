#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){
    this->length=0;
}

NodeList::~NodeList(){

}

NodeList::NodeList(NodeList& other){

}

int NodeList::getLength(){
    return length;
}

void NodeList::addElement(Node* newPos){
    nodes[length] = newPos;
    length++;
}

Node* NodeList::getNode(int i){
    return nodes[i];
}