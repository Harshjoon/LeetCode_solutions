class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=1,last=nums[0];
        for(auto i: nums){
            if(i!=last){ 
                nums[x] = i;
                x++;
            }
            last = i;
        }
        return x;
    }
};