"""
Level 4: 進階測試 — Property-Based Testing (Hypothesis)
學習目標：用數學性質驗證程式正確性，不需要手動列舉測試案例

性質 1：反轉兩次 = 原陣列（involution）
性質 2：反轉不改變長度
性質 3：反轉不改變元素集合
"""
from hypothesis import given, strategies as st
from helpers.solution_loader import load_solution

Solution = load_solution("0344-reverse-string")


class TestReverseStringProperty:
    @given(st.lists(st.sampled_from(list("abcdefghijklmnopqrstuvwxyz")), min_size=0, max_size=100))
    def test_reverse_twice_is_identity(self, chars):
        solution = Solution()
        original = chars[:]
        solution.reverseString(chars)
        solution.reverseString(chars)
        assert chars == original

    @given(st.lists(st.sampled_from(list("abcdefghijklmnopqrstuvwxyz")), min_size=0, max_size=100))
    def test_reverse_preserves_length(self, chars):
        solution = Solution()
        original_len = len(chars)
        solution.reverseString(chars)
        assert len(chars) == original_len

    @given(st.lists(st.sampled_from(list("abcdefghijklmnopqrstuvwxyz")), min_size=0, max_size=100))
    def test_reverse_preserves_elements(self, chars):
        solution = Solution()
        original_sorted = sorted(chars)
        solution.reverseString(chars)
        assert sorted(chars) == original_sorted
