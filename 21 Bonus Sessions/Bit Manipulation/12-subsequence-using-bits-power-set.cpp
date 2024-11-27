// gfg: Power Set

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // first we will create mask and then use mask to create subsequence
            int len = s.length();
            // int n = pow(2,len);
            int n = (1 << len);

            vector<string>ans;
            for(int num = 0; num < n; num++){
                // for each num, find the subsequence based on the bits
                string temp = "";
                // now go to each index and check whether i should include or exclude the character
                for(int i = 0; i < len; i++){
                    char ch = s[i];
                    int mask = (1 << i);
                    if(num & mask){
                        // can include the character
                        temp.push_back(ch);
                    }
                }
                if(temp.length() > 0) ans.push_back(temp);
            }
            sort(ans.begin(), ans.end());
            return ans;
		}
};