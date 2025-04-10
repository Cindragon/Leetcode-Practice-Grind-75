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
        return reverse(head, NULL);
    }
    ListNode* reverse(ListNode* curr, ListNode* pre){
        if(curr==NULL) return pre;
        ListNode* temp=curr->next;
        curr->next=pre;
        return reverse(temp, curr);
    }
};
/*
用雙指針跟遞迴的方式寫

雙指針：
有 curr、temp(存下一個要反轉的指針)、pre(最後回傳的頭)
curr=head (if head==NULL) return NULL
while(curr!=NULL)
temp=curr->next 
curr->next=pre
pre=curr
curr=temp
最後回傳 pre

遞迴：
reverese的函式(curr, NULL(pre))
if(curr==NULL)(反轉完成) return pre
temp=curr->next
curr->next=pre
return reverse(temp, curr)
*/
