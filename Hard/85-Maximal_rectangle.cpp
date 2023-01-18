#include <vector>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0, m=size(matrix), n=size(matrix[0]);
        for( int i=0; i<m;i++ ){
            for( int j=0; j<n;j++){
                for( int row=i, colLen=n, col; row<m && matrix[row][j]=='1'; row++ ){
                    for( col=j;col<n && matrix[row][col]=='1'; col++ ){
                        
                        colLen = min(colLen, col - j);
                        ans = max(ans, colLen*(row - i + 1));
                        cout << colLen << "--" << row << endl;
                        cout << ans << endl;
                    }
                }
            }
        }
        return ans;
    }
};