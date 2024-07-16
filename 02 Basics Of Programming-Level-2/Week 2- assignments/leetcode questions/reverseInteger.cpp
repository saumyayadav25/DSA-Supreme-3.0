//leetcode 7: reverse integer
class Solution {
public:
    int reverse(int x) {
        int ans = 0, rem =0;
        bool isNegative =false;
        if(x<= INT_MIN ){
            return 0;
        }
        if(x<0){
            isNegative=true;
            x=-x;
        }
        while(x>0){
            if ( ans> INT_MAX /10 ){
                return 0;
            }
            int digit= x%10;
            ans=ans*10 + digit;
            x=x/10;
        }
        return isNegative? -ans : ans ;
    }
};
