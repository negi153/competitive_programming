#include<iostream>
#include<vector>
#include<set>
#include<deque>
#define INF 10000000
using namespace std;
//This type of BFS is used to find the shortest distance between two nodes in a graph provided that
// the edges in the graph have the weights 0 or 1

/*
In this approach, a boolean array is not used to mark the node because
the condition of the optimal distance will be checked
when you visit each node. A double-ended queue is used to store
the node. In 0-1 BFS, if the weight of the edge = 0, then the node
is pushed to the front of the dequeue. If the weight of the edge = 1,
then the node is pushed to the back of the dequeue.

*/

vector<pair<int,int> > a[10];
vector<int> dist(10,INF);

void find_distance(int s){

deque<int> q;
q.push_back(s);

dist[s]=0;

while(!q.empty()){

    int n=q.front();
    q.pop_front();
    for(int i=0;i<a[n].size();i++){
        if(dist[a[n][i].first]>dist[n]+a[n][i].second){
            dist[a[n][i].first]=dist[n]+a[n][i].second;
            if(a[n][i].second==0)
                q.push_front(a[n][i].first);
            else
                q.push_back(a[n][i].first);
        }
    }

}



}

int main(){

int nodes,edges,x,y,w,s;
cout<<"enter no. of nodes and edges: ";
cin>>nodes>>edges;

cout<<"enter edges with weight(x y z) :";
for(int i=0;i<edges;i++)
{
    cin>>x>>y>>w;
    a[x].push_back(make_pair(y,w));
    a[y].push_back(make_pair(x,w));
    }

    cout<<"enter source : ";
cin>>s;

find_distance(s);

for(int i=0;i<nodes;i++)
        cout<<"distace of "<<i<<" node from source node is: "<<dist[i]<<endl;


return 0;
}
