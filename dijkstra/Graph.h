#ifndef DIJKSTRA_H
#define DIJKSTRA_H

class Graph
{
private:
    int ** m; // adjacency matrix , a pointer to pointer (or the distance matrix)
    int n;//Number of element in arrays and matrix
    int *previous;// hold previous nodes whose path is from root node to other nodes "need it to print Path"
    int *minDistance;//will contain for each node of the graph the minimal distance from root node to different node 
    bool*isFindDistance;// is minimal distance found in a node or not ?
    int root; //root node 

public:
    Graph();// constructor : grab distance between nodes of the matrix
    void initialize(); //grab the value of root node and define initiale values of each array above
    void dijkstra(); //compute minimal distances between root node and other nodes 
    void display(); //display the obtained minimal distances , then call printPath()
    void printPath(int node); // print path from root node to other node in the graph
};

#endif // DIJKSTRA_H
