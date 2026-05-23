"""
Level 1: 基本斷言 (Basic Assertions)
學習目標：與 Power of Three 對照學習，強化測試設計思維
"""
import pytest
from helpers.solution_loader import load_solution

Solution = load_solution("0342-power-of-four")


@pytest.mark.easy
class TestPowerOfFour:
    def setup_method(self):
        self.solution = Solution()

    def test_16_is_power(self):
        assert self.solution.isPowerOfFour(16) is True

    def test_5_is_not_power(self):
        assert self.solution.isPowerOfFour(5) is False

    def test_1_is_power(self):
        assert self.solution.isPowerOfFour(1) is True

    def test_0_is_not_power(self):
        assert self.solution.isPowerOfFour(0) is False

    def test_negative_is_not_power(self):
        assert self.solution.isPowerOfFour(-4) is False

    def test_64_is_power(self):
        assert self.solution.isPowerOfFour(64) is True

    def test_8_is_not_power(self):
        # 8 = 2^3，不是 4 的次方
        assert self.solution.isPowerOfFour(8) is False

    def test_large_power(self):
        assert self.solution.isPowerOfFour(4**8) is True
