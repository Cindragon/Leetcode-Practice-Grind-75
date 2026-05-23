"""
Level 3: Fixture 與資料結構
學習目標：測試帶範圍參數（left, right）的 Linked List 操作
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0092-reverse-linked-list-ii")


@pytest.mark.medium
@pytest.mark.linked_list
class TestReverseBetween:
    def test_example_1(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4, 5])
        result = Solution().reverseBetween(head, 2, 4)
        assert_linked_list_equal(result, [1, 4, 3, 2, 5])

    def test_single_node(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([5])
        result = Solution().reverseBetween(head, 1, 1)
        assert_linked_list_equal(result, [5])

    def test_reverse_entire_list(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().reverseBetween(head, 1, 3)
        assert_linked_list_equal(result, [3, 2, 1])

    def test_reverse_from_head(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4, 5])
        result = Solution().reverseBetween(head, 1, 3)
        assert_linked_list_equal(result, [3, 2, 1, 4, 5])

    def test_reverse_to_tail(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4, 5])
        result = Solution().reverseBetween(head, 3, 5)
        assert_linked_list_equal(result, [1, 2, 5, 4, 3])

    def test_same_left_right(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().reverseBetween(head, 2, 2)
        assert_linked_list_equal(result, [1, 2, 3])
