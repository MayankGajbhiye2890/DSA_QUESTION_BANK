//heaps

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        priority_queue<pair<int, pair<int, int>>>pq;
        set<pair<int, int>>s;
        
        vector<int>result;
        pq.push({A.back() + B.back(), {N-1, N-1}});
        s.insert({N-1, N-1});
        
        while(K--){
            auto p = pq.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            result.push_back(sum);
            pq.pop();
            
            if(s.find({i-1, j}) == s.end()){
                pq.push({A[i-1] + B[j], {i-1, j}});
                pair<int, int>p = make_pair(i-1, j);
                s.insert(p);
            }
            if(s.find({i, j-1}) == s.end()){
                 pq.push({A[i] + B[j-1], {i, j-1}});
                s.insert({i, j-1});
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends