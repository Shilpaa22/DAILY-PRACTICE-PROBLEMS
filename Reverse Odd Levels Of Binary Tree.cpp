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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> pq;
        pq.push(root);
        int level = 1;
        while(!pq.empty()){
            int size = pq.size();
            vector<TreeNode*> temp;
            for(int i=0 ; i < size ; i++){
                TreeNode* node = pq.front();
                pq.pop();
                if(node -> left) pq.push(node->left);
                if(node -> right) pq.push(node->right);
                if(level % 2 != 0){
                   if(node -> left) temp.push_back(node->left);
                   if(node -> right) temp.push_back(node->right);
                }
            }
            
            if(level % 2 != 0){
                int l = 0;
                int r = temp.size()-1;
                while(l < r){
                    swap(temp[l] -> val,temp[r] -> val);
                    l++;
                    r--;
                }
            }
            level++;
        }

        return root;
        
    }
};