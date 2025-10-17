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
    unordered_map<long long, int> mp;   //計算每個前綴和出現幾次
    int traversal(TreeNode* root, long long currSum, int targetSum){
        if(!root)   return 0;
        currSum+=root->val;
        int count=0;
        if(mp.count(currSum-targetSum)){
            count+=mp[currSum-targetSum];
        }
        mp[currSum]++;
        count+=traversal(root->left, currSum, targetSum);
        count+=traversal(root->right, currSum, targetSum);
        mp[currSum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        return traversal(root, 0, targetSum);
    }
};

/*
*/