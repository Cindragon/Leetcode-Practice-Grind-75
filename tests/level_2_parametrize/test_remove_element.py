"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：測試 in-place + 回傳值的函式，需同時驗證回傳值與陣列內容
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0027-remove-element")


@pytest.mark.easy
@pytest.mark.array
class TestRemoveElement:
    @pytest.mark.parametrize("nums, val, expected_k, expected_remaining", [
        ([3, 2, 2, 3], 3, 2, [2, 2]),
        ([0, 1, 2, 2, 3, 0, 4, 2], 2, 5, [0, 0, 1, 3, 4]),
        ([], 1, 0, []),
        ([1], 1, 0, []),
        ([1], 2, 1, [1]),
        ([2, 2, 2], 2, 0, []),
        ([1, 2, 3, 4, 5], 6, 5, [1, 2, 3, 4, 5]),
    ], ids=[
        "example_1",
        "example_2",
        "empty_array",
        "single_match",
        "single_no_match",
        "all_match",
        "none_match",
    ])
    def test_remove_element(self, nums, val, expected_k, expected_remaining):
        solution = Solution()
        k = solution.removeElement(nums, val)
        assert k == expected_k
        assert sorted(nums[:k]) == sorted(expected_remaining)
