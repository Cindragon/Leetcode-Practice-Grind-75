import pytest
from helpers import ListNode, list_to_linked_list, linked_list_to_list, create_cycle


@pytest.fixture
def make_linked_list():
    def _make(values):
        return list_to_linked_list(values)
    return _make


@pytest.fixture
def to_list():
    def _to_list(head):
        return linked_list_to_list(head)
    return _to_list


@pytest.fixture
def make_cycled_list():
    def _make(values, pos):
        return create_cycle(values, pos)
    return _make


@pytest.fixture
def assert_linked_list_equal():
    def _assert(head, expected_list):
        assert linked_list_to_list(head) == expected_list
    return _assert
