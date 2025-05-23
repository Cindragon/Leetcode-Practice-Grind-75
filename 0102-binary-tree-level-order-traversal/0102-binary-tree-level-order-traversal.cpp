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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        int size;
        while(!que.empty()){
            size=que.size();
            vector<int> vec;
            while(size--){
                TreeNode* node=que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left!=NULL) que.push(node->left);
                if(node->right!=NULL) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

/*
用佇列+迴圈的方式來進行層次遍歷
先儲存root節點，然後用size記錄每次佇列的大小
size--的同時，用node記錄que的最前端(也就是每一層第一個被加進去的節點)並彈出佇列
然後用vector儲存node的val
如果node的left跟right不為NULL，則加到佇列中，並且先把每次儲存的vector加到result
最後回傳result(每層的節點值)

*/