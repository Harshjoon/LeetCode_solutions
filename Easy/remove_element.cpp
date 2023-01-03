class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // remove val and get iterator to last element in vector after removing val.
        auto i=remove(nums.begin(),nums.end(),val); 
        // find len of vector after removing val.
        return distance(nums.begin(),i);
    }
};