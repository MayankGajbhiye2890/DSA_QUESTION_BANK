#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    vector<int>nextsmallerelement(vector<int>&arr, int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            int curr=arr[i];
            while(st.top()!= -1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevsmallerelement(vector<int>&arr, int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int curr=arr[i];
            while(st.top()!= -1 && arr[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }    

    int largestArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextsmallerelement(heights,n);

        vector<int>prev(n);
        prev= prevsmallerelement(heights, n);
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l=heights[i];
            if(next[i]== -1){
                next[i]=n;
            }
            int b = next[i]-prev[i]-1;
            int newarea = l*b;
            area = max(area, newarea);
        }
        return area;
    }   
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        int length=0, breadth=0;
        int maxi=INT_MIN;
        vector<int>histogram(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j =0 ; j<histogram.size(); j++){
                if(matrix[i][j] == '1'){
                    histogram[j]++;
                }
                else{
                    histogram[j]=0;
                }
            }
            maxi = max(maxi, largestArea(histogram));
        }
        return maxi;
    }
};