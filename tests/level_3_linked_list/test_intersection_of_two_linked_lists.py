"""
Level 3: Fixture 與資料結構
學習目標：手動建構共享尾部的兩條 Linked List，測試節點身份（identity）比較
"""
import pytest
from helpers import ListNode, list_to_linked_list
from helpers.solution_loader import load_solution

Solution = load_solution("0160-intersection-of-two-linked-lists")


def build_intersecting_lists(list_a_vals, list_b_vals, shared_vals):
    shared = list_to_linked_list(shared_vals)

    head_a = list_to_linked_list(list_a_vals)
    if head_a:
        curr = head_a
        while curr.next:
            curr = curr.next
        curr.next = shared
    else:
        head_a = shared

    head_b = list_to_linked_list(list_b_vals)
    if head_b:
        curr = head_b
        while curr.next:
            curr = curr.next
        curr.next = shared
    else:
        head_b = shared

    return head_a, head_b, shared


@pytest.mark.easy
@pytest.mark.linked_list
class TestIntersectionOfTwoLinkedLists:
    def test_has_intersection(self):
        head_a, head_b, shared = build_intersecting_lists([4, 1], [5, 6, 1], [8, 4, 5])
        result = Solution().getIntersectionNode(head_a, head_b)
        assert result is shared

    def test_no_intersection(self):
        head_a = list_to_linked_list([2, 6, 4])
        head_b = list_to_linked_list([1, 5])
        result = Solution().getIntersectionNode(head_a, head_b)
        assert result is None

    def test_intersection_at_first_node(self):
        head_a, head_b, shared = build_intersecting_lists([], [], [1, 2, 3])
        result = Solution().getIntersectionNode(head_a, head_b)
        assert result is shared

    def test_single_shared_node(self):
        head_a, head_b, shared = build_intersecting_lists([1], [2, 3], [99])
        result = Solution().getIntersectionNode(head_a, head_b)
        assert result is shared
