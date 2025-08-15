# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead=ListNode(0)
        dummyHead.next=head
        curr=dummyHead
        while curr.next is not None and curr.next.next is not None:
            first=curr.next
            second=curr.next.next
            curr.next=second
            first.next=second.next
            second.next=first
            curr=first
        return dummyHead.next