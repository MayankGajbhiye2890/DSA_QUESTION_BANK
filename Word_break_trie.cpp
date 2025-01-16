//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class trienode {
public:
    char data;
    trienode* children[26];
    bool terminal;

    trienode(char data) {
        this->data = data;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        this->terminal = false;
    }
};

class trie {
public:
    trienode* root;

    trie() {
        root = new trienode('\0');
    }

    void insertutil(trienode* root, string word) {
        if (word.length() == 0) {
            root->terminal = true;
            return;
        }

        int index = word[0] - 'a';
        trienode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word) {
        insertutil(root, word);
    }

    bool searchFrom(trienode* node, string& word, int start) {
        trienode* curr = node;
        for (int i = start; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
            if (curr->terminal) {
                if (i == word.size() - 1 || searchFrom(root, word, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string>& B) {
        trie dictionaryTrie;
        
        for (string word : B) {
            dictionaryTrie.insertword(word);
        }
    
        return dictionaryTrie.searchFrom(dictionaryTrie.root, A, 0) ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends