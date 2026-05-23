"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：撰寫第一個 pytest 測試，理解 assert 語法
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0001-two-sum")


@pytest.mark.easy
@pytest.mark.array
class TestTwoSum:
    def setup_method(self):
        self.solution = Solution()

    def test_example_1(self):
        result = self.solution.twoSum([2, 7, 11, 15], 9)
        assert sorted(result) == [0, 1]

    def test_example_2(self):
        result = self.solution.twoSum([3, 2, 4], 6)
        assert sorted(result) == [1, 2]

    def test_example_3(self):
        result = self.solution.twoSum([3, 3], 6)
        assert sorted(result) == [0, 1]

    def test_negative_numbers(self):
        result = self.solution.twoSum([-1, -2, -3, -4, -5], -8)
        assert sorted(result) == [2, 4]

    def test_minimum_length(self):
        result = self.solution.twoSum([0, 0], 0)
        assert sorted(result) == [0, 1]

    def test_large_target(self):
        result = self.solution.twoSum([1000000, 999999, 1], 1000001)
        assert sorted(result) == [0, 2]
