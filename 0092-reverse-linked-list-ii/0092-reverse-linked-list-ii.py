# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head is None or left==right:
            return head
        dummyHead=ListNode(0)
        dummyHead.next=head
        pre=dummyHead
        for i in range(1, left):
            pre=pre.next
        nextNode=None
        temp=pre.next
        for i in range(0, right-left, +1):
            nextNode=temp.next
            temp.next=nextNode.next
            nextNode.next=pre.next
            pre.next=nextNode
        return dummyHead.next

        