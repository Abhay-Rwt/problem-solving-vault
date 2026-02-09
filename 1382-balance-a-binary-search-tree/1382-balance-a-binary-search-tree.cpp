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
private:
    void getInorder(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return;
        
        getInorder(root->left, inorder);
        
        inorder.push_back(root->val);

        getInorder(root->right, inorder);
    }

    TreeNode* solve(int start, int end, vector<int>& inorder){
        if(start > end) return NULL;

        int mid = (start+end)/2;

        TreeNode* node = new TreeNode(inorder[mid]);

        node->left = solve(start, mid-1, inorder);

        node->right = solve(mid+1, end, inorder);

        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);

        TreeNode* node = NULL;

        node = solve(0, inorder.size()-1, inorder);

        return node;
    }
};