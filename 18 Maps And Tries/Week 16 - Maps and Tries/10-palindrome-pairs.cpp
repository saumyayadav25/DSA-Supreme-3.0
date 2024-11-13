// lc 336. Palindrome Pairs

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int stringNumber; //original words array index of that string

        TrieNode(char ch):data(ch), stringNumber(-1){
            for(int i = 0; i < 26; i++){
                children[i] = 0;
            }
        }
};

void insertWord(TrieNode*root, string word, int i, int& stringNumber){
    if(i>= word.size()){
        root->stringNumber = stringNumber;
        return;
    }
    int index = word[i] - 'a';

    if(!root->children[index]){
        root->children[index] = new TrieNode(word[i]);
    }
    insertWord(root->children[index], word, i+1, stringNumber);
}

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }

    void insert(string& word, int& stringNumber) {
        insertWord(root,word,0, stringNumber);
    }
    
    bool isPalindrome(string&s, int low, int high){
        while(low <= high){
            if(s[low] != s[high]) return false;
            low++, high--;
        }
        return true;
    }

    void searchCase2(TrieNode*root, vector<int>&myPalindrome, string s){
        if(root-> stringNumber != -1){
            if(isPalindrome(s,0,s.size() - 1)){
                myPalindrome.push_back(root->stringNumber);
            }
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i] != 0){
                s.push_back(i + 'a');
                searchCase2(root->children[i], myPalindrome, s);
                s.pop_back(); // backtrack
            }
        }
    }

    void search(string &word, vector<int>&myPalindrome) {
        TrieNode* curr = root;
        // case 1: when a prefix of string word exactly matches with a word in trie
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(curr->stringNumber != -1){
                // check if rest of the search-word is palindome?
                if(isPalindrome(word, i, word.size() - 1)){
                    myPalindrome.push_back(curr->stringNumber);
                }
            }
            if(curr->children[index]){
                curr = curr->children[index];
            }
            else{
                return;
            }
        }
        // case 2: search-word is a prefix of a word in the trie
        // check remaining subtrees in the trie for the palindrome
        searchCase2(curr, myPalindrome, "");
    }
};

// TC: O(n * k^2) where k: length of longest string
// SC: O(n * k)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        Trie trie;
        // insert all words in reverse order and mark its stringNumber as index of words array
        for(int i = 0; i < words.size(); i++){
            auto reverseword = words[i];
            reverse(reverseword.begin(), reverseword.end());
            trie.insert(reverseword, i);
        }

        // find palindromic pairs of each word
        for(int i = 0; i < words.size(); i++){
            vector<int>myPalindrome; // stores palindromic pairs of ith word

            trie.search(words[i], myPalindrome);

            for(auto it: myPalindrome){
                if(it != i){
                    ans.push_back({i,it});
                }
            }
        }

        return ans;
    }
};