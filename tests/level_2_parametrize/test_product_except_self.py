"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：測試陣列輸出的函式，理解含零情況的測試設計
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0238-product-of-array-except-self")


@pytest.mark.medium
@pytest.mark.array
class TestProductExceptSelf:
    @pytest.mark.parametrize("nums, expected", [
        ([1, 2, 3, 4], [24, 12, 8, 6]),
        ([-1, 1, 0, -3, 3], [0, 0, 9, 0, 0]),
        ([0, 0], [0, 0]),
        ([1, 0], [0, 1]),
        ([2, 3], [3, 2]),
        ([1, 1, 1, 1], [1, 1, 1, 1]),
        ([-1, -1], [-1, -1]),
    ], ids=[
        "example_1",
        "example_2_with_zero",
        "two_zeros",
        "one_zero",
        "two_elements",
        "all_ones",
        "negative_numbers",
    ])
    def test_product_except_self(self, nums, expected):
        solution = Solution()
        assert solution.productExceptSelf(nums) == expected
