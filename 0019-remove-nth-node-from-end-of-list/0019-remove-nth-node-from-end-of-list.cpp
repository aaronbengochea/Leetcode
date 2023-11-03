/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int index) {
    
    if(head == nullptr){
        return head;
    }

    if(index == 1 && head->next == nullptr){
        return nullptr;
    }

    int listSize = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        listSize++;
        temp = temp->next;
    }

    temp = head;
    if(listSize > 1 && (index == 1 || index == listSize)){
        if(index == 1) {
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            temp->next = nullptr;
            return head;
        } else{
            return head->next;
        }
    }



    temp = head;
    ListNode* temp2 = head;
    int newCounter = 1;
    int forwardOffset = listSize - index;
    
    while(newCounter < forwardOffset){
        temp = temp->next;
        newCounter++;
    }

    temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = nullptr;

    return head;
    }
};