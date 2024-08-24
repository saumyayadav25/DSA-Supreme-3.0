// leetcode 649. Dota2 Senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiantQ, direQ;
        int position = 0;
        for(; position<senate.size(); position++){
            char senator = senate[position];
            if(senator=='R') radiantQ.push(position);
            if(senator=='D') direQ.push(position);
        }
        while(!radiantQ.empty() && !direQ.empty()){
            int rFront = radiantQ.front();
            radiantQ.pop();
            int dFront = direQ.front();
            direQ.pop();
            // simulation of voting
            if(rFront < dFront){
                // means R will ban D forever
                radiantQ.push(position++);
            }
            else{
                // D will ban R forever
                direQ.push(position++);
            }
        }
        if(!radiantQ.empty()) return "Radiant";
        return "Dire";
    }
};