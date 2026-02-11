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
    void valid(TreeNode* root, long long maxi, long long mini, bool &ans){
        if(root == nullptr){
            return;
        }

        if(root->val > mini && root->val < maxi){
            valid(root->left, root->val, mini, ans);
            valid(root->right, maxi, root->val, ans); 
        }
        else{
            ans = false;
        }
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        valid(root, LLONG_MAX, LLONG_MIN, ans);
        return ans;
    }
};