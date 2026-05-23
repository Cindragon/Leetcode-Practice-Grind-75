"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：使用 ids 讓測試輸出更易讀，測試最佳化問題
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0011-container-with-most-water")


@pytest.mark.medium
@pytest.mark.array
class TestContainerWithMostWater:
    @pytest.mark.parametrize("height, expected", [
        ([1, 8, 6, 2, 5, 4, 8, 3, 7], 49),
        ([1, 1], 1),
        ([4, 3, 2, 1, 4], 16),
        ([1, 2, 1], 2),
        ([1, 8, 100, 2, 100, 4, 8, 3, 7], 200),
        ([10000, 10000], 10000),
    ], ids=[
        "example_1",
        "minimum_two_elements",
        "symmetric_ends",
        "small_array",
        "tall_middle_bars",
        "two_tall_bars",
    ])
    def test_max_area(self, height, expected):
        solution = Solution()
        assert solution.maxArea(height) == expected
