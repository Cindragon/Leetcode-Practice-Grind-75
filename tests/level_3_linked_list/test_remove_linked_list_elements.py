"""
Level 3: Fixture 與資料結構
學習目標：fixture 組合使用，測試帶目標值參數的 Linked List 操作
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0203-remove-linked-list-elements")


@pytest.mark.easy
@pytest.mark.linked_list
class TestRemoveLinkedListElements:
    def test_example_1(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 6, 3, 4, 5, 6])
        result = Solution().removeElements(head, 6)
        assert_linked_list_equal(result, [1, 2, 3, 4, 5])

    def test_empty_list(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([])
        result = Solution().removeElements(head, 1)
        assert_linked_list_equal(result, [])

    def test_all_same_value(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([7, 7, 7, 7])
        result = Solution().removeElements(head, 7)
        assert_linked_list_equal(result, [])

    def test_remove_head(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().removeElements(head, 1)
        assert_linked_list_equal(result, [2, 3])

    def test_no_removal(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().removeElements(head, 4)
        assert_linked_list_equal(result, [1, 2, 3])
