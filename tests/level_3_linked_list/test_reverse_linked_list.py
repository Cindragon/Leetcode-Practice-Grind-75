"""
Level 3: Fixture 與資料結構 (Fixtures & Data Structures)
學習目標：使用 conftest.py 中的 fixture，測試 Linked List 題目
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0206-reverse-linked-list")


@pytest.mark.easy
@pytest.mark.linked_list
class TestReverseLinkedList:
    def test_example_1(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4, 5])
        result = Solution().reverseList(head)
        assert_linked_list_equal(result, [5, 4, 3, 2, 1])

    def test_example_2(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2])
        result = Solution().reverseList(head)
        assert_linked_list_equal(result, [2, 1])

    def test_empty_list(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([])
        result = Solution().reverseList(head)
        assert_linked_list_equal(result, [])

    def test_single_node(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1])
        result = Solution().reverseList(head)
        assert_linked_list_equal(result, [1])
