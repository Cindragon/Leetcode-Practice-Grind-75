class ListNode:
    def __init__(self, val=0, next=None):
        self.val=val
        self.next=next
class MyLinkedList:  
    def __init__(self):
        self.dummy_head=ListNode()
        self.size=0

    def get(self, index: int) -> int:
        if index<0 or index>self.size-1:
            return -1
        curr=self.dummy_head.next
        for i in range(index):
            curr=curr.next
        return curr.val

    def addAtHead(self, val: int) -> None:
        self.dummy_head.next=ListNode(val, self.dummy_head.next)
        self.size+=1

    def addAtTail(self, val: int) -> None:
        curr=self.dummy_head
        while curr.next:
            curr=curr.next
        curr.next=ListNode(val)
        self.size+=1

    def addAtIndex(self, index: int, val: int) -> None:
        if index<0 or index>self.size:
            return
        curr=self.dummy_head
        while index:
            curr=curr.next
            index-=1
        curr.next=ListNode(val, curr.next)
        self.size+=1

    def deleteAtIndex(self, index: int) -> None:
        if index<0 or index>=self.size:
            return
        curr=self.dummy_head
        for i in range(index):
            curr=curr.next
        curr.next=curr.next.next
        self.size-=1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)