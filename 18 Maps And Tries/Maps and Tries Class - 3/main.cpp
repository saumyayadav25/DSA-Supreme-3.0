#include<iostream>
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


int main(){
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root,"cover");
    insertIntoTrie(root,"car");
    insertIntoTrie(root,"care");
    insertIntoTrie(root,"snake");
    insertIntoTrie(root,"sundari");
    insertIntoTrie(root,"extremelyWell");
    insertIntoTrie(root,"coward");
    insertIntoTrie(root,"tag");
    insertIntoTrie(root,"take");
    insertIntoTrie(root,"took");
    insertIntoTrie(root,"selfobsessed");

    bool searchAns = searchTrie(root,"take");
    if(searchAns){
        cout << "found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    deleteWord(root,"take");
    searchAns = searchTrie(root,"take");
    if(searchAns){
        cout << "found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }


    return 0;
}