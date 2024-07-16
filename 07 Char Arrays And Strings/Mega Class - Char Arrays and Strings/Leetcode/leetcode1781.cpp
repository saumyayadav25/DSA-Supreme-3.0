// leetcode 1781: Sum of Beauty of All Substrings
// method-1
class Solution {
public:
    int beautySum(string s) {
        int beautySum = 0;
        unordered_map<char,int>mp;
        //find all substrings
        for(int i=0;i<s.size();i++){
            mp.clear(); 
            for(int j=i; j<s.size();j++){
                // char ch = s[j];
                char &ch = s[j]; 
                mp[ch]++; //freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;
                //find most and least frequent ch from the map
                for(auto each:mp){
                    maxi=max(maxi,each.second);
                    mini=min(mini,each.second);
                }

                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};

// method-2
class Solution {
public:
    int beautySum(string s) {
        int beautySum = 0;
        
        //find all substrings
        for(int i=0;i<s.size();i++){
            int mp[256]={0}; //only 26char ki freq store kr rha h
            for(int j=i; j<s.size();j++){
                // char ch = s[j];
                char &ch = s[j]; 
                mp[ch]++; //freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;
                //find most and least frequent ch from the map
                
                for(char ch='a';ch<='z';ch++){
                    if(mp[ch]>0){ //if char was present in the substring
                        maxi=max(maxi,mp[ch]);
                        mini=min(mini,mp[ch]);
                    }
                    
                }
                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};