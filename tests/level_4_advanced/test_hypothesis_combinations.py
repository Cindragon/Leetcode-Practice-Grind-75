"""
Level 4: 進階測試 — Property-Based Testing (Hypothesis)
學習目標：用組合數學公式驗證 backtracking 結果

性質 1：C(n, k) 的結果數量 = n! / (k! * (n-k)!)
性質 2：每個組合的長度 = k
性質 3：組合中沒有重複
性質 4：所有元素都在 [1, n] 範圍內
"""
import math
from hypothesis import given, settings, strategies as st
from helpers.solution_loader import load_solution


class TestCombinationsProperty:
    @given(st.integers(min_value=1, max_value=10), st.data())
    @settings(max_examples=30)
    def test_result_count_matches_formula(self, n, data):
        k = data.draw(st.integers(min_value=1, max_value=n))
        Solution = load_solution("0077-combinations")
        solution = Solution()
        result = solution.combine(n, k)
        expected_count = math.comb(n, k)
        assert len(result) == expected_count

    @given(st.integers(min_value=1, max_value=8), st.data())
    @settings(max_examples=20)
    def test_each_combination_has_correct_length(self, n, data):
        k = data.draw(st.integers(min_value=1, max_value=n))
        Solution = load_solution("0077-combinations")
        solution = Solution()
        result = solution.combine(n, k)
        for combo in result:
            assert len(combo) == k

    @given(st.integers(min_value=1, max_value=8), st.data())
    @settings(max_examples=20)
    def test_no_duplicate_combinations(self, n, data):
        k = data.draw(st.integers(min_value=1, max_value=n))
        Solution = load_solution("0077-combinations")
        solution = Solution()
        result = solution.combine(n, k)
        tuples = [tuple(sorted(c)) for c in result]
        assert len(tuples) == len(set(tuples))

    @given(st.integers(min_value=1, max_value=8), st.data())
    @settings(max_examples=20)
    def test_elements_in_valid_range(self, n, data):
        k = data.draw(st.integers(min_value=1, max_value=n))
        Solution = load_solution("0077-combinations")
        solution = Solution()
        result = solution.combine(n, k)
        for combo in result:
            for val in combo:
                assert 1 <= val <= n
