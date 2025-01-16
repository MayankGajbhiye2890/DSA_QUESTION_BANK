//https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION**/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int, bool>&visited,stack<int>&st,unordered_map<int, list<int>>&adjlist){
	visited[node]=true;
	for(auto nbr: adjlist[node]){
		if(!visited[nbr]){
			dfs(nbr, visited, st, adjlist);
		}
	}
	//topologic
	st.push(node);
}


void revdfs(int node, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&transpose){
	visited[node] = true;
	for(auto nbr: transpose[node]){
		if(!visited[nbr]){
			revdfs(nbr, visited, transpose);
		}
	}
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>>adjlist;
	int n = edges.size();
	for(int i=0; i<n; i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adjlist[u].push_back(v);
	}

	stack<int>st;
	unordered_map<int, bool>visited;

	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfs(i, visited, st, adjlist);
		}
	}

	//transpose

	unordered_map<int, list<int>>transpose;
	for(int i=0; i<v; i++){
		visited[i]=0; //because it should be marked false for transpose operation
		for(auto nbr: adjlist[i]){
			transpose[nbr].push_back(i);
		}
	}

	int count=0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!visited[top]){
			count++;
			revdfs(top, visited, transpose);
		}
	}
	return count;
}