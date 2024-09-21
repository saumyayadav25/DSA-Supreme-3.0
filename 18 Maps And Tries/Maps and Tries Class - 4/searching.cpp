#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char value;
        unordered_map<int,TrieNode*>children;
        bool isTerminal;

        TrieNode(char data){
            value = data;
            isTerminal = false;
        }
};

// insert
void insertIntoTrie(TrieNode* root, string word){
    // base case: string empty hojaye
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    // 1case: 1 character ko trie me insert krdo
    char ch = word[0];
    TrieNode* child;

    // present: waha chle jao
    // absent: create krdo
    if(root->children.count(ch) == 1){
        child = root->children[ch];
    }
    else{
        // absent
        child = new TrieNode(ch);
        // link new node
        root->children[ch] = child;
    }
    // baaki recursion sambhal lega
    insertIntoTrie(child, word.substr(1));
}

// search
bool searchTrie(TrieNode*root, string word){
    // base case
    // check if last character is terminal
    if(word.length() == 0){
        // iska mtlb root me last character pada hua hai
        // if(root->isTerminal == true) return true;
        // else return false;
        return root->isTerminal;
    }
    // 1case
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
    // baaki rec
    bool recAns = searchTrie(child, word.substr(1));
    return recAns;
}

// remove
void deleteWord(TrieNode* root, string word){
    // base case: word empty hojaye and root me last character hoga
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    // 1case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return;
    }
    // baki rec sambhal lega
    deleteWord(child,word.substr(1));
}


void storeString(TrieNode* root, vector<string> &ans,string output){

    if(root->isTerminal){
        ans.push_back(output);
    }
    // 1 case
    for(auto i: root->children){
        char ch = i.first;
        TrieNode* child = i.second;
        output.push_back(ch);
        // baaki recursion sambhal lega
        storeString(child,ans,output);
        // backtracking
        output.pop_back();
    }
}

void findWordsWithPrefix(TrieNode* root, string prefix, vector<string>&ans){
    // base case
    if(prefix.length() == 0){
        // prefix poora search ho chuka hai, root abhi prefix string ke last character ko store kr rhi hogi
        // ab is last node ke neeche jitni bhi strings ban skti hai, un sabko create krke store krenge using below function
        string temp = "";
        storeString(root,ans,temp);
        return;
    }
    // 1 case
    char ch = prefix[0];
    TrieNode*child;

    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return;
    }
    // baaki recursion sambhal lega
    findWordsWithPrefix(child, prefix.substr(1),ans);
}

vector<vector<string> > getSuggestions(TrieNode* root, string prefix){
    vector<vector<string> > ans;
    
    string temp = "";
    for(int i = 0; i < prefix.length(); i++){
        vector<string> tempAns;
        char currChar = prefix[i];
        temp.push_back(currChar);
        findWordsWithPrefix(root,temp,tempAns);
        // add temp prefix in tempAns array
        for(int j = 0; j < tempAns.size(); j++){
            tempAns[j] = temp + tempAns[j];
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root,"babbar");
    insertIntoTrie(root,"baby");
    insertIntoTrie(root,"baba");
    insertIntoTrie(root,"bala");

    string prefix = "bal"; //b, ba, bal
    vector<vector<string> > ans = getSuggestions(root,prefix);

    for(int i = 0 ; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }

    

    // string prefix = "bab";
    // vector<string>ans;
    // findWordsWithPrefix(root,prefix,ans);
    // for(int i = 0 ; i < ans.size(); i++){
    //     string str = prefix + ans[i];
    //     ans[i] = str;
    //     cout << ans[i] << " " << endl;
    // }
    return 0;
}
