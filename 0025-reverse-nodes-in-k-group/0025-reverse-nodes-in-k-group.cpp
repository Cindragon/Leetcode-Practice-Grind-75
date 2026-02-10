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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2||!head) return head;
        int count=0;
        ListNode* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }

        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* prev=dummyHead;
        while(count>=k){
            ListNode* curr=prev->next;
            ListNode* next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummyHead->next;
    }
};

/*
使用 DummyHead 方便處理第一組反轉
先計算 linked list 的總長度，用來判斷是否還能反轉 k 個節點

prev 指向「前一組反轉後的尾巴」
每一組開始時：
- curr = prev->next，為本組反轉前的頭（反轉後會變成尾巴）
- next = curr->next，為即將被移到前面的節點

for 迴圈中使用「頭插法」：
每次把 next 節點搬到 prev 後面
curr 始終不動，負責接剩下尚未反轉的節點

一組完成後：
prev 移到 curr（本組反轉後的尾巴）
*/