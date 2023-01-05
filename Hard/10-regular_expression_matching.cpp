class Solution {
public:
    bool Match(string &s, string &p, int i, int j){
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        bool r=false;
        bool e= (i<s.size()) && (s[i]==p[j] || p[j]=='.');
        if((j+1<p.size()) && p[j+1]=='*'){
            r=(e && Match(s,p,i+1,j)) || Match(s,p,i,j+2);
        }
        else if(e) {
            r=Match(s,p,i+1,j+1);
        }
        return r;
    }
    bool isMatch(string s, string p) {
        return Match(s,p,0,0);
    }
};