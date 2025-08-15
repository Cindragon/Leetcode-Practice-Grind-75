# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummyHead=ListNode(0)
        dummyHead.next=head
        fast=dummyHead
        slow=dummyHead
        while n>0 and fast is not None:
            fast=fast.next
            n-=1
        fast=fast.next  #fast 多走一步，slow 就會指到要刪的前一個節點
        while fast is not None:
            fast=fast.next
            slow=slow.next
        slow.next=slow.next.next
        return dummyHead.next