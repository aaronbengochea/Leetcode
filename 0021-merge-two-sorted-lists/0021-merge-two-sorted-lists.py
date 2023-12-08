# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, nodeOne: Optional[ListNode], nodeTwo: Optional[ListNode]) -> Optional[ListNode]:
        
        
        if not nodeOne:
            return nodeTwo

        if not nodeTwo:
            return nodeOne

        newHead = ListNode()
        finalHead = newHead

        while nodeOne and nodeTwo:
            if nodeOne.val <= nodeTwo.val and nodeOne and nodeTwo:
                newHead.next = nodeOne
                nodeOne = nodeOne.next
                newHead = newHead.next
            else:
                newHead.next = nodeTwo
                nodeTwo = nodeTwo.next
                newHead = newHead.next

        if not nodeOne:
            newHead.next = nodeTwo

        if not nodeTwo:
            newHead.next = nodeOne

        return finalHead.next