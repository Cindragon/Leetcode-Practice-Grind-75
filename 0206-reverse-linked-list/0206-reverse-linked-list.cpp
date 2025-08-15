/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* temp=curr->next;  //保存下一個節點
            curr->next=pre; //開始反轉
            pre=curr;   //pre 向前移動
            curr=temp;  //cur 也向前移動
        }
        return pre;
    }
};