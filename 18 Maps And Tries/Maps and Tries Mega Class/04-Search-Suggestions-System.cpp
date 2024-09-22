// leetcode 1268. Search Suggestions System

class TrieNode{
    public: 
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    string word;
    TrieNode(char ch): data(ch), isTerminal(false){};
};

class Trie{
    TrieNode*root;
    
    void insertUtil(TrieNode* root, string &word, int i = 0){
        if(i==word.size()){
            root->isTerminal = true;
            root->word = word;
            return;
        }
        if(root->children.find(word[i]) == root->children.end()){
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1);
    }

    TrieNode* searchPrefixUtil(TrieNode* root, string&prefix, int i = 0){
        if(i>=prefix.size()){
            // prefix matching completed: now have to return all the terminal words
            return root;
        }
        if(root->children.find(prefix[i]) != root->children.end()){
            return searchPrefixUtil(root->children[prefix[i]], prefix, i + 1);
        }
        return NULL;
    }

    void collectAllWords(TrieNode*root,vector<string>&ans){
        if(!root) return;
        if(root->isTerminal) ans.push_back(root->word);

        for(auto &[childChar, childNode]: root->children){
            collectAllWords(childNode,ans);
        }
    }

public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string &word){
        insertUtil(root,word);
    }
    vector<string> searchPrefix(string &prefix){
        auto prefixMatchedNode = searchPrefixUtil(root,prefix);
        vector<string>ans;
        if(prefixMatchedNode){
            // collect all the words below this node.
            collectAllWords(prefixMatchedNode, ans);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        vector<vector<string>>ans;

        // insert all product names
        for(auto &product: products){
            trie.insert(product);
        }
        // search with searchWord being typed char by char
        string prefix;
        // this loop is simulating char by char typing of the searchWord
        for(auto ch: searchWord){
            prefix += ch;
            // get all words with current prefix
            vector<string>suggestions = trie.searchPrefix(prefix);
            sort(suggestions.begin(),suggestions.end());

            if(suggestions.size() > 3){
                suggestions.resize(3); // resize to vector of n size
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};