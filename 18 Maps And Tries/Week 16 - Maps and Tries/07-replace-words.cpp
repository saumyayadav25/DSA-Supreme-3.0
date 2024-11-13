// lc 648. Replace Words

class TrieNode{
    public:
        char data;
        unordered_map<char,TrieNode*> children;
        bool isTerminal;
        TrieNode(char val){
            data= val;
            isTerminal = false;
        }
};

void insertWord(TrieNode*root, string word){
            // base case
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            // 1 case
            char ch = word[0];
            TrieNode* child;
            if(root->children.find(ch) != root->children.end()){
                // present
                child = root->children[ch];
            }
            else{
                // absent
                child = new TrieNode(ch);
                root->children[ch] = child;
            }
            // baaki recursion sambhal lega
            insertWord(child,word.substr(1));
        }

bool searchWord(TrieNode* root, string& word, int &i){
    if(root->isTerminal) return true;
    if(i >= word.size()){
        return root->isTerminal;
    }
    char ch = word[i++];
    if(root->children.find(ch) != root->children.end()) {
        return searchWord(root->children[ch], word, i);
    }
    return false;
}

bool searchPrefix(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return true;
    }
    // 1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return false;
    }
    // baaki recursion
    bool recAns = searchPrefix(child, word.substr(1));
    return recAns;
}

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }

    void insert(string word) {
        insertWord(root,word);
    }
    
    int search(string &word) {
        int i = 0;
        bool gotIt = searchWord(root,word,i);
        return gotIt ? i:-1;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchPrefix(root,prefix);
        return ans;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie trie;
        // insert dict into trie
        for(auto root:dictionary){
            trie.insert(root);
        }
        // pick each word and find in trie and check whether the root is available or not
        int start = 0, end = 0;
        while(end < sentence.size()){
            if(sentence[end] == ' ' || end == sentence.size() - 1){
                int len = end == sentence.size() - 1 ? sentence.size() : end - start;
                string word = sentence.substr(start, len);
                int trieMatchIndex = trie.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0,trieMatchIndex) : word;
                if(sentence[end] == ' '){
                    ans += " ";
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};