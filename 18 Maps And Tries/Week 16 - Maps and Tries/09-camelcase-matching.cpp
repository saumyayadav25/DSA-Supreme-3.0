// lc 1023. Camelcase Matching

class TrieNode{
    public:
        char data;
        TrieNode* children[58];
        bool isTerminal;
        TrieNode(char ch):data(ch), isTerminal(false){
            for(int i = 0; i < 58; i++){
                children[i] = 0;
            }
        }
};

void insertWord(TrieNode*root, string word, int i){
    if(i>= word.size()){
        root->isTerminal = true;
        return;
    }
    int index = word[i] - 'A';
    if(!root->children[index]){
        root->children[index] = new TrieNode(word[i]);
    }
    insertWord(root->children[index], word, i+1);
}

bool searchWord(TrieNode* root, string& word, int i){
    if(i >= word.size()){
        return root->isTerminal;
    }
    int index = word[i] - 'A';
    if(root->children[index]){
        return searchWord(root->children[index], word, i+1);
    }
    else if(islower(word[i])){
        return searchWord(root, word, i+1);
    }
    return false;
}

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }

    void insert(string& word) {
        insertWord(root,word,0);
    }
    
    int search(string &word) {
        bool gotIt = searchWord(root,word,0);
        return gotIt;
    }
};

// TC: O(PatternLength) + O(n*m) where n: no. of queries;    m: q[i] length
// SC: O(PatternLength)
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);
        for(auto query: queries){
            ans.push_back(trie.search(query));
        }
        return ans;
    }
};