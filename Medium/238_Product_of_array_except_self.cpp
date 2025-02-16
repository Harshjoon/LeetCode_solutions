class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod_all = 1;
        int prod_non_zero = 1;
        int zero_count = 0;
        for(int num: nums){
            prod_all*=num;
            if(num!=0) prod_non_zero*=num;
            if(num == 0) zero_count++;
        }

        vector<int> ans;
        for(int num: nums){

            if(zero_count>1){
                ans.push_back(0);
            }
            else{
                if(num==0) ans.push_back(prod_non_zero);
                else ans.push_back(prod_all/num);
            }
        }

        return ans;
    }
};