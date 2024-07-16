//leetcode 136: single number
class Solution{
public:
    int singleNumber(vector<int>&nums){
        //frequency table
        unordered_map<int,int>freqMap;
        for(int i=0; i<nums.size();i++){
            int num=nums[i];
            freqMap[num]=freqMap[num]+1;
        }
        unordered_map<int,int>::iterator it;
        int ans;
        for(it = freqMap.begin(); it!=freqMap.end(); it++){
            int key= it->first;
            int freq= it->second;
            if(freq==1){
                ans=key;
                break;
            }
            // cout<<key<<" "<<freq<<endl;
        }
        return ans;
    }
};
