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



//kth largest
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];  // Choosing first element as pivot
    int i = left + 1, j = right;

    while (i <= j) {
        while (i <= j && nums[i] >= pivot) i++; // Move right if greater
        while (i <= j && nums[j] < pivot) j--;  // Move left if smaller
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]); // Place pivot in its correct position
    return j;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(nums, left, right);
        
        if (pivotIndex == k - 1) return nums[pivotIndex]; // Found kth largest
        else if (pivotIndex > k - 1) return quickSelect(nums, left, pivotIndex - 1, k);
        else return quickSelect(nums, pivotIndex + 1, right, k);
    }
    return -1;  // Should never reach here
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "-th largest element is: " << findKthLargest(arr, k) << endl;
    return 0;
}
 
