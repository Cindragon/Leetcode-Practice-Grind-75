"""
Level 3: Fixture 與資料結構
學習目標：測試「類別設計」題目（非 Solution class），模擬操作序列

注意：0838-design-linked-list.py 定義了自己的 ListNode 和 MyLinkedList class
"""
import pytest
from helpers.solution_loader import load_solution

MyLinkedList = load_solution("0838-design-linked-list", class_name="MyLinkedList")


@pytest.mark.medium
@pytest.mark.linked_list
class TestDesignLinkedList:
    def test_example_operations(self):
        obj = MyLinkedList()
        obj.addAtHead(1)
        obj.addAtTail(3)
        obj.addAtIndex(1, 2)
        assert obj.get(1) == 2
        obj.deleteAtIndex(1)
        assert obj.get(1) == 3

    def test_get_invalid_index(self):
        obj = MyLinkedList()
        assert obj.get(0) == -1
        assert obj.get(-1) == -1

    def test_add_at_head(self):
        obj = MyLinkedList()
        obj.addAtHead(3)
        obj.addAtHead(2)
        obj.addAtHead(1)
        assert obj.get(0) == 1
        assert obj.get(1) == 2
        assert obj.get(2) == 3

    def test_add_at_tail(self):
        obj = MyLinkedList()
        obj.addAtTail(1)
        obj.addAtTail(2)
        obj.addAtTail(3)
        assert obj.get(0) == 1
        assert obj.get(1) == 2
        assert obj.get(2) == 3

    def test_add_at_index_boundary(self):
        obj = MyLinkedList()
        obj.addAtIndex(0, 10)
        assert obj.get(0) == 10
        obj.addAtIndex(1, 20)
        assert obj.get(1) == 20
        obj.addAtIndex(5, 30)  # 超出範圍，不應新增
        assert obj.get(2) == -1

    def test_delete_at_index(self):
        obj = MyLinkedList()
        obj.addAtHead(1)
        obj.addAtTail(2)
        obj.addAtTail(3)
        obj.deleteAtIndex(0)
        assert obj.get(0) == 2
        obj.deleteAtIndex(10)  # 超出範圍，不應刪除
        assert obj.get(0) == 2

    def test_mixed_operations(self):
        obj = MyLinkedList()
        obj.addAtHead(1)
        obj.addAtTail(3)
        obj.addAtIndex(1, 2)
        assert obj.get(0) == 1
        assert obj.get(1) == 2
        assert obj.get(2) == 3
        obj.deleteAtIndex(2)
        assert obj.get(2) == -1
        obj.addAtTail(4)
        assert obj.get(2) == 4
