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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, &res, 0);
        return res;
    }

    void helper( TreeNode* root, vector<int> *vals, int level )
    {
        if ( root == nullptr ) return;

        if ( level == vals->size() ) vals->push_back(root->val);
        else (*vals)[level] = max(root->val, (*vals)[level]);
        //else vals[level] = max(root->val, vals[level]);

        helper(root->left, vals,level+1);
        helper(root->right,vals,level+1);
    }
};