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
    int num_moves = 0;

    int distributeCoins(TreeNode* root) {
        //int num_moves;
        give_coins(root);
        return num_moves;
    }

    int give_coins(TreeNode* node){
        if( node==NULL) return 0;
        int left_moves = give_coins(node->left);
        int right_moves = give_coins(node->right);
        num_moves+= abs(left_moves) + abs(right_moves);
        return node->val + left_moves + right_moves - 1;
    }
};