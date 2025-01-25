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



// USING BINARY SEARCH
#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}

