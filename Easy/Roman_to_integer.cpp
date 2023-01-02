class Solution {
public:
    int romanToInt(string s) {
        // Create a Map to extract value of Integer from Roman Number.
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int ans = 0;
        ans = roman[s[s.size() - 1]];
        // iterate over reverse string.
        for(int i=s.size()-2;i>=0;i--){  
            // If curret char value is smaller than previous char value. 
            if ( roman[s[i]] < roman[s[i+1]] ){ 
                ans -= roman[s[i]];
            }
            // add value of roman to ans.
            else{
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};