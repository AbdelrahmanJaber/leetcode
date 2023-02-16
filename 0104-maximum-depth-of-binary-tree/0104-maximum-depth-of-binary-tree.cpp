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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return max(1+maxDepth(root->left), 1+maxDepth(root->right));
    }
};

// Time complexity = O(N), where N: number of nodes in the tree

// Space complexity = O(N) in the worst case if the tree is unbalanced(all the nodes in the left sub tree or 
// right sub tree), O(log N) in the best case if the tree is balanced