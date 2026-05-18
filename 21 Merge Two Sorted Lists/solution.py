from typing import Optional

class ListNode:
    def __init__(self, val = 0, next_ = None):
        self.val = val
        self.next = next_



class Solution:
    def mergeTwoLists(self, list1 : Optional[ListNode], list2 : Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2: return None

        out = ListNode()
        l = list1
        r = list2
        curr = out
        while l != None and r != None:
            if l.val < r.val:
                curr.val = l.val
                l = l.next
            else:
                curr.val = r.val
                r = r.next
            curr.next = ListNode()
            curr = curr.next
        
        while l != None:
            curr.val = l.val
            l = l.next
            if l != None:
                curr.next = ListNode()
                curr = curr.next
        while r != None:
            curr.val = r.val
            r = r.next
            if r != None:
                curr.next = ListNode()
                curr = curr.next

        return out
        

a = ListNode(4)
b = ListNode(2, a)
c = ListNode(1, b)

d = ListNode(4)
e = ListNode(3, d)
f = ListNode(1, e)

temp = Solution().mergeTwoLists(c, f)
while temp != None:
    print(temp.val, end = " ")
    temp = temp.next
print()