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

    int diameterOfTree(TreeNode* root, int& diameter){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return 0;
        }

        int leftDiamater = diameterOfTree(root->left, diameter);
        int rightDiamater = diameterOfTree(root->right, diameter);

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
        int diameter = 0;
        diameterOfTree(root, diameter);
        return diameter;
    }
};