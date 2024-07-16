class Solution{
    public:
        int firstRepeated(int a[], int n){
            // for(int i=0;i<n;i++){   //TC:O(N^2)
            //     bool isRepeated=false;
            //     for(int j=i+1;j<n;j++){
            //         if(a[i]==a[j]){
            //             isRepeated=true;
            //             return i+1;
            //         }
            //     }
            // }
            // return -1; 

            // HASHING
            unordered_map<int,int> hash;
            for(int i=0; i<n;i++){
                hash[a[i]]++;
            }
            for(int i=0;i<n;i++){
                if(hash[a[i]]>1){
                    return i+1;
                }
            }
            return -1;
        }
};