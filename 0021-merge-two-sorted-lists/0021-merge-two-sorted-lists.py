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
        currentN1 = nodeOne
        currentN2 = nodeTwo

        while currentN1 and currentN2:
            if currentN1.val <= currentN2.val and currentN1 and currentN2:
                newHead.next = currentN1
                currentN1 = currentN1.next
                newHead = newHead.next
            else:
                newHead.next = currentN2
                currentN2 = currentN2.next
                newHead = newHead.next

        if not currentN1:
            newHead.next = currentN2

        if not currentN2:
            newHead.next = currentN1

        return finalHead.next