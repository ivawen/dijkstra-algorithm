#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph myGraph;
    cout << endl;
    
    int next = 1;
    do
    {
        myGraph.initialize();
        myGraph.dijkstra();
        cout<< endl;
        cout << "**************Path***************" << endl;
        myGraph.display();
        cout << "**************Path***************" <<endl;
        cout << "Continue (1/0)?" <<endl;
        cin >> next;
    } while(next == 1);
   
	return 0;
}
