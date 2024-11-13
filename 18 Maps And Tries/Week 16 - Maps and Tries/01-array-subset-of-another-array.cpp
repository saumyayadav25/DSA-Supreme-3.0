// gfg: Array Subset

// TC: O(m+n)
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>map;
    string ans = "Yes";

    // map hashing using a1
    for(int i = 0; i < n; i++){
        map[a1[i]]++;
    }

    // check whether all elements of a2 are present in a1
    for(int i = 0; i < m; i++){
        if(map.find(a2[i]) == map.end()){
            ans = "No";
            break;
        }
        else{
            // present
            if(map[a2[i]] > 0){ //occurrence should be greater than 0
                map[a2[i]]--;
            }
            else{
                ans = "No";
                break;
            }
        }
    }
    return ans;
}