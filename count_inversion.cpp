#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&a, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    int count =0;
    while(left<= mid && right<=high){
        if(a[left]<= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            count += mid-left+1;
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<= high){
        temp.push_back(a[right]);
        right++;
    }

    //transfer all the elements of temp to a
    for(int i=low; i<=high; ++i){
        a[i] = temp[i-low];
    }
    return count;
}

int mergesort(vector<int>&a, int low, int high){
    int count=0;
    if(low>=high) return count;
    int mid = low+(high-low)/2;
    count += mergesort(a,low, mid);
    count += mergesort(a, mid+1, high);
    count += merge(a, low, mid, high);
    return count;
}
int numberOfInversions(vector<int>&a, int n) {
    //int low = 0;
    //int high = n-1;
    return mergesort(a, 0, n-1);
}