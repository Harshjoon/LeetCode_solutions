#include <typeinfo>
class Solution {
public:
    int *mid =  new int;
    int *offset = new int;
    int *zero = new int(0);
    int search(vector<int>& nums, int target) {         
        return binary_search( nums, target, zero);
    }
    
    int binary_search( vector<int>& nums, int target, int *offset )
    {
        *mid =  int(nums.size()/2);  //nums.size()/2;
        if( nums.size() > 1 ){
            if ( *(nums.begin() + *mid) == target )
            {
                return *mid + *offset;
            }
            else if ( *(nums.begin() + *mid) < target )
            {
                vector<int> new_vector;
                new_vector = vector<int>( nums.begin() + *mid, nums.end() );
                *offset += *mid;
                return binary_search( new_vector, target, offset);
            }
            else if ( *(nums.begin() + *mid) > target )
            {
                vector<int> new_vector;
                new_vector = vector<int>( nums.begin(), nums.begin() + *mid );
                return binary_search( new_vector, target, offset);
            }
        }
        if ( *(nums.begin() + *mid) == target )
        {
            return *mid + *offset;
        }
        return -1;
    }
};