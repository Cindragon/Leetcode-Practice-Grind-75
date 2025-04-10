/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||head->next==nullptr) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* curr=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                while(curr!=slow){
                    curr=curr->next;
                    slow=slow->next;
                }
                return curr;
            }
        }
    return nullptr;
    }
};

/*
先用快慢指針（Floyd’s Cycle Detection Algorithm ）判斷是否有環，沒環的話回傳NULL
有環相遇之後，用一個節點curr指向head
然後在 curr!=slow 的時候，curr跟slow都一步步往下走
最後相遇的時候會就會是入口！
*/