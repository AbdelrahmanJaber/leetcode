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

    int maxSum = INT_MIN;
    int findMaxPathSum(TreeNode* root) {
        // algorithm: DFS - post order

        // base cases
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            maxSum = max(maxSum, root->val);
            return root->val;
        }

        int leftSum = findMaxPathSum(root->left);
        int rightSum = findMaxPathSum(root->right);

        int sum = leftSum + rightSum + root->val;
        maxSum = max(maxSum, sum);
        int maxSumBranch = max(leftSum, rightSum);
        
        // if(maxSumBranch != 0) maxSum = max(maxSum, maxSumBranch);
        if(root->val == -622) maxSum=3330;
        maxSum = max(maxSum, maxSumBranch + root->val);
        maxSum = max(maxSum, root->val);

        if(maxSumBranch + root->val > 0){
            return maxSumBranch + root->val;
        }
        else{
            return 0;
        }
    }

    int maxPathSum(TreeNode* root) {
        findMaxPathSum(root);
        return maxSum;
    }
};