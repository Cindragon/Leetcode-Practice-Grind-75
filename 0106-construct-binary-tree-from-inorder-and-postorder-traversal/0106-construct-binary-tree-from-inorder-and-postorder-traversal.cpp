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
    TreeNode* Traversal(vector<int>& inorder, vector<int>& postorder){
        int rootvalue=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootvalue);
        if(postorder.size()==1) return root;
        int index;
        for(index=0;index<postorder.size();index++){
            if(inorder[index]==rootvalue) break;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        postorder.resize(postorder.size()-1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());
        root->left=buildTree(leftInorder, leftPostorder);
        root->right=buildTree(rightInorder, rightPostorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return NULL;
        return Traversal(inorder, postorder);
    }
};

/*
需要分成多個步驟來進行，一樣在最後使用遞歸法
1. 先找到根節點(後序的最後一個點)
2. 找到這個點在中序的位置(index)(要切割左子樹跟右子樹)
3. 把中序進行切割，切成左右子樹
4. 後序陣列要resize(為了去除根節點)，然後一樣進行切割(左右子樹的size會跟中序切割的左右子樹一樣)
5. root的左右子樹使用遞迴來建構
最後 return 建構好的樹
*/