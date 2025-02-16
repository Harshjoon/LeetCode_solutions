class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        map<char,int> mapping;

        for(int i=0; i<s.size(); i++){
            mapping[s[i]]++;
            mapping[t[i]]--;
        }

        for( auto i: mapping ){
            if(i.second != 0) return false;
        }
        return true;
    }
};