//leetcode 791:custom sort string
string orderCopy;
class Solution {
public:
    
    static bool cmp(char a, char b){
        //order wali string me dekho ki konsa character phle ana chiye and konsa character badme aana chiye
        //return true: a will be placed before b
        return (orderCopy.find(a) < orderCopy.find(b));
    }
    string customSortString(string order, string s) {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};