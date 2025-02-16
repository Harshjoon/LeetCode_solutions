class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;

        sort(nums.begin(), nums.end());

        int max = 1;
        int idx = 0;

        while( idx < nums.size() - 1){
            int temp = 1;
 
            int curr = nums[idx+temp-1];
            int next = nums[idx+temp];


            while( curr==next-1 || curr==next ){
                if(curr==next){
                    idx++;
                }
                else{
                    temp++;
                }

                if( idx + temp >= nums.size() ) break;
                
                curr = nums[idx+temp-1];
                next = nums[idx+temp];
            }

            if( temp > max ) max = temp ;

            idx+= temp;
        }

        return max;
    }
};