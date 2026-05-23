"""
Level 2: 參數化測試 (Parametrized Tests)
學習目標：測試 2D 輸入的函式，練習矩陣相關測試案例設計
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0054-spiral-matrix")


@pytest.mark.medium
@pytest.mark.array
class TestSpiralMatrix:
    @pytest.mark.parametrize("matrix, expected", [
        ([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [1, 2, 3, 6, 9, 8, 7, 4, 5]),
        ([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]], [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]),
        ([[1]], [1]),
        ([[1, 2], [3, 4]], [1, 2, 4, 3]),
        ([[1, 2, 3]], [1, 2, 3]),
        ([[1], [2], [3]], [1, 2, 3]),
    ], ids=[
        "3x3_square",
        "3x4_rectangle",
        "1x1_single",
        "2x2_square",
        "1x3_single_row",
        "3x1_single_column",
    ])
    def test_spiral_order(self, matrix, expected):
        solution = Solution()
        assert solution.spiralOrder(matrix) == expected
