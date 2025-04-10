
## 🆀 鏈結串列找出環的起點【Detect Cycle in a Linked List】

### 📌 題目說明
給定一個單向鏈結串，可能存在一個環。請找出 **環的起點**，如果沒有環就返回 `nullptr`。

---

## ✨ Floyd's Cycle Detection Algorithm 是什麼？

Floyd 或稱 **鼠鼠與兔子模型 (Tortoise and Hare)** ，是一種用於判斷鏈結串是否存在 **環** 的高效率演算法。

- 🐢 **slow pointer** (慢指針)：每次移動1步
- 🐇 **fast pointer** (快指針)：每次移動2步

### 🌀 主要想法

- 若鏈結串 **無環**，則 fast pointer 最終會走到 `nullptr`，並不會與 slow pointer 相遇
- 若有環，則 fast 最終會在環中 **追上 slow pointer**，並與之相遇

就像兩個人在迷你路的圈道跑步，一個跑快點，總有一天會追上前面的人！

### ⏳ 複雜度
| 類型 | 複雜度 |
|--------|------------|
| 時間 | O(n)       |
| 空間 | O(1)       |

不需要額外空間，只需使用兩個指針，非常高效。

### 廣範應用
- 判斷鏈結串是否有環
- 找出 **環的起點**
- 計算 **環的長度**
- 用於數學模型中，判斷數列是否有循環

---

### ✅ 解法: 快慢指針 Floyd's Cycle Detection

我們使用 **快慢指針** 來找出是否有環，若有，則從頭節點與相遇點同時出發，找到環的起點。

---

### 🧠 步驟說明

#### 1️⃣ 快慢指針初始化
```cpp
ListNode* slow = head;
ListNode* fast = head;
```

#### 2️⃣ 移動指針直到相遇（檢查是否有環）
```cpp
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
}
```

#### 3️⃣ 若有環：從 head 和 相遇點 同步走，直到再次相遇，就是起點
```cpp
ListNode* entry = head;
while (entry != slow) {
    entry = entry->next;
    slow = slow->next;
}
return entry;
```

#### 4️⃣ 若沒有環，fast 會先走到 `nullptr`
```cpp
return nullptr;
```

---

### 📈 圖解

```text
例子：
head = 3 -> 2 -> 0 -> -4
              ↑        ↓
              ← ← ← ← ←

快慢指針第一次相遇在某個環中節點 (例：0)

從 head 出發一個指針，從相遇點出發另一個指針，
兩者會在環的起點 2 相遇
```

📌 直覺：相遇時，快指針已經多跑了 `n` 圈，而從 `head` 和相遇點同步走的話，會剛好「在環的入口碰頭」。

---

### 🧪 測試範例

#### 測試 1：
```cpp
head = [3,2,0,-4], pos = 1

返回：指向值為 2 的節點（環起點）
```

#### 測試 2：
```cpp
head = [1,2], pos = 0

返回：指向值為 1 的節點
```

#### 測試 3：
```cpp
head = [1], pos = -1

返回：nullptr（無環）
```

---

### ✅ 完整程式碼

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }

        return nullptr;
    }
};
```
