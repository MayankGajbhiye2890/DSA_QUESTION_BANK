#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    pair<int, int> getcoordinate(int num){
        int rt= (num -1)/n;
        int rb = (n-1) - rt;

        int col = (num -1) %n;
        if((n%2==1 && rb%2==1) || (n%2==0 && rb%2==0)){ // right to left wali condition
            col = (n-1)-col;
        }
        return make_pair(rb,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps =0;
        queue<int>q;
        vector<vector<bool>>visited(n, vector<bool>(n, false));

        visited[n-1][0] = true;
        q.push(1);

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front();
                q.pop();

                if(x==n*n){
                    return steps;
                }
                for(int k=1; k<=6; k++){
                    int val = x+k;
                    if(val>n*n){
                        break;
                    }
                    pair<int, int>coord = getcoordinate(val);
                    int r = coord.first;
                    int c = coord.second;

                    if(visited[r][c] == true) continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1){
                        q.push(val);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};