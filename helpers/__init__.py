from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode({self.val})"


def list_to_linked_list(lst):
    if not lst:
        return None
    head = ListNode(lst[0])
    curr = head
    for val in lst[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head


def linked_list_to_list(head):
    result = []
    curr = head
    while curr:
        result.append(curr.val)
        curr = curr.next
    return result


def create_cycle(lst, pos):
    if not lst:
        return None
    head = list_to_linked_list(lst)
    if pos == -1:
        return head
    cycle_entry = None
    tail = head
    idx = 0
    while tail.next:
        if idx == pos:
            cycle_entry = tail
        tail = tail.next
        idx += 1
    if idx == pos:
        cycle_entry = tail
    tail.next = cycle_entry
    return head
