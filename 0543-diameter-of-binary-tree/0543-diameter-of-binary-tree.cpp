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
    int diameter = 0;

    int diameterOfTree(TreeNode* root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        }

        int leftDiamater = diameterOfTree(root->left);
        int rightDiamater = diameterOfTree(root->right);

        if(root -> left && root -> right){
            diameter = max(diameter, leftDiamater + rightDiamater + 2);
            return max(leftDiamater, rightDiamater) + 1;
        }
        else {
            diameter = max(diameter, leftDiamater + rightDiamater + 1);
            return max(leftDiamater, rightDiamater) + 1;
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfTree(root);
        return diameter;
    }
};