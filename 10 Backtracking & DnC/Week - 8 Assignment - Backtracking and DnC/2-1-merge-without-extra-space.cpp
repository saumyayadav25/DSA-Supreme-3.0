// gfg: Merge Without Extra Space
// HW of inplace merge sort(2nd ques in assignment)

class Solution {
  public:
    // Function to merge the arrays.
    void merge(int n, int m, long long arr1[], long long arr2[]) {
        int total_len = n + m;
        int gap = (total_len / 2) + total_len % 2;
        while(gap>0){
            int i = 0, j = gap;
            while(j<total_len){
                // compare elements in first array - if a[j] < a[i] then swap their values
                if(j < n && arr1[i] > arr1[j]){
                    swap(arr1[i],arr1[j]);
                }
                // comparing elements in both arrays
                else if(j>=n && i<n && arr1[i]>arr2[j-n]){
                    swap(arr1[i],arr2[j-n]);
                }
                // comparing elements in second array
                else if(j>=n && i>=n && arr2[i-n]>arr2[j-n]){
                    swap(arr2[i-n],arr2[j-n]);
                }
                j++;
                i++;
            }
            gap = gap <= 1 ? 0 : (gap/2) + (gap%2);
        }
    }
};