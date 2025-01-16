#include <bits/stdc++.h>
using namespace std;


//o(length os word) for insertion, deletion and searching as well
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

        // Convert to uppercase
        word[0] = toupper(word[0]);

        int index = word[0] - 'A';
        trienode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Absent
        else {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word) {
        insertutil(root, word);
    }

    bool search_util(trienode* root, string word) {
        if (word.length() == 0) {
            return root->terminal;
        }

        // Convert to uppercase
        word[0] = toupper(word[0]);

        int index = word[0] - 'A';
        trienode* child;

        // Present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return search_util(child, word.substr(1));
    }

    bool search(string word) {
        return search_util(root, word);
    }



    
};

int main() {
    trie* t = new trie();
    t->insertword("ABCD");

    cout << t->search("ABCD") << endl; // Should print 1 (true)
    cout << t->search("abc") << endl;  // Should print 1 (true) since we handle case
    cout << t->search("XYZ") << endl;  // Should print 0 (false)

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

class trienode {
public:
    char data;
    trienode* charchildren[26];
    bool isterminal;

    // Constructor
    trienode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            charchildren[i] = NULL;
        }
        isterminal = false;
    }
};

class trie {
public:
    trienode* root;

    trie() {
        root = new trienode('\0');
    }

    void insertword(string word) {
        insertutil(root, word);
    }
    
    bool searchword(string word){
        return searchutil(root, word);
    }
    
    bool removeword(string word){
        return removeutil(root, word, 0);
    }
private:
    void insertutil(trienode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'A'; // assuming caps lock letters
        trienode* child;

        if (root->charchildren[index] != NULL) {
            // char present
            child = root->charchildren[index];
        } else {
            // absent
            child = new trienode(word[0]);
            root->charchildren[index] = child;
        }

        insertutil(child, word.substr(1));
    }
    
    bool searchutil(trienode*root, string word){
        if(word.length() == 0){
            return root->isterminal;
        }
        int index = word[0] - 'A';
        trienode*child;
        if(root->charchildren[index] != NULL){
            child = root->charchildren[index];
        }
        else{
            //not present
            return false;
        }
        
        return searchutil(child, word.substr(1));
        
    }
    bool isempty(trienode * root){
        for(int i=0; i<26; i++){
            if(root->charchildren[i] != NULL) return false;
        }
        return true;
    }
    bool removeutil(trienode* root, string word, int depth){
        if(depth == word.length()){ //when word exist
            if(root->isterminal){
                root->isterminal = false;
                
                return isempty(root);
            }
            return false; // if the word doesn't exist
        }
        
        int index = word[0] - 'A';
        trienode * child;
        
        if(child == NULL) return false;
        if(root->charchildren[index] != NULL){
            child = root->charchildren[index];
        }
        
        bool todeletenode = removeutil(child, word, depth +1);
        
        if(todeletenode){
            delete child;
            root->charchildren[index] = NULL;
            return isempty(root) && !root->isterminal;
        }
        return false;
    }
};

int main() {
    trie t;
    t.insertword("ABCD");
    cout<<"word is present or not:"<< t.searchword("ABCD");

    return 0;
}
