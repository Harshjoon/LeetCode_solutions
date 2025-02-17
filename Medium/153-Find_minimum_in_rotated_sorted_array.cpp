class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();

        if(n==1) return nums[0];

        if( nums[0] < nums[1] && nums[0] < nums[n - 1] ){
            return nums[0];
        }

        if( nums[n - 1] < nums[0] && nums[n - 1] < nums[n-2] ){
            return nums[n-1];
        }

        while(left <= right){
            int mid = (left + right)/2;

            if( nums[mid] > nums[mid+1] ){
                return nums[mid+1];
            }
            else if( nums[mid] < nums[right] ){
                right = mid;
            }
            else left = mid + 1;
        }

        return -1;
    }
};