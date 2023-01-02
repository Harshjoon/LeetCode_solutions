class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = ""; 
        bool f=false;
        char c; 
        int i = 0;
        while(true){
            // i should be less than string size
            for (auto str:strs){
                if(i>=str.size()){
                    f=true;
                }
            }
            if(f) break;
            // ith char of first string.
            c = strs[0][i];
            // if all strings ith element is c then append to ans.
            for(auto j: strs){
                if (j[i]!=c){
                    f=true;
                }
            }
            // otherwise break loop
            if(f) break;
            ans += c;
            i ++;
        }
        return ans;
    }
};