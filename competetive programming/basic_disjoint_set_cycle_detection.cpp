// 1. disjoint sets are useful for detecting a cycle in non directed graph or undirected graph
// 2. kruskal's algorithm uses disjoint set to detect cycle in graph.
// 3. disjoint sets means ,2 sets doesn't have anything comman. eg. s1 = {1, 2, 3, 4} and s2 = {5, 6, 7} . here s1 intersection s2 is null. so s1 and s2 are disjoint set.
//         4. disjoint set operation-- >
//         a > find ---> to findout any element belongs to which set
//         b > union ---> if there is an edge u, v... find out u, to which set it belong. and find out v, to which set it belong. and if they belong to different set, perform union operation on those 2 sets. or if they belong to same set, then definitely there exist a cycle in the graph.
// 					        4. steps to find cycle.-- >
// 					        4.1 let set s = {1, 2, 3, 4, 5} . initialy each element will be a set.
// 	                        4.2 take edges from graph one by one. and check if those 2 vertices belongs to same set or not.
// 		                        4.2.1 if they belong to same set , then there is a cycle
// 			                        4.2.2 if they does not belong to same set then union those 2 set.
// 					                        repeat the process untill we conver all the edges.


#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100]; //array of vectore to contain the graph edges. here graph is undirected

int parent[100]; //array to store the parents of nodes

int find_parent(int v) { // function to return the root parent of the node or vertex

	while (parent[v] != -1) {
		v = parent[v]; //set v as parent of itself until we did not find the root element.
	}

	//after getting out of this while loop, v will be our root node and parent of v will be -1.

	return v;

}


void union_sets(int v1, int v2) { // this function joins the two sets
	parent[v1] = v2; //make one node as a parent of another node
}


void detect_cycle(int n) {

	memset(parent, -1, sizeof(parent)); //initially we are marking parent of every node as -1, that means every element is present in different sets.

	// for (int i = 0; i < 100; i++) cout << parent[i] << endl;

	int v1, v2; //two variable to represent the vertex of an edge
	int top_parent_v1, top_parent_v2; // two variables to store the root parents of 2 vertex

	//loop to take one edge at a time.
	for (int i = 0; i < n; i++)
	{
		v1 = i;
		for (int j = 0; j < graph[i].size(); j++) {
			v2 = graph[i][j];

			//find the root parent of both the vertex
			top_parent_v1 = find_parent(v1);
			top_parent_v2 = find_parent(v2);

			if (top_parent_v1 == top_parent_v2) {
				cout << "Cycle is present" << endl;
				for (int k = 0; k < 100; k++) {
					if (parent[k] != -1) cout << k << " " << parent[k] << endl;
				}
				return;
			}

			union_sets(top_parent_v1, top_parent_v2);

		}


	}

	cout << "Cycle is not present";

}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	int v1, v2; //temporary variable to store the vertex for edges.

	for (int i = 0; i < n; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2); //since it is a undirected graph. so i should make the connection between v1 to v2 and also from v2 to v1.
		//but in finding the cycle we will pick the edge only one time.
	}



	// for (int i = 0; i < n; i++)
	// {
	// 	cout << i << "->";
	// 	for (int j = 0; j < graph[i].size(); j++)
	// 		cout << graph[i][j] << " ";
	// 	cout << endl;
	// }

	detect_cycle(n);

	return 0;
}