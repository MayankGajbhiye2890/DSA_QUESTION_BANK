
#include <bits/stdc++.h>
using namespace std;


bool solve(vector<int> &stalls, int k, int mid){
    int cowcount = 1;
    int lastpos = stalls[0];
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int s = 0;
    sort(stalls.begin(), stalls.end());
    int maxi = -1;
    //if(m>n) return -1;
    for (int i = 0; i < stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(solve(stalls, k, mid)){//kys ye wala mid ek possible solution hai ya nhi
            ans = mid;
            s=mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
    
}