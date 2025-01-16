#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minHeap.push(matrix[i][j]);
            }
        }
        int result = 0;
        for (int i = 0; i < k; i++) {
            result = minHeap.top();
            minHeap.pop();
        }
        return result;
    }
};