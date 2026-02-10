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
    void buildPar(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL) return;

        if(root->left != NULL){
            parent[root->left] = root;
            buildPar(root->left, parent);
        }
        
        if(root->right != NULL){
            parent[root->right] = root;
            buildPar(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;
        
        parent[root] = NULL;
        buildPar(root, parent);

        int size = parent.size();
        
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*,int> visited;

        q.push({target, 0});
        visited[target] = 1;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second;

            if(level == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left != NULL && !visited[node->left]){
                visited[node->left] = 1;
                q.push({node->left, level+1});
            }

            if(node->right != NULL && !visited[node->right]){
                visited[node->right] = 1;
                q.push({node->right, level+1});
            }

            if(parent[node] != NULL && !visited[parent[node]]){
                visited[parent[node]] = 1;
                q.push({parent[node], level+1});
            }
        }

        return ans;
    }
};