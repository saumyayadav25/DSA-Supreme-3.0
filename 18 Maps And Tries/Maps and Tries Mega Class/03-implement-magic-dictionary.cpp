// leetcode 676. Implement Magic Dictionary

class TrieNode{
    public: 
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    TrieNode(char ch): data(ch), isTerminal(false){};
};

class Trie{
    TrieNode*root;
    
    void insertUtil(TrieNode* root, string &word, int i = 0){
        if(i==word.size()){
            root->isTerminal = true;
            return;
        }
        if(root->children.find(word[i]) == root->children.end()){
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1);
    }

    bool searchUtil(TrieNode* root, string&word, int i = 0, bool mismatch = false){
        if(i == word.size()) return mismatch && root->isTerminal;

        auto ch = word[i];
        if(root->children.find(ch) != root->children.end()){
            // match till you can
            if(searchUtil(root->children[ch], word, i+1, mismatch)){
                return true;
            }
        }
        // if you are here means-> there is a mismatch
        if(!mismatch){
            for(auto &[childChar, childNode]: root->children){
                if(ch!=childChar && searchUtil(childNode, word, i+1, true)) return true;
            }
        }
        return false;
    }

public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string &word){
        insertUtil(root,word);
    }
    bool search(string &word){
        return searchUtil(root,word);
    }
};

class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word:dictionary){
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        return trie.search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */