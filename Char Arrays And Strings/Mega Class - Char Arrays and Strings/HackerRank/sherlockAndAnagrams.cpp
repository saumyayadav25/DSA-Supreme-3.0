#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    unordered_map<string, int>anagramaticSubstringCount;
    int anagramPairs = 0; //ans-> yahi find karna h
    // generate all substring
    for(int i=0; i<s.size(); i++) {
        for(int j=i; j<s.size(); j++) {
            string subString = s.substr(i, j-i+1);
            sort(subString.begin(), subString.end());
            anagramaticSubstringCount[subString]++;
            
        }   
    }
    
    // calculate pairs
    for(auto it: anagramaticSubstringCount) {
        int count = it.second;
        if(count > 1) {
            // find unique pairs
            anagramPairs += (count * (count-1))/2;
        }
    }
    
    return anagramPairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}