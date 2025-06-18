#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
        // alsi vectore can be used here
        unordered_map<int,list<pair<int,int>> > adjList;

        void addEdge(int u, int v,int w, bool direction){
            //if direction = 0 -> undirected graph
            // if direction = 1 -> directed graph

            adjList[u].push_back({v,w});;

            if(direction == 0){ // means undirected
                adjList[v].push_back({u,w});
            }
        }

        void printAdjacencyList(){
            for(auto node: adjList){
                cout<<node.first<<" -> ";
                for(auto neighbour: node.second)
                    cout<<"("<<neighbour.first<<","<<neighbour.second<<"), ";

                cout<<endl;
            }
        }
};

int main() {
    
    graph g;
    // g.addEdge(source_node,target_node,weigh,direction)
    g.addEdge(0,1,10,0); // direction is 0 means undirected
    g.addEdge(0,5,20,1); // direction is 1 means it's directed
    g.addEdge(1,2,30,0);
    g.addEdge(2,3,40,1);
    
    g.printAdjacencyList();
    
    
    return 0;
}