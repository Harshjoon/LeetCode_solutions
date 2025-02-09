class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        int positive_pointer = 0;

        while( positive_pointer < N && nums[positive_pointer] < 0 ) positive_pointer++;

        int negative_pointer = positive_pointer-1;
        vector<int> res;

        while( negative_pointer >=0 && positive_pointer < N )
        {
            if ( nums[positive_pointer] < abs(nums[negative_pointer]) )
            {
                res.push_back(nums[positive_pointer]*nums[positive_pointer]);
                positive_pointer++;
            }
            else
            {
                res.push_back(nums[negative_pointer]*nums[negative_pointer]);
                negative_pointer--;
            }
        }

        while( negative_pointer >= 0 )
        {
            res.push_back(nums[negative_pointer]*nums[negative_pointer]);
            negative_pointer--;
        }

        while( positive_pointer < N )
        {
            res.push_back(nums[positive_pointer]*nums[positive_pointer]);
            positive_pointer++;
        }

        return res;
    }
};