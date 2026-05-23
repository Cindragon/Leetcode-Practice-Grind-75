"""
Level 4: 進階測試 — Property-Based Testing (Hypothesis)
學習目標：用排列（permutation）性質驗證 anagram 判斷

性質 1：任何字串的排列都是它的 anagram
性質 2：字串自己是自己的 anagram
性質 3：加上不同字元後就不是 anagram
"""
import random
from hypothesis import given, strategies as st, assume
from helpers.solution_loader import load_solution

Solution = load_solution("0242-valid-anagram")


class TestValidAnagramProperty:
    @given(st.text(alphabet="abcdefghijklmnopqrstuvwxyz", min_size=1, max_size=50))
    def test_permutation_is_anagram(self, s):
        solution = Solution()
        t = list(s)
        random.shuffle(t)
        t = "".join(t)
        assert solution.isAnagram(s, t) is True

    @given(st.text(alphabet="abcdefghijklmnopqrstuvwxyz", min_size=0, max_size=50))
    def test_self_is_anagram(self, s):
        solution = Solution()
        assert solution.isAnagram(s, s) is True

    @given(st.text(alphabet="abcdefghijklmnopqrstuvwxyz", min_size=1, max_size=50))
    def test_different_length_not_anagram(self, s):
        solution = Solution()
        assert solution.isAnagram(s, s + "z") is False
