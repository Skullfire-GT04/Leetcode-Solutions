from typing import Optional


class ListNode:

    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next


class Solution:

    def get_num(self, head : ListNode) -> int:
        temp = 0
        curr_node = head
        i = 1
        while curr_node:
            temp += curr_node.val * i
            i *= 10
            curr_node = curr_node.next
        return temp

    def addTwoNumbers(self, l1 : Optional[ListNode], l2 : Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode()
        num = str(self.get_num(l1) + self.get_num(l2))
        start = temp
        i = 0
        while i < len(num):
            temp.val = int(num[len(num) - (i + 1)])
            i += 1
            if i < len(num):
                new_node = ListNode()
                temp.next = new_node
                temp = new_node
        return start


a = ListNode(3)
b = ListNode(4, a)
c = ListNode(2, b)

d = ListNode(4)
e = ListNode(6, d)
f = ListNode(5, e)

g = Solution().addTwoNumbers(c, f)

while g:
    print(g.val, end = "")
    g = g.next