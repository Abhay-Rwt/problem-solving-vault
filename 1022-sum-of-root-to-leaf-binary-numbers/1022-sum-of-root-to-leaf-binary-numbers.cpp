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
    vector<string> paths;

    int find_deci(string &str){
        int deci = 0;
        for(char &ch: str){
            deci = (deci << 1) | (ch - '0');
        }
        return deci;
    }

    void solve(TreeNode* root, string path){
        if(root == NULL) return;

        path.push_back(root->val + '0');

        if(root->left == NULL && root->right == NULL){
            paths.push_back(path);   
            return; 
        }

        solve(root->left, path);
        solve(root->right, path);
    }

    int sumRootToLeaf(TreeNode* root) {
        solve(root, "");

        int sum = 0;
        for(auto it: paths) {
            int deci = find_deci(it);
            sum += deci;
        }

        return sum;
    }
};