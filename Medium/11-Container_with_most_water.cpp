class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_pointer = 0;
        int right_pointer = height.size() - 1;
        int max_area = 0;
        
        while( left_pointer < right_pointer )
        {
            if( height[left_pointer] < height[right_pointer] )
            {
                max_area = max( max_area, height[left_pointer]*(right_pointer - left_pointer) );
                left_pointer++;
            }
            else
            {
                max_area = max(max_area, height[right_pointer]*(right_pointer - left_pointer));
                right_pointer--;
            }
        }


        return max_area;
    }
};