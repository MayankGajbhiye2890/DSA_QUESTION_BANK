#include<bits/stdc++.h>
using namespace std;

class disjoint_set{
    vector<int>rank, parent;

    public:
    disjoint_set(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findparent(int x){//function to find ultimate parent
        if(x==parent[x]){
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }

    bool UnionByRank(int u , int v){
        int ultp_u = findparent(u);
        int ultp_v = findparent(v);
        if(ultp_u == ultp_v) return false;
        if(rank[ultp_u]< rank[ultp_v]){
            parent[ultp_u]=ultp_v;
        }
        else if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_v]=ultp_u;
        }
        else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
        return true;
    }
};

int main(){
    disjoint_set ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);
    if(ds.findparent(3) == ds.findparent(7)){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    ds.UnionByRank(3,7);
    
}

//redundant connection leetcode
class disjoint_set{
    vector<int>rank, parent;

    public:
    disjoint_set(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }

    int findparent(int x){//function to find ultimate parent
        if(x==parent[x]){
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }

    bool UnionByRank(int u , int v){
        int ultp_u = findparent(u);
        int ultp_v = findparent(v);
        if(ultp_u == ultp_v) return false;
        if(rank[ultp_u]< rank[ultp_v]){
            parent[ultp_u]=ultp_v;
        }
        else if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_v]=ultp_u;
        }
        else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disjoint_set dsu(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(!dsu.UnionByRank(u,v)){
                return edge;
            }
        }
        return {};
    }
};

