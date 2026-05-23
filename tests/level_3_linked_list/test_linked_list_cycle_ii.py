"""
Level 3: Fixture 與資料結構
學習目標：使用 make_cycled_list fixture，測試環形 Linked List（不能用 to_list 轉換）
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0142-linked-list-cycle-ii")


@pytest.mark.medium
@pytest.mark.linked_list
class TestLinkedListCycleII:
    def test_cycle_at_pos_1(self, make_cycled_list):
        head = make_cycled_list([3, 2, 0, -4], 1)
        result = Solution().detectCycle(head)
        assert result is not None
        assert result.val == 2

    def test_cycle_at_pos_0(self, make_cycled_list):
        head = make_cycled_list([1, 2], 0)
        result = Solution().detectCycle(head)
        assert result is not None
        assert result.val == 1

    def test_no_cycle(self, make_cycled_list):
        head = make_cycled_list([1], -1)
        result = Solution().detectCycle(head)
        assert result is None

    def test_no_cycle_multiple_nodes(self, make_linked_list):
        head = make_linked_list([1, 2, 3, 4])
        result = Solution().detectCycle(head)
        assert result is None

    def test_cycle_at_tail(self, make_cycled_list):
        head = make_cycled_list([1, 2, 3], 2)
        result = Solution().detectCycle(head)
        assert result is not None
        assert result.val == 3
