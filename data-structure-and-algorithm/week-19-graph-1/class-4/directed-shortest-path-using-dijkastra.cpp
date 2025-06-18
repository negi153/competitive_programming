#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
#include<set>

using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v, int wt, int direction){
        adjList[u].push_back({v,wt});
        
        if(direction == 0){
            // undirected graph
            adjList[v].push_back({u,wt});
        }
    }

    void printGraph(){
        cout<<"Graph - "<<endl;
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto dest:node.second){
                cout<<"("<<dest.first<<","<<dest.second<<"), ";
            }
            cout<<endl;
        }
    }

    void shortestDistDijkastra(int src,int n){


        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;
        
        // add distance, source in set
        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto top = *st.begin(); // get first value of set which will be smallest in distance, as set will keep distance in sorted order
             
            int nodeDistance = top.first;
            int node = top.second;

            // pop from set
            st.erase(st.begin());

            // iterate on the neighbours
            for(auto nbr: adjList[node]){
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;

                if(nodeDistance + nbrWeight < dist[nbrNode]){

                    // find if neighbour is present in set or not
                    auto result = st.find({dist[nbrNode], nbrNode});

                    if(result != st.end()){
                        st.erase({dist[nbrNode], nbrNode});
                    }

                    // update distance array
                    dist[nbrNode] = nodeDistance + nbrWeight;
                    st.insert({dist[nbrNode], nbrNode});
                    
                }
            }

        }
        
        cout<<"Dijkastra shortest path - "<<endl;
        for(int i=0;i<n;i++){
            cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
        }

    }

};

int main (){

    graph g;


	g.addEdge(6,3,2,1);
	g.addEdge(6,1,14,1);
	g.addEdge(3,1,9,1);
	g.addEdge(3,2,10,1);
	g.addEdge(1,2,7,1);
	g.addEdge(2,4,15,1);
	g.addEdge(4,3,11,1);

	g.addEdge(6,5,9,1);
	g.addEdge(4,5,6,1);

    g.printGraph();

    int src = 6, n = 7;
    g.shortestDistDijkastra(src, n); // time complexity - Elogv

    return 0;
}