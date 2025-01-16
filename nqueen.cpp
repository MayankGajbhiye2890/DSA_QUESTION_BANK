#include <bits/stdc++.h> 
using namespace std;

void addsolution(vector<vector<int>>&board, vector<vector<int>>&ans){
    int n = board.size();
    vector<int>temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}
bool issafe(int row, int col, vector<vector<int>>&board, int n){
    //only when not in same row, col, diagonal
    int x = row;
    int y = col;
    //check same row
    while(y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    //check for uppr diaginal
    x = row;
    y = col;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
        x--;
    }

    //check for lower diagonal
    x = row;
    y = col;
    while(x<n && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
        x++;
    }

    return true;
}
void solve(int col, vector<vector<int>>&ans, vector<vector<int>>&board, int n ){
    if(col==n){
        addsolution(board, ans);
        return;
    }

    //solve 1 case rest leave on recursion

    for(int row =0; row< n; row++){
        if(issafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>>nqueens(int n){
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>>ans;

    solve(0, ans, board, n);
    return ans;
}







// bool issafe()


// void solve(int col, vector<int>&temp, vector<vector<int>>&board, int n){
//     if(col == n){
//         board.push_back(temp);
//         return;
//     }

//     for(int row =0; row<n; row++){
//         if(issafe(row, col, board, n)){
//            board[row][col]='Q';
//            solve(col+1, temp, board, n);
//            board[row][col]='0';
//         }
//     }
// }
// vector<vector<int>>nqueen(int n){
//     vector<vector<int>>ans(n, vector<int>(n,0));
//     vector<int>temp;
//     int col = 0;
//     solve(ans, temp, col, n);
//     return ans;
// }
