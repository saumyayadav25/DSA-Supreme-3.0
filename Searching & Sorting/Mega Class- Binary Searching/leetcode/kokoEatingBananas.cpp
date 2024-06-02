//leetcode 875: koko eating bananas
class Solution {
public:

    bool canKokoFinishBananasWithKSpeed(vector<int> &piles, int h, int k){
        long long int totalHoursTakenByKokoToFinishAllBananas = 0;
        for( int i=0; i<piles.size();i++){
            totalHoursTakenByKokoToFinishAllBananas +=ceil(piles[i]/(double)k);
        }
        // if(totalHoursTakenByKokoToFinishAllBananas <= h){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return totalHoursTakenByKokoToFinishAllBananas <=h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int ans=0;
        // auto it = max_element(piles.begin(), piles.end());
        // int end = *it;
        int end = *(max_element(piles.begin(), piles.end()));


        //TC: O(n*log(Max(Piles)))
        while(start<=end){
            int mid = (start + end)>>1;
            int k = mid;
            if(canKokoFinishBananasWithKSpeed(piles, h, k)){
                ans = k;
                end = mid-1;
            }
            else{
                start= mid + 1;
            }
        }
        return ans;
    }
};
