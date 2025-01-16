
#include<bits/stdc++.h>
using namespace std;

void findpalindromes(string s, int l, int r, vector<string>&palindromes){
    while(l>=0 && r<s.length() && s[l]==s[r]){
        palindromes.push_back(s.substr(l, r-l +1));
        l--;
        r++;
    }
}
vector<string> findpalindrome(string &s){
    vector<string>palindromes;
    for(int i=0; i<s.length();  i++){
        findpalindromes(s, i, i, palindromes);
        findpalindromes(s, i, i+1, palindromes);
    }
    return palindromes;
}
int main() {
    string s = "ababa";
    vector<string> result = findpalindrome(s);

    for (const string &palindrome : result) {
        cout << palindrome << endl;
    }

    return 0;
}