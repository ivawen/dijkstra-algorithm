#include "Graph.h"
#include <iostream>

//precondition: Weighted graph G={E,V} and source vertex v∈V, such that all edge weights are nonnegative
//post-condition:Lengths of shortest paths (or the shortest paths themselves) from a given source vertex v∈V  to all other vertices

using namespace std;

//Constructor
Graph::Graph()
{
    cout << "How many nodes in the graph ? ";
    cin>>n;
    m = new int* [n]; //create matrix dynamic memory allocation 
    int i,j;
    for(i=0; i<n; i++)// first node of the graph is 0 
        m[i]= new int[n];// create the matrix, allocate number of element in each array of the matrix
        
        cout <<endl;
        cout << "\t\"Enter positive values > 0 for distances between nodes i to j\"" << endl;
        cout << "\t\"Enter 99999 if no distance between i to j\"" << endl;
        cout << "\t\"Enter 0 from one node to itself i to i or j to j\"" <<endl;
        cout <<endl;
        
    
    /*distance from one node to itself is null i to i , or j to j
     * if edge exists from i to j or j to i this edge contains the distance
     * if no edge exists from i to j display value of 99999 that represents unknown distance
     * Precondition: i>=0, j>=0
     * */
    for (i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            cout << "Distance edge" << "(" << i <<"," << j << ")" <<"?"<<  endl;
            cin >> m[i][j]; // enter the weight of the matrix
        }
        
    //arrays memory allocation 
    minDistance = new int[n];
    isFindDistance = new bool[n];
    previous = new int[n];
}

/*initializing arrays to default values
 * the arrays values will be updated along in the code */
void Graph::initialize()
{
    int i;
    cout << "Enter root node" << endl;
    cin >> root;
    cout << endl;
    for(i=0; i<n; i++)
        minDistance[i] = 99999;// assume no distances at start, all minimal distances fixed by default to 99999 "just random"
    for(i=0; i<n; i++)
        isFindDistance[i] = false;//no distance from start as well
    for(i=0; i<n; i++)
        previous[i] = -1; //for each node i there is no previous node
}

void Graph::dijkstra()
{
    int i,j;
    
    /*see the adjacent vertices of the root node in the graph, and grab the distances that take from root node to the 
     direct successors of that node*/
    for(j=0; j<n; j++)
    {
        minDistance[j] = m[root][j];// get distance in the matrix from root to the successor node
        previous[j] = root; // update the previous nodes  
    }
    //initialize values
    isFindDistance[root] = true;// minimal distance has been found from root node to itself
    minDistance[root] = 0; //minimal distance from node to itself is 0
    previous[root] = root; // predecessor of root node is itself

    /*find minimal distances from root node to other nodes. n-1 to find the minimal distance from root node to 
     * the other n-1 nodes of the graph*/
    for(i=0; i<n-1; i++)
    {
        int mind = 99999;
        //s the index for the minimal value or distance
        int s = root;
        
        //get the minimal distance in the array
        for(j=0; j<n; j++)
            //if distance == true skip
            if(!isFindDistance[j])//get the minimum distance only for nodes that we did not find the minimal distance for
                if(minDistance[j] < mind)
                {
                    s = j;// set the index of minimal distance 
                    mind = minDistance[s];// get the value of minimal distance as well
                }
                isFindDistance[s] = true; // update the array. Start with new succesor 's' of the root node  whose we found min distance
            
            //loop for all successor j of node s
            for(int j = 0; j<n; j++)
                if(!isFindDistance[j])
                    //found even small distance
                    if(mind + m[s][j] < minDistance[j]) /*get all succesors of node s. add min value that had been 
                     * found previously to the weight that takes to a successor m of node s */
                    {
                        minDistance[j] = mind + m[s][j];//update min distance of node j
                        previous[j] = s; // update. succesor j is a child of node s 
                    }
    }
}

//displays the path by calling printPath()
void Graph::display()
{
    int i;
    for(i=0; i<n; i++)//loop through nodes
    {
        if (i == root)//if we are at root
            cout << root << " " << root; // if i == 0 root print path from root to root
        else
                printPath(i);// call printPath to print the path
        if(minDistance[i] !=99999)//99999 is infiniti or not existing path
            cout << " Minimal distance is: " << minDistance[i] << endl;// print distances
        else
            cout <<"NO PATH!!!!" << endl;//else no path
    }
}

//Print the path using recursion 
void Graph::printPath(int node)
{
    if(node == root)//base case. 
        cout << node <<" ";//print the node
    else
    {
        printPath(previous[node]);//recursive call of printPath
        cout << node << " ";
    }
}