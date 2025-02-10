/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int leftmost = 0;
        solve(root, 1, depth, leftmost);
        return leftmost;
    }

    void solve(TreeNode * node, int currD, int & depth, int &leftmost)
    {
        if(node==NULL) return;

        if( currD > depth ){
            depth = currD;
            leftmost = node->val;
        }

        solve(node->left, currD + 1, depth, leftmost);
        solve(node->right, currD + 1, depth, leftmost);
    }
};