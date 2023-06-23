/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // iterative approach
        TreeNode* LCA = root;

        while(true){
            if(p->val < LCA->val && q->val < LCA->val){
                LCA = LCA->left;
            }
            else if(p->val > LCA->val && q->val > LCA->val){
                LCA = LCA->right;
            }
            else{
                return LCA;
            }
        }

        return nullptr;
    }
};

// Time complexity = O(N), where N: number of nodes in the tree (in worst case we might visit the whole BST if it is skewed (all nodes are in the left or all nodes are in the right))
// Space complexity = O(1)