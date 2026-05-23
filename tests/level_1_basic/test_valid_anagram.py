"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：測試回傳 bool 的函式，理解 True/False 斷言
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0242-valid-anagram")


@pytest.mark.easy
@pytest.mark.string
class TestValidAnagram:
    def setup_method(self):
        self.solution = Solution()

    def test_example_1_is_anagram(self):
        assert self.solution.isAnagram("anagram", "nagaram") is True

    def test_example_2_not_anagram(self):
        assert self.solution.isAnagram("rat", "car") is False

    def test_empty_strings(self):
        assert self.solution.isAnagram("", "") is True

    def test_single_char_same(self):
        assert self.solution.isAnagram("a", "a") is True

    def test_single_char_different(self):
        assert self.solution.isAnagram("a", "b") is False

    def test_different_length(self):
        assert self.solution.isAnagram("ab", "abc") is False

    def test_same_chars_different_count(self):
        assert self.solution.isAnagram("aab", "abb") is False

    def test_reversed_string(self):
        assert self.solution.isAnagram("abcde", "edcba") is True
