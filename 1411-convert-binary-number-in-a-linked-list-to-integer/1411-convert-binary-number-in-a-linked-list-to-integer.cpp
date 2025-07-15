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
    int getDecimalValue(ListNode* head) {
        vector<int> sum;
        while(head!=NULL){
            sum.push_back(head->val);
            head=head->next;
        }
        int ans=0, exp=0;
        for(int i=sum.size()-1;i>=0;i--){
            ans+=sum[i]*pow(2, exp);
            exp++;
        }
        return ans;
    }
};