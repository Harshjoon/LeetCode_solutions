class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[n-1];

        for( int i=0;i<n-2;i++ )
        {
            int left_pointer = i+1;
            int right_pointer = n-1;

            while( left_pointer < right_pointer)
            {
                int curr_res = nums[i] + nums[left_pointer] + nums[right_pointer];

                if ( curr_res < target )
                {
                    left_pointer++;
                } 
                else
                {
                    right_pointer--;                    
                }

                if( abs(curr_res - target) < abs(res - target) ) res = curr_res;
            }
        }
        
        return res;
    }
};