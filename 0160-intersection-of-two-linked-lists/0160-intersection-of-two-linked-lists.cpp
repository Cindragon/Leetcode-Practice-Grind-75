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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0, n=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1){
            m++;
            temp1=temp1->next;
        }
        while(temp2){
            n++;
            temp2=temp2->next;
        }
        while(m>n){
            headA=headA->next;
            m--;
        }
        while(n>m){
            headB=headB->next;
            n--;
        }
        while(headA&&headB){
            if(headA==headB) return headA;
            else{
                headA=headA->next;
                headB=headB->next;
            }
        }
        return nullptr;
    }
};