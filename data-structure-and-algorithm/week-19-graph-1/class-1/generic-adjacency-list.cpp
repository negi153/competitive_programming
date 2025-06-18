#include <iostream>
#include<list>
#include<unordered_map>
#include<string>
using namespace std;
template <typename T>

class graph{
    public:
        // alsi vectore can be used here
        unordered_map<T,list<T> > adjList;

        void addEdge(T u, T v, bool direction){
            //if direction = 0 -> undirected graph
            // if direction = 1 -> directed graph

            adjList[u].push_back(v);;

            if(direction == 0){ // means undirected
                adjList[v].push_back(u);
            }
        }

        void printAdjacencyList(){
            for(auto node: adjList){
                cout<<node.first<<" -> ";
                for(auto neighbour: node.second)
                    cout<<neighbour<<", ";

                cout<<endl;
            }
        }
};

int main() {
    
    graph<char> g;
    // g.addEdge(source_node,target_node,direction)
    g.addEdge('a','b',0); // direction is 0 means undirected
    g.addEdge('a','c',1); // direction is 1 means it's directed
    g.addEdge('b','c',0);
    g.addEdge('c','a',1);
    
    cout<<"Below is the graph of characters - "<<endl;
    g.printAdjacencyList();
    
    graph<int> g1;
    // g.addEdge(source_node,target_node,direction)
    g1.addEdge(0,1,0); // direction is 0 means undirected
    g1.addEdge(0,5,1); // direction is 1 means it's directed
    g1.addEdge(1,2,0);
    g1.addEdge(2,3,1);
    
    cout<<"\nBelow is the graph of integers - "<<endl;
    g1.printAdjacencyList();
    

    graph<string> g2;
    // g.addEdge(source_node,target_node,direction)
    g2.addEdge("ramesh","anjali",0); // direction is 0 means undirected
    g2.addEdge("rahul","kanika",1); // direction is 1 means it's directed
    g2.addEdge("kanika","gopi",0);
    g2.addEdge("gopi","ketan",1);
    
    cout<<"\nBelow is the graph of persons showing who loves whom - "<<endl;
    g2.printAdjacencyList();
    
    return 0;
}