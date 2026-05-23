"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：使用 @pytest.mark.parametrize 減少重複程式碼，處理順序無關的比較
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0015-3sum")


def sorted_triplets(result):
    return sorted([sorted(x) for x in result])


@pytest.mark.medium
@pytest.mark.array
class TestThreeSum:
    @pytest.mark.parametrize("nums, expected", [
        ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        ([0, 1, 1], []),
        ([0, 0, 0], [[0, 0, 0]]),
        ([0, 0, 0, 0], [[0, 0, 0]]),
        ([-2, 0, 1, 1, 2], [[-2, 0, 2], [-2, 1, 1]]),
        ([1, 2, 3], []),
        ([-1, -1, -1, 2], [[-1, -1, 2]]),
        ([-2, 0, 1, 1, 1, 2], [[-2, 0, 2], [-2, 1, 1]]),
        ([-3, 0, 1, 2, 2], [[-3, 1, 2]]),
    ], ids=[
        "example_1_mixed",
        "example_2_no_solution",
        "example_3_all_zeros",
        "four_zeros",
        "multiple_solutions",
        "all_positive",
        "duplicate_negatives",
        "right_side_duplicates",
        "right_skip_duplicates",
    ])
    def test_three_sum(self, nums, expected):
        solution = Solution()
        result = solution.threeSum(nums)
        assert sorted_triplets(result) == sorted_triplets(expected)
