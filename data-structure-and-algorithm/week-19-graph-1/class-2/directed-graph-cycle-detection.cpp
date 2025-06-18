#include <iostream>
#include<list>
#include<unordered_map>
#include<queue>
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

        bool cycleDetectionUsingDfs(int src,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsCalls){

            visited[src] = true;
            dfsCalls[src] = true;

            for(auto nbr: adjList[src]){

                if(!visited[nbr]){
                    bool aageKaAnswer = cycleDetectionUsingDfs(nbr,visited,dfsCalls);
                    
                    if(aageKaAnswer == true)
                        return true;
                }
                else{ // visited already
                    if(dfsCalls[nbr] == true)
                        return true;
                }
            }
            
            dfsCalls[nbr] = false; // mark false to the function call
            return false;
        }
};

int main() {

    graph<int> g;
    // g.addEdge(source_node,target_node,direction)
    g.addEdge(0,1,1); 
    g.addEdge(1,2,1); 
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);// if  uncomment this then it's cyclic graph
    
    cout<<"Below is the graph - \n";
    g.printAdjacencyList();
    
    cout<<"Detecting cycle using DFS - ";
    
    unordered_map<int,bool> visitedDfs;
    unordered_map<int,bool> dfsCalls; // it is used to keep track of the recursion calls
    bool ansDfs = false;
    for(int i=0;i<5;i++){
        if (!visitedDfs[i])
            {
              ansDfs = g.cycleDetectionUsingDfs(i,visitedDfs,dfsCalls);
              if(ansDfs == true)
                    break;
            }
    }
    
    if(ansDfs) 
        cout<<"cycle present"<<endl;
    else
        cout<<"cycle absent"<<endl;
        
    
    return 0;
}