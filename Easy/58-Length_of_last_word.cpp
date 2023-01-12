#include <string>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        if(s.size()==0) return 0;
        if(s.size()==1){
            if(s[0]==' ') return 0;
            return 1;
        }
        int i = s.size() - 1;
        while(s[i]==' ' && i>=0){
            i--;
        }
        while(i>=0){
            if(s[i]==' ') break;
            ans ++;
            i --;
        }
        return ans;
    }
};