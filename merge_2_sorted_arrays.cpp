#include<bits/stdc++.h>
using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //vector<int>num3;
        int k=nums1.size()-1;
        int i=m-1;
        int j=n-1;
        while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
    }

//another solution with finding median

vector<int> mergeSortedArrays(const vector<int>& v1, const vector<int>& v2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if(i<v1.size() && j>v2.size()){
            merged.push_back(v1[i]);
            i++;
        }
        if(i>v1.size() && j<v2.size()){
            merged.push_back(v2[i]);
            j++;
        }
        if (v1[i] < v2[j]) {
            merged.push_back(v1[i]);
            i++;
        } else {
            merged.push_back(v2[j]);
            j++;
        }
    }
    return merged;
}

double findMedian(const vector<int>& merged) {
    int n = merged.size();

    if (n % 2 == 1) {
        return merged[n / 2];
    }

    else {
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
}


// using binary search for better optimization



int main() {
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8};

    vector<int> merged = mergeSortedArrays(v1, v2);

    
    cout << "Merged Array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
  
    double median = findMedian(merged);
    cout << "Median: " << median << endl;

    return 0;
}



