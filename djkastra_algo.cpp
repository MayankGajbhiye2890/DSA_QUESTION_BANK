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

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(int vertices, vector<pair<int, int>> adj[], int source) {
    // Distance array to store the shortest distance from the source to each node
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Priority queue to store (distance, node), ordered by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Push source node with distance 0

    while (!pq.empty()) {
        int nodeDistance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Explore all adjacent nodes
        for (auto &neighbor : adj[node]) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Relaxation step: Check if a shorter path exists
            if (dist[node] + edgeWeight < dist[neighborNode]) {
                dist[neighborNode] = dist[node] + edgeWeight;
                pq.push({dist[neighborNode], neighborNode}); // Push updated distance to priority queue
            }
        }
    }

    return dist;
}

int main() {
    int vertices = 6; // Number of vertices
    int edges = 9;    // Number of edges
    vector<pair<int, int>> adj[vertices]; // Adjacency list: adj[node] = {(neighbor, weight)}

    // Input edges: (u, v, weight)
    vector<vector<int>> inputEdges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5}, {2, 3, 8},
        {2, 4, 9}, {3, 4, 4}, {3, 5, 6}, {4, 5, 3}
    };

    // Build adjacency list
    for (auto &edge : inputEdges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Comment this line for a directed graph
    }

    // Run Dijkstra's algorithm from source node 0
    int source = 0;
    vector<int> shortestDistances = dijkstra(vertices, adj, source);

    // Output shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
