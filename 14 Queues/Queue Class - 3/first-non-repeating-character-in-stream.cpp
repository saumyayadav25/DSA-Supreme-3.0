// gfg: First non-repeating character in a stream

// using Queue
class Solution {
	public:
		string FirstNonRepeating(string A){
            unordered_map<char,int>freq;
            string ans = "";
            queue<char>q;
            for(int i = 0; i < A. length(); i++){
                char ch = A[i];
                // to maintain intial state, push ch
                freq[ch]++;
                q.push(ch);
                // find the answer now
                while(!q.empty()){
                    char frontElement = q.front();
                    // check whether front element is anwer or not
                    if(freq[frontElement] == 1){
                        ans.push_back(frontElement);
                        break;
                    }
                    else{
                        // frontElement is duplicate element
                        q.pop();
                    }
                }
                // Important Condition
                // agar sab duplicate element the-> q empty hogi; Agar koi bhi unique element hai toh q empty nhi hogi
                if(q.empty()) ans.push_back('#');
            }
            return ans;
		}
};


// METHOD-1: using maps-> O(N^2)
class Solution {
	public:
		string FirstNonRepeating(string A){
            unordered_map<char,int> freq;
            string result = "";
            for(int i = 0; i < A.length();i++){
                char ch = A[i];
                freq[ch]++;
                // check entire map
                char ans = '#';
                for(int k = 0; k <= i; k++){
                    char c = A[k];
                    if(freq[c]==1){
                        ans = c;
                        break;
                    }
                }
                result.push_back(ans);
            }
            return result;
		}
};