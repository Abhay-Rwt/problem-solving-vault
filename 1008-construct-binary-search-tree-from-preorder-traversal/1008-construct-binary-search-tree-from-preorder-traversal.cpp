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
    TreeNode* constructBST(int &index, vector<int> &preorder, int maxi, int mini){
        if(index >= preorder.size() || preorder[index] < mini || preorder[index] > maxi) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        
        root->left = constructBST(index, preorder, root->val, mini);

        root->right = constructBST(index, preorder, maxi, root->val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        TreeNode* root = constructBST(index, preorder, INT_MAX, INT_MIN);
        return root;
    }
};