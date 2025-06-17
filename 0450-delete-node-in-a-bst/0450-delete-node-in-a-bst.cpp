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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL; 
            }
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* node=root->left;
                delete root;
                return node;
            }
            else if(root->left==NULL&&root->right!=NULL){
                TreeNode* node=root->right;
                delete root;
                return node;
            }
            else{
                TreeNode* cur=root->right;
                while(cur->left){
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* temp=root;
                root=root->right;
                delete temp;
                return root;
            }
        }
        if(key<root->val){
            root->left=deleteNode(root->left, key);
        }
        if(key>root->val){
            root->right=deleteNode(root->right, key);
        }
        return root;
    }
};

/*
終止條件是要找到刪除的節點
刪除節點的時候有五種情況要考慮
    1. 找不到要刪的節點：return NULL
    2. 要刪除的節點是葉子節點(左右皆為空)：這時候一樣回傳NULL，並且刪除節點
    3. 刪除的節點左不為空，右為空：用一個節點儲存刪除節點的左子樹，刪除節點後回傳儲存的左子樹
    4. 刪除的節點左為空，右不為空：相同邏輯
    5. 刪除的節點左右皆不為空：統一將左子樹接在右子樹最左下方的位置(其值最接近root->val)
    為了找到要接上的點，用cur來儲存root->right，接著找到cur左子樹的盡頭
    接下來用temp儲存root的節點，讓root=root->right之後刪除temp(原本就要刪除的節點)
    最後回傳root(修改過後的二元樹)
在單層邏輯中則是一樣比較root跟key的值
並且看要向左還是向右遍歷
最後回傳root
*/