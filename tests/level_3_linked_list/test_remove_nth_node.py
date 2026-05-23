"""
Level 3: Fixture 與資料結構
學習目標：測試需要兩個參數（head + n）的 Linked List 操作
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0019-remove-nth-node-from-end-of-list")


@pytest.mark.medium
@pytest.mark.linked_list
class TestRemoveNthFromEnd:
    def test_example_1(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4, 5])
        result = Solution().removeNthFromEnd(head, 2)
        assert_linked_list_equal(result, [1, 2, 3, 5])

    def test_single_node_remove_first(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1])
        result = Solution().removeNthFromEnd(head, 1)
        assert_linked_list_equal(result, [])

    def test_two_nodes_remove_first(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2])
        result = Solution().removeNthFromEnd(head, 1)
        assert_linked_list_equal(result, [1])

    def test_remove_head_node(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2])
        result = Solution().removeNthFromEnd(head, 2)
        assert_linked_list_equal(result, [2])

    def test_remove_from_middle(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().removeNthFromEnd(head, 2)
        assert_linked_list_equal(result, [1, 3])
