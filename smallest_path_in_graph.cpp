#include<bits/stdc++.h>
using namespace std;

//bfs code
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, bool>visited;
	unordered_map<int, int>parent;
	unordered_map<int, list<int>>adj;

	for(int i =0; i<n; i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	
	queue<int>q;
	q.push(s);
	parent[s] = -1; visited[s] = true;

	while(!q.empty()){
		int fnode = q.front();
		q.pop();

		for(auto nbr: adj[fnode]){
			if(!visited[nbr]){
				parent[nbr] = fnode;
				visited[nbr] = true;
				q.push(nbr);
			}
		}
	}

	//prepare shortest path
	vector<int>ans;

	int currnode = t; //starting from destination
	ans.push_back(t);
	while(currnode != s){
		currnode = parent[currnode];
		ans.push_back(currnode);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


//dijkastra algo

#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Build adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt)); // Add this line if graph is undirected
    }

    // Initialize distances
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Min-heap using set
    set<pair<int, int>> st;
    st.insert(make_pair(0, source)); // Insert source node with distance 0

    while (!st.empty()) {
        auto top = *(st.begin());
        int nodedist = top.first;
        int node = top.second;

        st.erase(st.begin()); // Remove processed node

        // Update distances for neighbors
        for (auto nbr : adj[node]) {
            if (nodedist + nbr.second < dist[nbr.first]) {
                // Find existing record in set
                auto record = st.find(make_pair(dist[nbr.first], nbr.first));
                if (record != st.end()) {
                    st.erase(record); // Erase old record
                }

                // Update distance and insert updated record
                dist[nbr.first] = nodedist + nbr.second;
                st.insert(make_pair(dist[nbr.first], nbr.first));
            }
        }
    }

    return dist;
}

