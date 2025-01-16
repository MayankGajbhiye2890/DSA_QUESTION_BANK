#include<bits/stdc++.h>
using namespace std;

bool topobfs(int n, unordered_map<int, list<int>>&adjlist){
    vector<int>ans;
    queue<int>q;
    unordered_map<int, int>indegree;

    for(auto i: adjlist){
        int src = i.first;
        for(auto nbr: i.second){
            indegree[nbr]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int fnode = q.front();
        q.pop();
        ans.push_back(fnode);
        cout<<fnode<<",";
        for(auto nbr: adjlist[fnode]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(ans.size()==n){
        return true;
    }
    else{
        return false;
    }
}
bool canfinish(int numcourses, vector<vector<int>>
 prerequisites){
    unordered_map<int, list<int>>adjlist;
    for(auto task: prerequisites){
        int u = task[0];
        int v = task[1];

        adjlist[v].push_back(u);
    }
    bool ans = topobfs(numcourses, adjlist);
    return ans;
 }

 //course scedule 2
 class Solution {
public:
    vector<int> topobfs(int n, unordered_map<int,list<int> > adjlist){
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>indegree;
        for(auto i: adjlist){
            int src= i.first;
            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }
        //put ndes with indegree 0
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int fnode = q.front();
            q.pop();
            ans.push_back(fnode);
            cout<<fnode<<", ";
            for(auto nbr: adjlist[fnode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size()==n){
            return ans;
        }
        else{
            return {};
        }
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjlist;
        for(auto task: prerequisites){
            int u = task[0];
            int v = task[1];
            adjlist[v].push_back(u);
        }
        vector<int> ans = topobfs(numCourses, adjlist);
        return ans;
    }
};