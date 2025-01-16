#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC: O(n*m), SC(N*M)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        vector<int>ans;
        
        while(top<=bottom && left<=right){

            //printing top row
            for(int i =left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //printing end coloumn
            for(int i = top; i<= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //printing bottom row
            if(top <= bottom){
                for(int i = right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i= bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }       
        return ans;
    }
};

class Solution {
public:
    // Time Complexity: O(n * m), where n is the number of rows and m is the number of columns
    // Space Complexity: O(n * m), for storing the result
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); // number of rows
        int m = matrix[0].size(); // number of columns
        
        // Define boundaries: left, right, top, bottom
        int left = 0, right = m - 1; 
        int top = 0, bottom = n - 1; 
        
        // Vector to store the spiral order result
        vector<int> ans;
        
        // Continue looping while boundaries don't overlap
        while (top <= bottom && left <= right) {

            // Step 1: Traverse the top row from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down after printing the top row

            // Step 2: Traverse the right column from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left after printing the right column

            // Step 3: Traverse the bottom row from right to left, if still within bounds
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up after printing the bottom row
            }

            // Step 4: Traverse the left column from bottom to top, if still within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right after printing the left column
            }
        }
        
        // Return the result containing elements in spiral order
        return ans;
    }
};
