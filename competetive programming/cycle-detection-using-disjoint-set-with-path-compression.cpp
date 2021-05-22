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

	// cout << "vertex is : " << v << endl;

	int v_temp = v; // v_temp will be used to compress the path between v and root.

	while (parent[v] > 0) {
		v = parent[v]; //set v as parent of itself until we did not find the root element.
	}


	//after getting out of this while loop, v will be our root node and parent of v will be a negative value. negative value here tells that we are at the top of node. and absolute value of that will tell us the rank (which means how many elements are connected to that node)

	if (v != v_temp) // compress path only if node is not equal to its root
		parent[v_temp] = v; //here v contains the root of original v node, and v_temp contains the value of v.. now we are connecting directly v to its root node. so if second time we need to find the root of v so it will not have to go to the same path again. it will find its parent in 2 step.

	return v;

}


void union_sets(int v1, int v2) { // this function joins the two sets
	//parent of the root node will contain the rank. which vertex has more rank, it will the parent of another node


	if (abs(parent[v1]) >= abs(parent[v2])) {
		parent[v1] = parent[v1] + parent[v2]; //add the rank
		parent[v2] = v1; //make one node as a parent of another node
	}
	else
	{
		parent[v2] = parent[v1] + parent[v2];
		parent[v1] = v2;
	}
}


void detect_cycle(int n) {

	memset(parent, -1, sizeof(parent)); //initially we are marking parent of every node as -1, that means every element is present in different sets.

	int v1, v2; //two variable to represent the vertex of an edge
	int top_parent_v1, top_parent_v2; // two variables to store the root parents of 2 vertex

	//loop to take one edge at a time.
	for (int i = 1; i < n; i++)
	{
		v1 = i;
		for (int j = 0; j < graph[i].size(); j++) {
			v2 = graph[i][j];

			//find the root parent of both the vertex
			top_parent_v1 = find_parent(v1);
			top_parent_v2 = find_parent(v2);

			if (top_parent_v1 == top_parent_v2) {
				cout << "Cycle is present" << endl;
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

	detect_cycle(n);

	return 0;
}