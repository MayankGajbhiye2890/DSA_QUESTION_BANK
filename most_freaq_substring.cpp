#include <bits/stdc++.h>
using namespace std;

void solve(string s, int k){
    map<string, int> mp;
    int n = s.length();

    for(int i = 0; i <= n - k; i++){
        string sub = s.substr(i, k);  
        mp[sub]++;
    }

    pair<string, int> most_frequent;
    for (auto it : mp) {
        if (it.second > most_frequent.second) {
            most_frequent = it;
        }
    }

    cout << most_frequent.first << " " << most_frequent.second << endl;
}

int main() {
    string s = "abcxyzabxyzabcxyz";
    int k = 3;
    solve(s, k);
    return 0;
}
