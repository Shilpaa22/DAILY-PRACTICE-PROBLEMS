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
    unordered_map<int,int>mp;
    int find(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=find(root->left);
        int right=find(root->right);
        int sum=left+right+root->val;
        ++mp[sum];
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        mp.clear();
        find(root);
        int max_freq=0;
        for(auto it:mp)
        {
            max_freq=max(max_freq,it.second);
        }
        vector<int>v;
        for(auto it:mp)
        {
            if(it.second==max_freq)
            {
                v.push_back(it.first);
            }
        }
        return v;
    }
};