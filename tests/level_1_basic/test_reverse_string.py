"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：測試 in-place 修改的函式（回傳 None，修改原始輸入）
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0344-reverse-string")


@pytest.mark.easy
@pytest.mark.string
class TestReverseString:
    def setup_method(self):
        self.solution = Solution()

    def test_example_1(self):
        s = ["h", "e", "l", "l", "o"]
        self.solution.reverseString(s)
        assert s == ["o", "l", "l", "e", "h"]

    def test_example_2(self):
        s = ["H", "a", "n", "n", "a", "h"]
        self.solution.reverseString(s)
        assert s == ["h", "a", "n", "n", "a", "H"]

    def test_returns_none(self):
        s = ["a", "b"]
        result = self.solution.reverseString(s)
        assert result is None

    def test_single_char(self):
        s = ["a"]
        self.solution.reverseString(s)
        assert s == ["a"]

    def test_two_chars(self):
        s = ["a", "b"]
        self.solution.reverseString(s)
        assert s == ["b", "a"]

    def test_palindrome(self):
        s = ["a", "b", "a"]
        self.solution.reverseString(s)
        assert s == ["a", "b", "a"]
