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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* fast=dummyHead;
        ListNode* slow=dummyHead;
        for(int i=0;i<n+1;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* del=slow->next;
        slow->next=del->next;
        delete del;
        return dummyHead->next;
    }
};

/*
用快慢指針
快指針多走n+1步
這樣在快指針指向節點時
慢指針剛好指向要刪除的前一個節點
*/