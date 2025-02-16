class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mapping;

        for(auto str: strs){
            string word = str;
            sort(word.begin(), word.end());
            mapping[word].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto x: mapping){
            ans.push_back(x.second);
        }

        return ans;
    }
};