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



//using priority queue

#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, unordered_map<int, list<pair<int, int>>>& adjlist, int n) {
    // Min-heap priority queue: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(n, INT_MAX); // Distance array initialized with INT_MAX
    dist[src] = 0;
    pq.push({0, src}); // Start with the source node

    while (!pq.empty()) {
        int d = pq.top().first;  // Current distance
        int node = pq.top().second;
        pq.pop();

        // If the current distance is greater than the stored distance, ignore it
        if (d > dist[node]) continue;

        // Traverse neighbors
        for (auto neighbor : adjlist[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            int newDist = dist[node] + weight;

            // If a shorter path is found, update
            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

// **Driver Code**
int main() {
    unordered_map<int, list<pair<int, int>>> adjlist; // Graph adjacency list

    // Graph Representation
    adjlist[0] = {{1, 4}, {2, 1}};
    adjlist[1] = {{3, 1}};
    adjlist[2] = {{1, 2}, {3, 5}};
    adjlist[3] = {}; // No outgoing edges

    int n = 4; // Number of nodes
    int src = 0; // Source node

    dijkstra(src, adjlist, n);
    
    return 0;
}
