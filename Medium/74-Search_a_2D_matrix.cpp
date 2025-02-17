class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m,n size(matrix)
        // binary search in col to get the closest row.
        // binary search to get the target.
        int m = matrix[0].size();
        int n = matrix.size();

        int left = 0;
        int right = n-1;

        while(left <= right){
            int mid = (left + right)/2;

            if( matrix[mid][0] == target ) return true;
            else if( matrix[mid][0] < target ){
                left = mid + 1;
            }
            else if( matrix[mid][0] > target ){
                right = mid - 1;
            }
        }

        if(right < 0) right = 0;

        int left_ = 0;
        int right_ = m - 1;

        while(left_<=right_){
            int mid = (left_ + right_)/2;

            if( matrix[right][mid] == target ) return true;
            else if( matrix[right][mid] < target ){
                left_ = mid + 1;
            }
            else{
                right_ = mid - 1;
            }
        }
        
        return false;
    }
};