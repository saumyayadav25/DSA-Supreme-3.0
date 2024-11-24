// lc 721. Accounts Merge

class Solution {
public:
    int findParent(vector<int>&parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]); //path compression
    }

    void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        unordered_map<string,int>mp;
        for(int i = 0; i < n; i++){
            auto account = accounts[i];
            for(int j = 1; j < account.size(); j++){
                string &mail = account[j];
                auto it = mp.find(mail);
                if(it == mp.end()){
                    mp[mail] = i;
                }
                else{
                    unionSet(i,it->second, parent, rank);
                }
            }
        }
        unordered_map<int, set<string>> preAns;
        for(auto it: mp){
            int accountNo = it.second;
            string mail = it.first;
            accountNo = findParent(parent, accountNo);
            preAns[accountNo].insert(mail);
        }

        vector<vector<string>> ans;
        for(auto it: preAns){
            int accountNo = it.first;     
            auto st = it.second;
            vector<string>v;
            v.push_back(accounts[accountNo][0]);
            for(auto mail: st){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;
    }
};