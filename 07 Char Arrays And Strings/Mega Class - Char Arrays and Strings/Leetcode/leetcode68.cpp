// leetcode 68: text justification
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currentLine;
        int currentLineTotalChars = 0;
        for(int i=0;i<words.size();i++){
            string &currentWord = words[i];
            int currentLineNeededNumberOfSpaces = currentLine.size(); //single space after each word

            if(currentLineTotalChars + currentLineNeededNumberOfSpaces + currentWord.size() >maxWidth){
                //exceded. (means)->currentLine without taking currentWord is complete.
                // this is fully justified case
                int extraSpaces = maxWidth - currentLineTotalChars;
                int spacesGoInBetweenWord = extraSpaces / max(1,(int)(currentLine.size()-1));
                int remainder = extraSpaces % max(1,(int)(currentLine.size()-1));  //not evenly distributed spaces
                //we dont need spaces after last word
                for(int j=0;j<currentLine.size()-1;j++){  
                    //add spaces evenly
                    for(int k=0;k<spacesGoInBetweenWord;k++){
                        currentLine[j] += " ";   //add spaces after the word.
                    }
                    if(remainder>0){
                        currentLine[j] +=" ";
                        remainder--;
                    }
                }
                if(currentLine.size()==1){
                    //left justified case, because only 1 word in the line
                    while(extraSpaces--) currentLine[0] += " ";
                }

                //final line
                string finalLine="";
                for(string wordWithSpaces: currentLine){
                    finalLine += wordWithSpaces; //string concatenation
                }
                ans.push_back(finalLine);
                currentLine.clear();
                currentLineTotalChars = 0;
            }
            //currentLine is not complete
            currentLine.push_back(currentWord);
            currentLineTotalChars += currentWord.size(); //without including spaces
        }

        //take care of last line
        //add 1 space between words
        string finalLine="";
        for(auto word:currentLine){
            finalLine += word + " ";
        }
        finalLine.pop_back(); //removed extra added space

        //if still maxwidth is not achieved
        int leftSpaces = maxWidth - finalLine.size();
        while(leftSpaces--) finalLine +=" ";
        ans.push_back(finalLine);
        return ans;
    }
};