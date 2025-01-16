
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearchRecursive(vector<vector<int>>& matrix, int target, int left, int right) {
        if (left > right) {
            return 0;
        }
        int cols = matrix[0].size();
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols]; 

        if (midValue == target) {
            return 1; 
        } else if (midValue < target) {
            return binarySearchRecursive(matrix, target, mid + 1, right);
        } else {
            return binarySearchRecursive(matrix, target, left, mid - 1); 
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = binarySearchRecursive(matrix, target, 0, rows*cols -1);
        if(result>0) return true;
        return false;
    }
};