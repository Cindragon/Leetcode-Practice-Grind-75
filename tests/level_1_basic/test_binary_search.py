"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：測試回傳 int 的函式，理解邊界條件

注意：原始解法 0792-binary-search.py 第 6 行有 bug
  mid=left+right-left//2  應為  mid=left+(right-left)//2
這是一個「測試發現 bug」的好範例。如果測試失敗，請先修正解法。
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0792-binary-search")


@pytest.mark.easy
@pytest.mark.array
class TestBinarySearch:
    def setup_method(self):
        self.solution = Solution()

    def test_example_1_found(self):
        assert self.solution.search([-1, 0, 3, 5, 9, 12], 9) == 4

    def test_example_2_not_found(self):
        assert self.solution.search([-1, 0, 3, 5, 9, 12], 2) == -1

    def test_single_element_found(self):
        assert self.solution.search([5], 5) == 0

    def test_single_element_not_found(self):
        assert self.solution.search([5], 3) == -1

    def test_first_element(self):
        assert self.solution.search([1, 2, 3, 4, 5], 1) == 0

    def test_last_element(self):
        assert self.solution.search([1, 2, 3, 4, 5], 5) == 4

    def test_negative_numbers(self):
        assert self.solution.search([-10, -5, -3, 0, 2], -5) == 1

    def test_two_elements(self):
        assert self.solution.search([1, 3], 3) == 1
