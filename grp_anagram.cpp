// C++ Code to check if two Strings are anagram of 
// each other using Frequency Array

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// As the input strings can only have lowercase 
// characters, the maximum characters will be 26
const int MAX_CHAR = 26;

bool areAnagrams(string &s1, string &s2) {
    vector<int> freq(MAX_CHAR, 0);
    if(s1.length() != s2.length()) return false;
    // Count frequency of each character in string s1
    for(char ch: s1) 
        freq[ch - 'a']++;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
        freq[ch - 'a']--;
  
    // Check if all frequencies are zero
    for (int count : freq) {
        if (count != 0) 
            return false;
    }
    
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}






class Solution {
public:

    string generate(string &word){
        vector<int>v(26,0);
        for(auto &ch: word){
            v[ch-'a'] += 1;
        }
        string newword = "";
        for(int i =0; i<26; i++){
            int freq = v[i];
            if(freq>0){
                newword += string(freq,(i+'a'));
            }
        }
        return newword;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mp;

        for(int i = 0; i<n; i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }
        vector<vector<string>>result;
        for(auto &ch: mp){
            result.push_back(ch.second);
        }
        return result;
    }
};

