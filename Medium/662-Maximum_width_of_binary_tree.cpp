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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned int maxWidth = 0;
        if(!root) return maxWidth;

        queue<pair<unsigned int, TreeNode*>> q;
        q.push({1,root});

        while(!q.empty())
        {
            unsigned int size = q.size();
            unsigned int leftNode = q.front().first;
            unsigned int rightNode = q.back().first;
            unsigned int width = rightNode - leftNode + 1;
            maxWidth = max(width, maxWidth);

            while(size--){
                unsigned int frontIndex = q.front().first;
                TreeNode* frontNode = q.front().second;
                q.pop();

                if(frontNode->left) q.push({2*frontIndex, frontNode->left});
                if(frontNode->right) q.push({(2*frontIndex)+1,frontNode->right});
            }
        }
        return maxWidth;
    }
};