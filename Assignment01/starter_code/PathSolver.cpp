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

// Search for the starting Node
{
    for (int row = 0; row < ENV_DIM; ++row)
    {
        for (int col = 0; col < ENV_DIM; ++col)
        {
            if (env[row][col] == 'S')
            {
                *startNode = Node(row, col, 0);
            }
        }
    }

NodeList* openList;
int currentRow = startNode->getRow();
int currentCol = startNode->getCol();

openList->addElement(startNode);

for (int i = 0;i < NODE_LIST_ARRAY_MAX_SIZE; ++i){
    if (currentRow>0){
        if(env[currentRow-1][currentCol] == '.'){
            Node* newNode = new Node(currentRow-1,currentCol,i+1);
            openList->addElement(newNode);
        }
    }
     if (currentRow<ENV_DIM-1){
        if(env[currentRow+1][currentCol] == '.'){
            Node* newNode = new Node(currentRow+1,currentCol,i+1);
            openList->addElement(newNode);
        }
    }
     if (currentCol>0){
        if(env[currentRow][currentCol-1] == '.'){
            Node* newNode = new Node(currentRow,currentCol-1,i+1);
            openList->addElement(newNode);
        }
    }
     if (currentCol<ENV_DIM+1){
        if(env[currentRow][currentCol+1] == '.'){
            Node* newNode = new Node(currentRow,currentCol+1,i+1);
            openList->addElement(newNode);
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
