//dp approach

// C++ program to count number of ways to
// reach nth stair using Space Optimized DP

#include <iostream>
#include <vector>
using namespace std;

int countWays(int n) {
  
    // variable prev1, prev2 to store the
      // values of last and second last states 
    int prev1 = 1;
    int prev2 = 1;
  
      for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
  
      // In last iteration final value
      // of curr is stored in prev.
    return prev1;
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}



//normal approach

class Solution {
public:
    int climbStairs(int n) {
        //dp aproach
        if(n<=0) return 0;
        else if(n<=1) return 1;
        else{
            vector<int>stairs(n+1);
            stairs[0]=1;
            stairs[1]=1;
            for(int i=2; i<=n; i++){
                stairs[i]=stairs[i-2] + stairs[i-1];
            }
            return stairs[n];
        }

        //recursive aproach
        // if(n==0 || n==1) return 1;
        // return climbStairs(n-1) + climbStairs(n-2);
      
    }
};