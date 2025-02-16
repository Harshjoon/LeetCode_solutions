class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_hash;
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums_hash[nums[i]] = i;
        }

        for( int i=0; i<n;i++)
        {
            int diff = target - nums[i];
            if( nums_hash[diff] && nums_hash[diff] != i){
                return {i,nums_hash[diff]};
            }
        }
        return {};
    }
};