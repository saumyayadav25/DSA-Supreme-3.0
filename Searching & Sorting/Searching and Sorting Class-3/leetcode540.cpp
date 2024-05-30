//leetcode 540: Single Element in a Sorted Array
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            //single element
            if(s==e){
                return arr[s];
            }
            int currValue = arr[mid];
            int leftValue = -1;
            if(mid-1 >= 0){
                leftValue = arr[mid-1];
            }
            int rightValue = -1;
            if(mid+1 < n){
                rightValue = arr[mid+1];
            }
            //non duplicates
            if(currValue!=leftValue && currValue!=rightValue){
                return currValue;
            }
            //duplicate in left
            if(currValue==leftValue && currValue!=rightValue){
                int pairStartingIndex = mid-1;
                if(pairStartingIndex & 1){
                    //odd: move left
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            //duplicate in right
            else if(currValue!= leftValue && currValue==rightValue){
                int pairStartingIndex = mid;
                if(pairStartingIndex & 1){
                    //odd: move left
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};
