#include<bits/stdc++.h>
using namesace std;

int trap(vector<int>& height) {
    int n = height.size();
    
    int maxleft=height[0]; 
    int maxright=height[n-1];
    int left=0, right=n-1, ans=0;
    while(left<right){
        if(maxleft < maxright){//left pointer moves forward
            left ++;
            maxleft = max(maxleft, height[left]);
            ans += maxleft - height[left];
        }
        else{
            right--;
            maxright = max(maxright, height[right]);
            ans += maxright-height[right];
        }
    }
    return ans;
}
