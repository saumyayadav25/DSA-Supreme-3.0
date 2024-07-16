// leetcode 151: Reverse words in a string
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int start = 0, end = 0;
        for(int i=0;i<n;i++){
            //skip leading spaces
            while(i<n && s[i] == ' ')
                i++;
            if(i==n) break; //out of bound check

            //copy char to the right position
            while(i<n && s[i]!=' ')
                s[end++]=s[i++];
            //after copy reverse the individual word
            reverse(s.begin()+start, s.begin()+end);

            //add extra space between word
            s[end++]=' ';
            start=end;
        }

        //resize the final string.
        s.resize(end-1);
        return s;
    }
}; 