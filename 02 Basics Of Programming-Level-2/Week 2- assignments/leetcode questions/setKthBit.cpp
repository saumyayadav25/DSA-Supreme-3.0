//gfg: set the kth bit
class Solution{
public: 
    int setKthBit(int N, int K){
        int mask= 1<<K;
        int ans= N|mask;
        return ans;

        // return N | (1<<k);
    }
};
