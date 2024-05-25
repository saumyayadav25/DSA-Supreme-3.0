//2pointer method to sort 0's and 1's
//gfg
class Solution{
public:
    void segregate0and1(int arr[], int n){
        int l=0, h=n-1; //2 indices
        while(l<h){
            if(arr[l]==1 && arr[h]==0){
                //swap case
                swap(arr[l], arr[h]);
                l++, h--;
            }
            else{
                if(arr[l]==0){
                    l++;
                }
                if(arr[h]==1){
                    h--;
                }
            }
        }
    }
};
