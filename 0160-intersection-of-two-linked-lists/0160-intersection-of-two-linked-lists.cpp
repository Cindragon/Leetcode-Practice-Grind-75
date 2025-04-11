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

/*
先查看兩個鍊結的長度(m&n)，看誰比較長
比較長的那條先多走abs(m-n)步(終點對齊)，接下來兩條一起走
不是 val 相等，而是地址相等(headA==headB)才回傳
都沒相交就回傳nullptr
重點：讓兩條鏈「從同一距離」開始走，就能準確找出交點！
*/