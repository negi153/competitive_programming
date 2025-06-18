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
        
        bool cycleDetectionUsingBfs(int src, unordered_map<int,bool>& visited){

            // time complexity - linear
            
            unordered_map<int,int> parent;
            queue<int> q;

            q.push(src);
            visited[src] = true;
            parent[src] = -1;
            
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                
                // iterate on each neighbour
                for(auto nbr:adjList[frontNode]){
                    if(!visited[nbr]){ // if not visited neighbour
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    else{
                        // if neighour is visited and neighbour is not the parent of front, then cycle found
                        if(nbr != parent[frontNode])
                            {   
                                // if prent of current neighbour is not the front node, then cycle is pressent
                                return true; 
                            }
                     
                    }
                    

                }
            }
            
            return false; // cycle is not present
        }
        
        bool cycleDetectionUsingDfs(int currNode,unordered_map<int,bool>& visited,int parent){
            
            // cout<<currNode<<" ";
            visited[currNode] = true;
            
            // iterate on neighbours
            for(auto nbr:adjList[currNode]){
                // if neighbour is not visited, then make recursion for this
                if(!visited[nbr]){
                    bool checkAns = cycleDetectionUsingDfs(nbr,visited,currNode);

                    if(checkAns == true)
                        return true;
                }
                else{
                    // if neighbour is visited and neighbour is not parent of current node, then there is cycle
                    if(nbr != parent)
                        return true; // cycle is present
                }
                    
                


            }
            
            // cout<<"false ";
            return false; // cycle is not presnet 
        }
};

int main() {

    graph<int> g;
    // g.addEdge(source_node,target_node,direction)
    g.addEdge(0,1,0); 
    g.addEdge(1,3,0); 
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);
    // g.addEdge(3,4,0);// if  uncomment this then it's cyclic graph
    
    cout<<"Below is the graph - \n";
    g.printAdjacencyList();
    
    cout<<"Detecting cycle using BFS - ";
    
    unordered_map<int,bool> visited;
    bool ans = false;
    for(int i=0;i<5;i++){
        if (!visited[i])
            {
              ans = g.cycleDetectionUsingBfs(i,visited);
              if(ans == true)
                    break;
            }
    }
    
    if(ans) 
        cout<<"cycle present"<<endl;
    else
        cout<<"cycle absent"<<endl;
        
    // ----------
    cout<<"Detecting cycle using DFS - ";
    
    unordered_map<int,bool> visitedDfs;
    bool ansDfs = false;
    for(int i=0;i<5;i++){
        if (!visitedDfs[i])
            {
              ansDfs = g.cycleDetectionUsingDfs(i,visitedDfs,-1); // intially parent is -1
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