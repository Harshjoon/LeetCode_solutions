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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        containsOne(root);

        if( root->val==0 && root->left == NULL && root->right == NULL) return NULL;
        return root;
    }

    bool containsOne(TreeNode* root){
        if(root == nullptr) return false;
        bool left_contains = containsOne(root->left);
        bool right_contains = containsOne(root->right);

        if( !left_contains ) root->left = nullptr;
        if( !right_contains ) root->right = nullptr;

        // if(root->val == 0 && !left_contains && !right_contains){
        //     root = nullptr;
        //     return false;
        // }

        return root->val == 1 || left_contains || right_contains;
    }
};