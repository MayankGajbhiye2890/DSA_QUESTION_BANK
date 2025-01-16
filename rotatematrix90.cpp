#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step1: transpose: swap(marix[i][j], matrix[j][i])
        //step2: reverse matrix: reverse(matrix.begin(), matrix.end())

        int m = matrix.size();
        int n = m;
        for(int i = 0; i<m; ++i){
            for(int j = i; j<n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        //return matrix;

    }
};