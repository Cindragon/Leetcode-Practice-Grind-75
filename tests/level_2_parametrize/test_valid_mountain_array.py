"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：設計全面的邊界測試，理解「山形」的各種不合法情況
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0978-valid-mountain-array")


@pytest.mark.easy
@pytest.mark.array
class TestValidMountainArray:
    @pytest.mark.parametrize("arr, expected", [
        ([2, 1], False),
        ([3, 5, 5], False),
        ([0, 3, 2, 1], True),
        ([0, 1, 2, 3, 4, 5, 4, 3, 2, 1], True),
        ([1, 2, 3], False),
        ([3, 2, 1], False),
        ([1], False),
        ([1, 2], False),
        ([1, 3, 2], True),
        ([1, 1, 1], False),
    ], ids=[
        "example_1_too_short_desc",
        "example_2_plateau",
        "example_3_valid",
        "long_valid_mountain",
        "only_ascending",
        "only_descending",
        "single_element",
        "two_elements",
        "minimum_valid_mountain",
        "all_same",
    ])
    def test_valid_mountain(self, arr, expected):
        solution = Solution()
        assert solution.validMountainArray(arr) == expected
