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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        TreeNode* leftSubtree = root->left;
        root->left = root->right;
        root->right = leftSubtree;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Time complexity = O(N), where N: number of nodes in the tree
// Space complexity = O(h) = O(N) in the worst case if the tree is skewed. it will be O(log N) if the tree is balanced