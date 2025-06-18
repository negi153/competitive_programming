#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

template <typename T>
class graph{
    public:
        unordered_map<T,list<T>> adjList;
    
        void addEdge(T u, T v, T direction){
            adjList[u].push_back(v);
            
            if(direction==0)
                adjList[v].push_back(u);

        }

        void printAdjacencyList(){
            cout<<"Graph - "<<endl;
            for(auto node:adjList){
                cout<<node.first<<"->";
                for(auto nbr:node.second)
                    cout<<nbr<<", ";
                cout<<endl;
            }
        }

        void topologicalSortDfs(int currNode, unordered_map<int,bool>& visited, stack<int>& st){
            
            // cout<<currNode<<" ";
            visited[currNode] = true;
            
            // iterate on neighbours
            for(auto nbr: adjList[currNode]){
                if(!visited[nbr]){
                    topologicalSortDfs(nbr,visited,st);
                    // st.push(nbr);
                }
            }
            
            // push the curr node in stack when all the neighbour visited of current node
            st.push(currNode);

        }
        
        //this is khan's algorithmn 
        void topologicalSortBfs(int n,vector<int>& ans){
            queue<int> q;
            unordered_map<int,int> indegree;

            // indegree calculate
            for(auto i:adjList){
                int src = i.first;
                for(auto nbr:i.second)
                    indegree[nbr]++;
            }
            
            // put all the nodes inside queue which has indegree = 0
            for(int i=0;i<n;i++){
                if(indegree[i]==0)
                    q.push(i);
            }
            
            // bfs logic
            while(!q.empty()){
                int fNode = q.front();
                q.pop();

                // cout<<fNode<<", ";
                ans.push_back(fNode);

                // decrease the indegree of neighbours as we are removing the curr node
                for(auto nbr:adjList[fNode]){
                   
                    indegree[nbr]--;

                    if(indegree[nbr]==0)
                        q.push(nbr);
                
                }
            }

        }

};

int main(){
    int n = 8;

    graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    g.printAdjacencyList();

    // topological sort using DFS
    stack<int> st;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i])
            g.topologicalSortDfs(i,visited, st);
    }
    
    cout<<"topological sort using DFS - ";
    while(!st.empty()){
        int top = st.top();
        st.pop();

        cout<<top<<" ";
    }
    cout<<endl;

    // --------------------
    // topological sort using BFS

    vector<int> ans;
    //  connected or disconnected

    g.topologicalSortBfs(n,ans);


    cout<<"Topological sort using BFS - ";
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    
    if(ans.size()==n)
        cout<<"it is a valid topological sort. it's DAG graph";
    else
        cout<<"Cycle present or invalid topologica sort";
        
    return 0;
}