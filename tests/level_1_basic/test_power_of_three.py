"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：測試數學類問題，理解多種邊界值
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0326-power-of-three")


@pytest.mark.easy
class TestPowerOfThree:
    def setup_method(self):
        self.solution = Solution()

    def test_27_is_power(self):
        assert self.solution.isPowerOfThree(27) is True

    def test_0_is_not_power(self):
        assert self.solution.isPowerOfThree(0) is False

    def test_negative_is_not_power(self):
        assert self.solution.isPowerOfThree(-3) is False

    def test_1_is_power(self):
        assert self.solution.isPowerOfThree(1) is True

    def test_9_is_power(self):
        assert self.solution.isPowerOfThree(9) is True

    def test_10_is_not_power(self):
        assert self.solution.isPowerOfThree(10) is False

    def test_large_power(self):
        assert self.solution.isPowerOfThree(3**10) is True

    def test_non_power_close_to_power(self):
        assert self.solution.isPowerOfThree(28) is False
