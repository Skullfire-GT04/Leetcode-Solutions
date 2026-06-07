from typing import List, Optional


class TreeNode:

    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    
    def createBinaryTree(self, description : List[List[int]]) -> Optional[TreeNode]:
        hierarchy = dict()
        child = dict()
        for desc in description:
            child[desc[1]] = 1
            if not hierarchy.get(desc[0], None):
                hierarchy[desc[0]] = [0, 0]
            if desc[2]: hierarchy[desc[0]][0] = desc[1]
            else: hierarchy[desc[0]][1]  = desc[1]

        root_node = 0
        for desc in description:
            if not child.get(desc[0], None):
                root_node = desc[0]
                break
        
        temp = [TreeNode(val = root_node)]
        root = temp[0]
        while len(temp):
            node = temp.pop(0)
            if not hierarchy.get(node.val, None): 
                continue

            if hierarchy[node.val][0]:
                left_node = TreeNode(val = hierarchy[node.val][0])
                node.left = left_node
                temp.append(left_node)
            if hierarchy[node.val][1]:
                right_node = TreeNode(val = hierarchy[node.val][1])
                node.right = right_node
                temp.append(right_node)
        return root



temp = [Solution().createBinaryTree([[1,2,1],[2,3,0],[3,4,1]])]

while len(temp):
    node = temp.pop(0)
    if node.left:
        temp.append(node.left)
    if node.right:
        temp.append(node.right)
    print(node.val)
    
                