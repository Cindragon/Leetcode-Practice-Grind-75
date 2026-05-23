"""
Level 3: Fixture 與資料結構
學習目標：測試節點交換操作，奇偶長度的邊界案例
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0024-swap-nodes-in-pairs")


@pytest.mark.medium
@pytest.mark.linked_list
class TestSwapNodesInPairs:
    def test_example_1(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3, 4])
        result = Solution().swapPairs(head)
        assert_linked_list_equal(result, [2, 1, 4, 3])

    def test_empty_list(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([])
        result = Solution().swapPairs(head)
        assert_linked_list_equal(result, [])

    def test_single_node(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1])
        result = Solution().swapPairs(head)
        assert_linked_list_equal(result, [1])

    def test_odd_length(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2, 3])
        result = Solution().swapPairs(head)
        assert_linked_list_equal(result, [2, 1, 3])

    def test_two_nodes(self, make_linked_list, assert_linked_list_equal):
        head = make_linked_list([1, 2])
        result = Solution().swapPairs(head)
        assert_linked_list_equal(result, [2, 1])
