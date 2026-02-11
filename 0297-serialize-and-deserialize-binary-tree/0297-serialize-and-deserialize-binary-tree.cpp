/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        queue<TreeNode*> q;

        if(root == NULL) return "";
        
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node == NULL){
                    ans.push_back("N");
                    continue;
                }

                ans.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            }
        }

        string s = "";
        for(int i=0; i<ans.size(); i++){
            s += ans[i];
            if(i < ans.size()-1) s += ',';
        }
        // cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        vector<string> arr;
        stringstream ss(data);
        string temp;

        while(getline(ss, temp, ',')){
            arr.push_back(temp);
        }

        if(arr[0] == "N"){
            return NULL;
        }

        int index = 0;
        TreeNode* root = new TreeNode(stoi(arr[0]));
        index++;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && index < arr.size()){
            TreeNode* node = q.front();
            q.pop();

            if(arr[index] != "N"){
                node->left = new TreeNode(stoi(arr[index]));
                q.push(node->left);
            }
            index++;

            if(arr[index] != "N"){
                node->right = new TreeNode(stoi(arr[index]));
                q.push(node->right);
            }
            index++;
        }

        return root;
    }
};
