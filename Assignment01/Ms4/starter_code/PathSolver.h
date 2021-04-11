#ifndef COSC_ASSIGN_ONE_PATHSOLVER
#define COSC_ASSIGN_ONE_PATHSOLVER

#include "Node.h"
#include "NodeList.h"
#include "Types.h"

class PathSolver
{
public:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Destructor
    PathSolver();
    ~PathSolver();

    // Execute forward search algorithm
    // To be implemented for Milestone 2
    void forwardSearch(Env env);

    // Get a DEEP COPY of the explored NodeList in forward search
    // To be implemented for Milestone 2
    NodeList *getNodesExplored();

    // Execute backtracking and Get a DEEP COPY of the path the
    // robot should travel
    // To be implemented for Milestone 3
    NodeList *getPath(Env env);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    PathSolver(int rows, int cols);

private:
    /*                                           */
    /* DO NOT MOFIFY THESE VARIABLES             */
    /*                                           */

    // Nodes explored in forward search algorithm
    NodeList *nodesExplored;

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */
    Node *startNode;
    Node *endNode;

    int rows;
    int cols;

    // search for startNode 'S' and endNode 'G' from the environment
    // and update local variables
    void updateEnvNodes(Env env);

    // Return a NodeList of no more than 4 neighbouring Nodes of a given Node
    NodeList *searchNeibouringNodes(Env env, Node *node);

    // Return a NodeList that is a reversed version of a given NodeList
    NodeList *reverseList(NodeList *sample);
};

#endif //COSC_ASSIGN_ONE_PATHSOLVER