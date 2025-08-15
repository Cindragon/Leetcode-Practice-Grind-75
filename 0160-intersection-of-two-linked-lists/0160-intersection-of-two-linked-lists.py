# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        currA=headA
        currB=headB
        lenA, lenB=0, 0
        while currA is not None:
            currA=currA.next
            lenA+=1
        while currB is not None:
            currB=currB.next
            lenB+=1
        currA, currB=headA, headB
        if lenB>lenA:
            lenA, lenB=lenB, lenA
            currA, currB=currB, currA

        gap=lenA-lenB
        while gap:
            currA=currA.next
            gap-=1
        """
        for _ in range(lenA-lenB):
            currA=currA.next
        """
        while currA is not None:
            if currA==currB:
                return currA
            currA=currA.next
            currB=currB.next
        return None