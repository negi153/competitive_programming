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
        
        void bfs(int src,unordered_map<int,bool>& visited){
            // linear time complexity
            queue<int> q;
        
            q.push(src);
        
            while(!q.empty()){
                // take front elemen from queue and print it and delete it
                int front = q.front();
                q.pop();
        
                cout<<front<<", ";
                visited[front] = true; // mark this as visited
                
                // add childresns in queue if they are not visited
                for(auto child: adjList[front])
                    {
                        if(!visited[child])
                            q.push(child);
                    }
            }
        
        }
        
        void dfs(int currNode, unordered_map<int,bool>& visited){
            // linear time complexity
            cout<<currNode<<", ";
            visited[currNode] = true;

            // iterate on children of current node
            for(auto child: adjList[currNode]){
                if(!visited[child])
                    dfs(child,visited);
            }
        }

};


int main() {

    graph<int> g;
    // g.addEdge(source_node,target_node,direction)
    g.addEdge(0,1,0); 
    g.addEdge(0,4,0); 
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    
    cout<<"Below is the graph - \n";
    g.printAdjacencyList();
    
    int src = 0;
    unordered_map<int,bool> visited;

    cout<<"\nBFS traversal - \n";
    
    // apply bfs on single graph
    g.bfs(src,visited); // this will work if we have single graph

    // for disconnected grap, we need to visit each node and apply bfs
    cout<<"\n\nDisjoint graph BFS traversal - \n";
    unordered_map<int,bool> visited2;
    for(int i=0;i<5;i++){
        if(!visited2[i])
            g.bfs(i,visited2);
    }

    //------------------------
    // DFS
    cout<<"\n\nDFS traversal - \n";
    // apply dfs on a single node
    unordered_map<int,bool> visited3;
    g.dfs(src,visited3);

    // apply dfs for disjoint graph
    cout<<"\n\nDisjoint graph DFS traversal - \n";
    unordered_map<int,bool> visited4;
    for(int i=0;i<5;i++)
        if(!visited4[i])
            g.dfs(i,visited4);

    return 0;
}