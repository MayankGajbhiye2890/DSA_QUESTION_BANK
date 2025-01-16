//1 KADENS ALGO

#include<bits/stdc++.h>
using namespace std;
int maxsubarraysum(vector<int>v){
    if(v.empty()) return 0;
    int sum=0;
    int maxi = INT_MIN;
    for(auto i: v){
        sum+=v[i];
        if(sum<0){
            sum=0;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

//trapping rain water
int trappingrainwater(vector<int>heights){
    int n = heights.size();
    int maxleft = heights[0];
    int maxright = heights[n-1];
    int left =0, right = n-1, ans =0;

    while(left<right){
        if(maxleft < maxright){
            left++;
            maxleft = max(maxleft, heights[left]);
            ans += maxleft - heights[left];
        }
        else{
            right--;
            maxright = max(maxright, heights[right]);
            ans += maxright - heights[right];
        }
    }
    return ans;
}

//CANDIES: DISTRIBUTE CANDIES ACCORDING TO RATINGS AND ATLEAST ONE CANDY TO EVERY PERSON: GREEDY NHI CHALEGA CODE WITH MIK
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>L2R(n, 1);
        vector<int>R2L(n, 1);
        int countcandy = 0;
        for(int i=1; i<n; ++i){
            if(ratings[i-1]<ratings[i]){//yaha fasega
                L2R[i] = max(L2R[i-1]+1, L2R[i]);//yaha fasega 
            }
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i+1]<ratings[i]){//yaha fasega
                R2L[i] = max(R2L[i],R2L[i+1]+1);//yaha fasega
            }
        }

        for(int i=0; i<n ;i++){
            countcandy += max(L2R[i], R2L[i]);
        }
        return countcandy;
    }
};
