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

//using quickselect algo
int partition(vector<int>&arr, int low, int high){
        int pivot = arr[low];
        int i = low+1;
        for(int j = low+1; j<=high; j++){
            if(arr[j]< pivot){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[low], arr[i-1]);
        return i-1;
    }
    int quickselect(vector<int>&arr, int k, int low, int high){
        if(low>high) return 0;
        int pivot_index = partition(arr, low, high);
        if(pivot_index == k) return arr[pivot_index];
        else if(k<pivot_index) return quickselect(arr, k, low, pivot_index -1);
        else return quickselect(arr,k, pivot_index+1, high);
        //return -1;
    }
    int kthSmallest(vector<int> &arr, int k) {
       return quickselect(arr, k-1, 0, arr.size()-1);
    }
